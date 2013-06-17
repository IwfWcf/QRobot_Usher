#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "qisr.h"

#ifdef _WIN64
#pragma comment(lib,"../lib/msc_x64.lib")//x64
#else
#pragma comment(lib,"../lib/msc.lib")//x86
#endif


const int BUFFER_NUM = 1024 * 4;
const int AMR_HEAD_SIZE = 6;


class Msc_QISR_Tools
{
private:
	int ret;
	const char* params;
	const char* m_configs;
public:
	Msc_QISR_Tools(void);
	~Msc_QISR_Tools(void);
	char* run_iat(const char* src_wav_filename,char* result, const char* param);
	int init(const char* config);           //引擎初始化
	int fini();             //引擎关闭
};

