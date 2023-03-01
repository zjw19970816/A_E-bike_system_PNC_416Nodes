// FrankWolfe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"CNetwork.h"
#include "time.h"
#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
	clock_t start, end;
	start = clock();
	srand(0);

	//GA method for 416 nodes的network
	//CNetwork* Network = new CNetwork(stod(argv[1]), stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]), stod(argv[8]), stod(argv[9]), stod(argv[10]), stod(argv[11]), stod(argv[12]));
	CNetwork* Network = new CNetwork();
	Network->ReadNode("Node_example_416Nodes.txt");
	Network->ReadDepot("Depot_example_416Nodes.txt");
	Network->ReadLink("Link_example_416Nodes.txt");
	Network->ReadDistance("DepotNode_example_416Nodes.txt");
	Network->ReadODpairs("ODPairs_example_416Nodes.txt");
	//system("pause");
	Network->GAProgram();

	delete Network;	//释放堆区

	end = clock();   //结束时间
	cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;  //输出时间（单位: s）
	for (int i = 1; i < argc; ++i)
	{
		cout << stod(argv[i]) << " ";  // 字符串转换成整数
		//cout<< stod(argv[i]) << " "; // 字符串转换成double
	}
	cout << endl;
	return 0;
}