#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "qtts.h"

#ifdef _WIN64
#pragma comment(lib,"../lib/msc_x64.lib")//x64
#else
#pragma comment(lib,"../lib/msc.lib")//x86
#endif

typedef int SR_DWORD;
typedef short int SR_WORD ;

//��Ƶͷ����ʽ
struct wave_pcm_hdr
{
	char            riff[4];                        // = "RIFF"
	SR_DWORD        size_8;                         // = FileSize - 8
	char            wave[4];                        // = "WAVE"
	char            fmt[4];                         // = "fmt "
	SR_DWORD        dwFmtSize;                      // = ��һ���ṹ��Ĵ�С : 16

	SR_WORD         format_tag;              // = PCM : 1
	SR_WORD         channels;                       // = ͨ���� : 1
	SR_DWORD        samples_per_sec;        // = ������ : 8000 | 6000 | 11025 | 16000
	SR_DWORD        avg_bytes_per_sec;      // = ÿ���ֽ��� : dwSamplesPerSec * wBitsPerSample / 8
	SR_WORD         block_align;            // = ÿ�������ֽ��� : wBitsPerSample / 8
	SR_WORD         bits_per_sample;         // = ����������: 8 | 16

	char            data[4];                        // = "data";
	SR_DWORD        data_size;                // = �����ݳ��� : FileSize - 44 
};

//Ĭ����Ƶͷ������
wave_pcm_hdr default_pcmwavhdr = 
	{
		{ 'R', 'I', 'F', 'F' },
		0,
		{'W', 'A', 'V', 'E'},
		{'f', 'm', 't', ' '},
		16,
		1,
		1,
		16000,
		32000,
		2,
		16,
		{'d', 'a', 't', 'a'},
		0  
	};

class Msc_QTTS_Tools
{
private: 
	const char* m_configs;
	const char* params;
	int ret;
	char key;
public:
	Msc_QTTS_Tools(void);
	~Msc_QTTS_Tools(void);
	int text_to_speech(const char* src_text ,const char* des_path ,const char* params);        //�ϳ��ı�
	int init(const char* config);           //�����ʼ��
	int fini();             //����ر�
};

