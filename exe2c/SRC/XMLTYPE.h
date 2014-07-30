// Copyright(C) 1999-2005 LiuTaoTao��bookaa@rorsoft.com

//	XmlType.h

#ifndef	XmlType_H
#define	XmlType_H

enum XMLTYPE
{
	XT_invalid = 0,
	XT_blank,
	XT_Symbol,
	XT_Function,
	XT_Keyword,		//�ؼ��֣�����struct,union,for,while
	XT_Class,		//�Ǹ�class��union��struct������
	XT_K1,			//{} []
	XT_Comment,		//ע��
	XT_DataType,	//��������
	XT_Number,		//һ����
	XT_AsmStack,	//��ջֵ
	XT_AsmOffset,	//�����ʾʱ��seg:offset
	XT_AsmLabel,	//�����ʾʱ��label name
    XT_FuncName,
};

#define	COLOR_DEFAULT	RGB(255,255,255)

COLORREF XmlType_2_Color(XMLTYPE xmltype);

void XML_Clicked(XMLTYPE xmltype, PVOID p);

#endif	//	XmlType_H
