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

//音频头部格式
struct wave_pcm_hdr
{
	char            riff[4];                        // = "RIFF"
	SR_DWORD        size_8;                         // = FileSize - 8
	char            wave[4];                        // = "WAVE"
	char            fmt[4];                         // = "fmt "
	SR_DWORD        dwFmtSize;                      // = 下一个结构体的大小 : 16

	SR_WORD         format_tag;              // = PCM : 1
	SR_WORD         channels;                       // = 通道数 : 1
	SR_DWORD        samples_per_sec;        // = 采样率 : 8000 | 6000 | 11025 | 16000
	SR_DWORD        avg_bytes_per_sec;      // = 每秒字节数 : dwSamplesPerSec * wBitsPerSample / 8
	SR_WORD         block_align;            // = 每采样点字节数 : wBitsPerSample / 8
	SR_WORD         bits_per_sample;         // = 量化比特数: 8 | 16

	char            data[4];                        // = "data";
	SR_DWORD        data_size;                // = 纯数据长度 : FileSize - 44 
};

//默认音频头部数据
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
	int text_to_speech(const char* src_text ,const char* des_path ,const char* params);        //合成文本
	int init(const char* config);           //引擎初始化
	int fini();             //引擎关闭
};

