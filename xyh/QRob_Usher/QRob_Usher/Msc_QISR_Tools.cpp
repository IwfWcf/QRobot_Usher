#include "StdAfx.h"
#include "Msc_QISR_Tools.h"


Msc_QISR_Tools::Msc_QISR_Tools(void)
{
	//APPID请勿随意改动
	m_configs = "appid=51b1ef85";
	ret = MSP_SUCCESS;

	params = "sub=iat,ssm=1,auf=audio/L16;rate=16000,aue=speex,ent=sms16k,rst=plain";//直接转写，默认编码为gb2312，可以通过rse参数指定为utf8或unicode
}


Msc_QISR_Tools::~Msc_QISR_Tools(void)
{
}

//引擎初始化
int Msc_QISR_Tools::init(const char* config)
{
	ret = QISRInit( m_configs);
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSInit: failed, Error code %d.\n", ret);
	}
	return ret;
}

//引擎关闭
int Msc_QISR_Tools::fini()
{
	ret = QISRFini();
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSFini: failed , Error code %d.\n",ret);
	}
	return ret;
}

void Msc_QISR_Tools::run_iat(const char* src_wav_filename  ,char *result ,const char* param)
{
	bool error = false;
	int ret = MSP_SUCCESS;
	int i = 0;
	FILE* fp = NULL;;
	memset(result,'\0',0);
	char buff[BUFFER_NUM];
	unsigned int len;
	int status = MSP_AUDIO_SAMPLE_CONTINUE, ep_status = -1, rec_status = -1, rslt_status = -1;

	///第二个参数为传递的参数，使用会话模式，使用speex编解码，使用16k16bit的音频数据
	///第三个参数为返回码
	const char* sess_id = QISRSessionBegin(NULL, param, &ret);
	if ( MSP_SUCCESS != ret )
	{
		printf("QISRSessionBegin err %d\n", ret);	
		error = true;
	}

	///模拟录音，输入音频
	if (error == false)
	{
		fp = fopen( src_wav_filename , "rb");
		if ( NULL == fp )
		{
			printf("failed to open file,please check the file.\n");
			error = true;
		}
	}

	if (error == false)
	{
		printf("writing audio...\n");

		char param_value[32] = "";//参数值的字符串形式
		unsigned int value_len = 32;	//字符串长度或buffer长度
		int volume = 0;//音量数值

		while ( !feof(fp) )
		{
			len = (unsigned int)fread(buff, 1, BUFFER_NUM, fp);
			
			feof(fp) ? status = MSP_AUDIO_SAMPLE_LAST : status = MSP_AUDIO_SAMPLE_CONTINUE;//最后一块音频要使用last
			///开始向服务器发送音频数据
			ret = QISRAudioWrite(sess_id, buff, len, status, &ep_status, &rec_status);
			if ( ret != MSP_SUCCESS )
			{
				printf("\nQISRAudioWrite err %d\n", ret);
				error = true;
				break;
			}
			
			if (ep_status == MSP_EP_AFTER_SPEECH)//检测到音频后端点
			{
				printf("QISRAudioWrite: ep_status == MSP_EP_AFTER_SPEECH.\n");
				break;
			}

			///服务器返回部分结果
			if ( rec_status == MSP_REC_STATUS_SUCCESS )
			{
				const char* result_tmp = QISRGetResult(sess_id, &rslt_status, 0, &ret);
				if( rslt_status == MSP_REC_STATUS_NO_MATCH )
					printf("get result nomatch\n");
				else
				{
					if ( result != NULL )
					{
						int len = strlen(result)+strlen(result_tmp);
						char* temp;
						memset(temp,'\0',len);
						temp = strcpy(temp,result);
						temp = strcat(temp,result_tmp);
						free(result);
						result = temp;
					}
				}
			}
			Sleep(200);//因为是模拟录音，为了避免数据发送太快造成缓冲区溢出，所以这里暂停200ms，如果是实时录音，不必暂停
		}
		printf("\n");
		fclose(fp); 
	}

	///最后一块数据发完之后，循环从服务器端获取结果
	///考虑到网络环境不好的情况下，可以对循环次数作限定
	if (error == false)
	{	
		printf("get reuslt\n");
		int loop_count = 0;
		do 
		{
			const char* result_tmp = QISRGetResult(sess_id, &rslt_status, 0, &ret);
			if ( ret != MSP_SUCCESS )
			{
				printf("QISRGetResult err %d\n", ret);
				error = true;
				break;
			}

			if( rslt_status == MSP_REC_STATUS_NO_MATCH )
				printf("get result nomatch\n");
			else
			{
				if ( result != NULL )
					{
						int len = strlen(result)+strlen(result_tmp);
						char* temp;
						memset(temp,'\0',len);
						temp = strcpy(temp,result);
						temp = strcat(temp,result_tmp);
						free(result);
						result = temp;
					}
			}
			Sleep(500);
		} while (rslt_status != MSP_REC_STATUS_COMPLETE && loop_count++ < 30);
	}

	if( NULL == result )
	{
		free(result);
		memset(result,'\r\n',2);
	}

	ret = QISRSessionEnd(sess_id, NULL);
	if ( ret != MSP_SUCCESS )
	{
		printf("QISRSessionEnd err %d\n", ret);
		return;
	}
	printf("QISRSessionEnd.\n");
	return ;
}