#pragma once
#include<vector>
using namespace std;

class CNode
{
public:
	int ID; // �ڵ�ı�ţ����㿪ʼ��� ��node number��
	double PositionX; // �ڵ��X����
	double PositionY; // �ڵ��Y����
	int Origin_ID = -1; // �ڵ��Ӧ������ţ�-1��ʾ������� ����ʶ�����ж��ǲ�����㣬Ĭ���Ȳ��ǣ�
	vector<int> IncomingLink; // ����ڵ��link��ż��� ��������directed graph��
	vector<int> OutgoingLink; // �뿪�ڵ��link��ż��� 
	//int Node_type; // �ڵ��Ӧ�ĳ�վ���ͣ�1: parking node, 2: plug-in charging station, 3: non-parking node.
	int NodeType[3]; // ����ڵ��Ӧ�ĳ�վ����
	double Capacity[3]; //node��capacity
	double CapacityPick[3]; //node��pick capacity
	double CapacityDrop[3]; //node��drop capacity
	double CapacityPickAu[3]; //node��pick capacity����
	double CapacityDropAu[3]; //node��drop capacity����
	double CapacityPick_Temp[3]; //node��pick capacity
	double CapacityDrop_Temp[3]; //node��drop capacity
	double Incentive; //������
	double Penalty; //�ͷ���
	double Pickupflow[2];
	double Dropoffflow[3];
	double PickupUseRate[2];
	double DropoffUseRate[3];
	double PickupNoSharedEbike[2]; //1
	double DropofffNoParkingSpace[3]; //2
	double PickupLossRate[2]; 
	double DropoffLossRate[3]; 
	double PickupQueue[2];
	double DropoffQueue[3];
	double PickupEffectiveRate[2];
	double DropoffEffectiveRate[3];
	double Waiting_time_cost_pickup[3] = { 0,0,0 }; //pick-up waiting time cost
	double Waiting_time_cost_dropoff[3] = { 0,0,0 }; //drop-off waiting time cost
	double ValueDerivativePick[2]; //Pick-up node��capacity��
	double ValueDerivativeDrop[3]; //drop node��capacity��
	double ValueDerivativeNonMarginalFunctionPick[2];//Pick-up node��capacity�󵼺�Ե�ǰroute flow���ֵ�ֵ
	double ValueDerivativeNonMarginalFunctionDrop[3];
	double ValueDerivativeMarginalFunctionPick[2];//Pick-up node��capacity�󵼺�Եõ���UE route flow���ֵ�ֵ
	double ValueDerivativeMarginalFunctionDrop[3];
	double GeneralizedPickCapacity[2];
	double GeneralizedDropCapacity[3];
};
