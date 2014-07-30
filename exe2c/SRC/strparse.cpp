// Copyright(C) 1999-2005 LiuTaoTao��bookaa@rorsoft.com


//	exe2c project

#include "stdafx.h"
#include "00000.h"
#include <io.h>
#include "strparse.h"

void skip_space(PCSTR &p)
{
	while (*p == ' ')
		p++;
}
void skip_eos(PCSTR &p)
{
	if (*p == ' ')
		p++;
	if (*p == '\0')
		p++;
}
void get_1part(OUT PSTR buf,PCSTR &p)
{	//��p��ָ����Ϊ�ո�Ĳ��ִ�buf
	//	�ָ���������' ',',','\0','[',']',';','{','}'
	assert(p);
	assert(*p != ' ');
	*buf = 0;
	for(;;)
	{
		char c = *p;
		if (if_split_char(c))
		{
			*buf = '\0';
			if (c == ' ')	//	���Ǹ������������ϣ���ܶ�����
				p++;
			return;
		}
		*buf++ = c;
		p++;
	}	
}

BOOL if_split_char(char c)
{
	switch( c )
	{
	case ' ':
	case '\t':
	case ',':
	case ';':
	case '\0':
	case '(':
	case ')':
	case '*':
	case '[':
	case ']':
	case '{':
	case '}':
	case '+':
	case '\x0a':
	case '\x0d':
		return TRUE;		
	}
	return FALSE;
}
DWORD Str2Num(PCSTR p)
{
	DWORD d = 0;
	if (*p == '0' && (p[1] | 0x20) == 'x')
	{
		sscanf(p+2,"%x",&d);
		return d;
	}
	sscanf(p,"%d",&d);
	return d;
}

signed int Str2Int(PCSTR p)
{
	if (*p == '-')
	{
		return -Str2Int(p+1);
	}
	return (signed int)Str2Num(p);
}


