#pragma once
#include"CNode.h"
#include"CLink.h"
#include"COrigin.h"
#include"CRoute.h"
#include"CSolution.h"
#include<vector>
#include<string>
#include <fstream>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f //Infinite number

class CNetwork
{
public:

	////Upper-level model
	// Enumeration
	string str = "";
	//����possible��type
	int node_type[4][3] = { {1, -1, -1}, {-1, 2, -1}, {-1, -1, 3}, {1, 2, -1 } }; //һ��node�����ܵ�״̬���������
	double node_capacity[3] = { 10,10,10 };

	vector<CSolution*> m_Solution; //Solution set
	vector<CSolution*> m_Solution2; //Solution set
	CSolution* BestSolution;
	vector<CNode*> m_Node; //����ڵ㼯��
	vector<CNode*> m_Depot; //����ڵ㼯��
	vector<CLink*> m_Link; //����·�μ���
	vector<CLink*> m_DepotNode; 
	vector<COrigin*> m_Origin; //�������㼯��
	vector<CRoute*> m_Route; //�����route����
	int m_nSolution;
	int m_nNode; //�ڵ���
	int m_nDepot; //�ڵ���
	int m_nLink; //·������
	int m_nDepotNode;
	int m_nOrigin; //�������
	int m_nODpair; //Number of OD pair
	int m_nRoute; //route����
	double** NodeDistance; //�κ������distance
	double* RouteFlow; //·������ָ��
	double* RouteFlow_K1; //·������ָ��k-1��
	double* ANRouteFlow; // ����Route flow
	double* ANRouteFlow_K1; // ����Route flow k-1��
	double beita;// SRAM���µ�step size
	double Tao = 1.8; //8
	double gama = 0.05; //1.5
	vector<double> LinkTravelTime; //·������ʱ��
	//double MaxUEGap = 1.0e-4; //UE�������� 
	double MaxUEGap = 1; //UE�������� 
	double UEGap; //UE���
	double* ShortestPathCost;//��ʱ���������нڵ㵽�������· free
	int* ShortestPathParent;//���·�ϣ����нڵ㵽���������·�ϵ�ǰ��·��  free
	int temp_do;
	int n_swap;
	#define NP 10 // The number of food sources equals the half of the colony size
	#define FoodNumber NP/2 // The number of food sources equals the half of the colony size
	#define maxCycle 500 //The number of cycles for foraging {a stopping criteria}*/
	#define crossover_rate 0.8 //Crossover rate 0.1
	#define mutation_rate 0.2 //Mutation rate 0.2
	#define time_interval 0.25 //parking node service time
	#define average_charging_time 2.0 //charging plie average charging time
	#define ValueOfWalkingTime 2.0
	#define WalkingSpeed 4.0
	#define ValueOfRidingTime 1
	#define ValueOfWaitingTime 1
	#define CapUpper 15
	#define CapLower 5
	#define ArtificialRoute 10000 //����·��cost
	const double arfa3 = 21;//Battery consumption coefficient
	const double E_max = 672;//Maximum battery capacity1zhem
	const double days = 10; //һ������10Сʱ

	//�ɵ�����

	double EnvironmantalPenalty = 100;//Environment penalty effect 100
	double ConstructionCost[2] = { 5, 10 }; //P��C��construction cost, N��Ϊ0   5 10 maintenance cost
	double UnitCapCostPC[2] = {5, 10}; //Capacity cost, 5,10
	double xita1 = 1; //Unsatisfied and loss demand cost 1
	double xita5 = 10; //battery swap�ļ۸���10
	double xita6_1 = 1; //relocation for P and C 1
	double xita6_2 = 2; //relocation for N 2
	double incentive = 5; //ͣ��C�Ľ��� 5
	double penalty = 10; //ͣ��N�ĳͷ� 10
	double b_be_2 = 8;//unit rental fare 8
	//CNetwork(double EnPe, double PaM, double CaM, double PaC, double CaC, double xit1, double xit5, double xit6_1, double xit6_2, double incen, double penal, double b_be2)
	//{
	//	EnvironmantalPenalty = EnPe;
	//	ConstructionCost[0] = PaM;
	//	ConstructionCost[1] = CaM;
	//	UnitCapCostPC[0] = PaC;
	//	UnitCapCostPC[1] = CaC;
	//	xita1 = xit1;
	//	xita5 = xit5;
	//	xita6_1 = xit6_1; 
	//	xita6_2 = xit6_2;
	//	incentive = incen; 
	//	penalty = penal; 
	//	b_be_2 = b_be2;
	//}

public:
	void ReadNode(string DataPath);   // ��������ȡ�ڵ��ļ�
	void ReadDepot(string DataPath);  // ��������ȡdepot�ļ�
	void ReadLink(string DataPath);   // ��������ȡ·���ļ�
	void ReadDistance(string DataPath);   // ��������ȡDepot��node�ľ����ļ�
	void ReadODpairs(string DataPath); // ��������ȡOD���ļ�
	void GeneratePossible(int n);
	void EnumerationNodeType(); //Upper-levelö��node��type
	void NodeType(int sol, vector<CSolution*> m_Solution); //�����ϲ�����ÿ��node type��ֵ
	double Dijstra(int Start, int End); //Dijstra�㷨
	void CalNodeDistance(); //�����κ�����֮��ľ���
	void UpdateRouteCost(double* RouteFlow); //����RouteFlow���������е�RouteCost��ͬʱҲ���¶�Ӧ��PickupNode��DropoffNode��flow
	void GenerateRoute(); //Ϊÿһ��ODpair����route
	void AllorNothingAssignment(double* RouteFlow, double* ANRouteFlow);   // ȫ��ȫ�޽�ͨ���䣺����Ϊ��ʼ·��������������ӦCLink�е�ID��
	double GetUEGap(double* RouteFlow);  // ��϶����
	void battery_swap();
	double cal_obj(int sol, vector<CSolution*> m_Solution);
	void RecordBest(int sol, vector<CSolution*> m_Solution);
	void PrintUERouteFlow(double UEGap, double* RouteFlow);
	void PrintUENodeFlow();
	void PrintUERouteCost();
	void PrintNodeInf();
	void PrintBestSolution();
	void EnumerationProgram();
	void InitialNodeType();
	void RepairSolution(vector<CSolution*> m_Solution);
	void WheelSelect();
	void Crossover();
	void Mutation();
	void Selection();
	void GAProgram(); 


//private:
//	//void strcpy(char* strs, string name);
//	inline bool exists(const std::string name)
//	{
//		ifstream f(name.c_str());
//		return f.good();
//	}
//
//	vector<string> split(const string& str, const string& delim)
//	{
//		vector<string> res;
//		if ("" == str) return res;
//		//�Ƚ�Ҫ�и���ַ�����string����ת��Ϊchar*����  
//		char* strs = new char[str.length() + 1]; //��Ҫ����  
//		strcpy(strs, str.c_str());
//
//		char* d = new char[delim.length() + 1];
//		strcpy(d, delim.c_str());
//
//		char* p = strtok(strs, d);
//		while (p)
//		{
//			string s = p; //�ָ�õ����ַ���ת��Ϊstring����  
//			res.push_back(s); //����������  
//			p = strtok(NULL, d);
//		}
//
//		return res;
//	}
};

