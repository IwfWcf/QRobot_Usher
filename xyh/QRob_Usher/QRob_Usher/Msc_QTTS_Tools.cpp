#include "StdAfx.h"
#include "Msc_QTTS_Tools.h"


Msc_QTTS_Tools::Msc_QTTS_Tools(void)
{
	
	//APPID��������Ķ�
	m_configs = "appid=51b1ef85";

	params = "ssm=1,auf=audio/L16;rate=16000,vcn=xiaoyan";
	int ret = 0;
	char key = 0;
	init(m_configs);
}


Msc_QTTS_Tools::~Msc_QTTS_Tools(void)
{
	fini();
}

//�����ʼ��
int Msc_QTTS_Tools::init(const char* config)
{
	ret = QTTSInit( m_configs);
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSInit: failed, Error code %d.\n", ret);
	}
	return ret;
}

//����ر�
int Msc_QTTS_Tools::fini()
{
	ret = QTTSFini();
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSFini: failed , Error code %d.\n",ret);
	}
	return ret;
}

//�����ϳ�
int Msc_QTTS_Tools::text_to_speech(const char* src_text ,const char* des_path ,const char* params)
{
	struct wave_pcm_hdr pcmwavhdr = default_pcmwavhdr;
	const char* sess_id = NULL;
	int ret = 0;
	unsigned int text_len = 0;
	char* audio_data;
	unsigned int audio_len = 0;
	int synth_status = MSP_TTS_FLAG_STILL_HAVE_DATA;
	FILE* fp = NULL;

	int pos = 0;			//���ڱ����һ���Ѿ��ϳɵ���λ��
	int loop_count = 0;		//���ڱ�ǣ�ȡ�˼��ν��
	int upload_flow = 0,download_flow = 0;//�ϴ���������������
	char param_value[32] = "";//����ֵ���ַ�����ʽ
	unsigned int value_len = 32;	//�ַ������Ȼ�buffer����

	printf("begin to synth...\n");
	if (NULL == src_text || NULL == des_path)
	{
		printf("params is null!\n");
		return -1;
	}
	text_len = (unsigned int)strlen(src_text);
	fp = fopen(des_path,"wb");
	if (NULL == fp)
	{
		printf("open file %s error\n",des_path);
		return -1;
	}
	sess_id = QTTSSessionBegin(params, &ret);
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSSessionBegin: qtts begin session failed Error code %d.\n",ret);
		return ret;
	}

	ret = QTTSTextPut(sess_id, src_text, text_len, NULL );
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSTextPut: qtts put text failed Error code %d.\n",ret);
		QTTSSessionEnd(sess_id, "TextPutError");
		return ret;
	}

	fwrite(&pcmwavhdr, 1, sizeof(pcmwavhdr), fp);

	while ( true )
	{
		audio_data = (char*)QTTSAudioGet( sess_id ,&audio_len , &synth_status , &ret );
	
		fwrite(audio_data, 1, audio_len, fp);
		pcmwavhdr.data_size += audio_len;//����pcm���ݵĴ�С
		if ( MSP_TTS_FLAG_DATA_END == synth_status )
		{
			printf("QTTSAudioGet: get end of data.\n");
			break;
		}
	}
	//����pcm�ļ�ͷ���ݵĴ�С
	pcmwavhdr.size_8 += pcmwavhdr.data_size + 36;

	//��������������д���ļ�ͷ��
	fseek(fp, 4, 0);
	fwrite(&pcmwavhdr.size_8,sizeof(pcmwavhdr.size_8), 1, fp);
	fseek(fp, 40, 0);
	fwrite(&pcmwavhdr.data_size,sizeof(pcmwavhdr.data_size), 1, fp);

	fclose(fp);

	ret = QTTSSessionEnd(sess_id, "Normal");
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSSessionEnd: qtts end failed Error code %d.\n",ret);
	}
	return ret;
}