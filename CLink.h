#pragma once
#include "CNode.h"

class CLink
{
public:
	int ID; // ·�εı�ţ����㿪ʼ��� ��link��number��
	CNode* pInNode; // ·�ε���ڵ� ��link��㣬�����һ��CNode���ࣩ
	CNode* pOutNode; // ·�ε��սڵ� ��link�յ㣩
	double LinkDistance; // Free Flow Travel time
};

