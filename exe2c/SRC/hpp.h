// Copyright(C) 1999-2005 LiuTaoTao��bookaa@rorsoft.com


//	exe2c project

#ifndef	HPP_H
#define HPP_H

#include "CFuncType.h"
//	--------------------------------------------------------
class define_t
{	//#define src dst
public:
	PSTR src;
	PSTR dst;

	define_t();

	~define_t();
};

typedef CList<define_t*, define_t*> DefineList;
	//about this list:
	//	1. allow multi define, that is , it will save both
	//		#define A 1
	//		#define A 2
	//		but if 2 just same define, only once

extern DefineList* g_DefineList;

//	--------------------------------------------------------

class CCInfo
{	//	������һ��һ��ȥ��CPP����ʱ��������Ҫһ���ṹ����¼��ǰ��״̬
public:
	int	comma1;	//	Ϊ1������()�У��ڴ�һ��')'��Ϊ2����(())
	int	comma2;	//	Ϊ1������{}�У��ڴ�һ��'}'��Ϊ2����{{}}
	int extern_c;	//	��������һ��extern "C" {}��
	enum_CallC	m_default_callc;
	
	SIZEOF m_len;	//	��m_buf�ĳ���
	char* m_buf;

	CCInfo();
	~CCInfo();
	
	void LoadFile(FILE *f);
	void OneLine(PCSTR lbuf, PCSTR &pnext);
	void do_typedef(PCSTR &p);
	void do_typedef_(VarTypeID baseid, PCSTR &p);
	CFuncType* do_func_proto(PCSTR pstr);
	CFuncType* do_func_proto_void(PCSTR pstr);
	void do_class(PCSTR pleft, PCSTR &pnext);
};

VarTypeID do_enum(PCSTR &p);

//	--------------------------------------------------------


BOOL hpp_init();
BOOL hpp_onexit();

#endif	//	HPP_H
