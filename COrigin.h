#pragma once
#include "CNode.h"
#include<vector>
using namespace std;

class COrigin
{
public:
	int ID; // ���ı�ţ����㿪ʼ��� (����number)
	CNode* pOriginNode; // ����Ӧ�Ľڵ� �������һ��CNode���ࣩ
	vector<int> DestinationNode; // OD�ԣ�ֻ��¼�������OD (��¼������Ӧ�������յ�)
	vector<double> ODDemand; // OD����ֻ��¼�������OD ����¼OD demand��
	vector<int> ODpairNumber; // OD pair��number
};

