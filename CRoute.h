#pragma once
#include "CNode.h"
#include<vector>
using namespace std;

class CRoute
{
public:
	int ODID; // OD numerber, Ŀ�����Ҹ�OD pair�µ�route
	int RouteID; // route number
	CNode* PickupNode; // ��ODpair�ĸ���route��pick-up node
	CNode* DropoffNode; // ��ODpair�ĸ���route��drop-off node
	int PickupType; //ȡ܇�c�����
	int DropoffType; //ͣ܇�c�����
	//Route cost
	//double FreeFlowTravelTime; // Free Flow Travel time
	double FreeFlowTravelSpeed = 15; // Free Flow Travel speed
	double Capacity = 2000; // Route capacity
	double Pickupdistance;
	double Ridingdistance;
	double RentalCost;
	double EnergyConsumption;
	double Dropoffdistance;
	double PickupWalkingCost;
	double DropWalkingCost;
	double RidingTimeCost = 0; // link travel time
	double PickupWaitingCost;
	double DropWaitingCost;
	double RouteCost;

	double DropExtraCost;
	double ValueNonMarginalFunction; //V(x,f)
	double ValueMarginalFunction; //V(x,f(x)*)
	double ValueNonDerivativeMarginalFunctionPick;
	double ValueNonDerivativeMarginalFunctionDrop;
	//double ValueDerivativeMarginalFunctionPick;
	//double ValueDerivativeMarginalFunctionDrop;
	double DerivationRouteflow; //C_n_m_r��f_n_m_r��
	double GeneralizedRouteCost; //���µ�route cost��all or nothing
};

