#include "StdAfx.h"
#include "Msc_QISR_Tools.h"


Msc_QISR_Tools::Msc_QISR_Tools(void)
{
	//APPID��������Ķ�
	m_configs = "appid=51b1ef85";
	ret = MSP_SUCCESS;

	params = "sub=iat,ssm=1,auf=audio/L16;rate=16000,aue=speex,ent=sms16k,rst=plain";//ֱ��תд��Ĭ�ϱ���Ϊgb2312������ͨ��rse����ָ��Ϊutf8��unicode
}


Msc_QISR_Tools::~Msc_QISR_Tools(void)
{
}

//�����ʼ��
int Msc_QISR_Tools::init(const char* config)
{
	ret = QISRInit( m_configs);
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSInit: failed, Error code %d.\n", ret);
	}
	return ret;
}

//����ر�
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

	///�ڶ�������Ϊ���ݵĲ�����ʹ�ûỰģʽ��ʹ��speex����룬ʹ��16k16bit����Ƶ����
	///����������Ϊ������
	const char* sess_id = QISRSessionBegin(NULL, param, &ret);
	if ( MSP_SUCCESS != ret )
	{
		printf("QISRSessionBegin err %d\n", ret);	
		error = true;
	}

	///ģ��¼����������Ƶ
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

		char param_value[32] = "";//����ֵ���ַ�����ʽ
		unsigned int value_len = 32;	//�ַ������Ȼ�buffer����
		int volume = 0;//������ֵ

		while ( !feof(fp) )
		{
			len = (unsigned int)fread(buff, 1, BUFFER_NUM, fp);
			
			feof(fp) ? status = MSP_AUDIO_SAMPLE_LAST : status = MSP_AUDIO_SAMPLE_CONTINUE;//���һ����ƵҪʹ��last
			///��ʼ�������������Ƶ����
			ret = QISRAudioWrite(sess_id, buff, len, status, &ep_status, &rec_status);
			if ( ret != MSP_SUCCESS )
			{
				printf("\nQISRAudioWrite err %d\n", ret);
				error = true;
				break;
			}
			
			if (ep_status == MSP_EP_AFTER_SPEECH)//��⵽��Ƶ��˵�
			{
				printf("QISRAudioWrite: ep_status == MSP_EP_AFTER_SPEECH.\n");
				break;
			}

			///���������ز��ֽ��
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
			Sleep(200);//��Ϊ��ģ��¼����Ϊ�˱������ݷ���̫����ɻ��������������������ͣ200ms�������ʵʱ¼����������ͣ
		}
		printf("\n");
		fclose(fp); 
	}

	///���һ�����ݷ���֮��ѭ���ӷ������˻�ȡ���
	///���ǵ����绷�����õ�����£����Զ�ѭ���������޶�
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