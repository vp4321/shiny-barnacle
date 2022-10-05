#include <bits/stdc++.h>
using namespace std;

// function for odd even cfg
void fn(int n)
{
	string res_cfg = "";
	int nodeNum = 0;
	nodeNum++;
	res_cfg = to_string(nodeNum) + " -> ";

	// Odd
	if (n % 2 == 1)
	{
		nodeNum=2;
		res_cfg += to_string(nodeNum) + " -> ";
		cout << "Printing cfg for odd number\n";
	}

	// even
	else if (n % 2 == 0)
	{

		nodeNum=3;
		res_cfg += to_string(nodeNum) + " -> ";
		cout << "Printing cfg for even number\n";
	}
	nodeNum=4;
	res_cfg += to_string(nodeNum) + " -> ";
	// printing cfg
	cout << "Resultant CFG : " << res_cfg.substr(0, res_cfg.length() - 3) << "\n";
}
int main()
{
	cout << endl;
	cout << endl;
	int n;
	cout << "Enter a number: ";
	cin >> n;
	fn(n);
	cout << endl;
	cout << endl;
	return 0;
}
