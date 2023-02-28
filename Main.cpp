#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
	double depot = 1;
	double node = 1;
	int i = 1;
	while (depot<22)
	{
		for (i; i < (20 * node + 1); i++)
		{
			cout << depot << "            " << i << "            " << 1 << endl;
		}
		i = 20 * node + 1;
		depot++;
		node++;
	}

	return 0;
}