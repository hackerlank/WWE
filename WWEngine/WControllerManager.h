/*
���򵥻��Ŀ�������
//////////////////////////////////////////////////////////////////////////
���������򵥻����ÿ�����������Ĭ��ֻ��һ���ն˵�����¡�
�����ⲿ������������Ϣ�ɸ�������ա�Ȼ��ͳһ�ַ�����Ҫ���Ƶ�ģ�顣
������Ҫ���Ƶ�ģ��ͨ��ע��ķ�ʽ��ӵ��ÿ������ġ�
//////////////////////////////////////////////////////////////////////////
*/

#pragma once
#include "Common.h"
#include "WObject.h"
class WControllerManager {
	vector<WObject*>m_controller;
	priority_queue<ObjFreeHashNode>m_qfree;
public:
	void AddController(WObject* pobj);
};
