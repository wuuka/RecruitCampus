//一个数分解出做小奇数和偶数

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	while (cin >> num) {
		vector<int> num_vector;
		int num_v;
		for (int j = 0; j < num; j++) {
			cin >> num_v;
			num_vector.push_back(num_v);
		}

		for (int i = 0; i < num; i++) {
			int ou_num = 0, ji_num = 0;
			if (num_vector[i] % 2 == 0)
				ou_num = 2;
			for (int k = 1; k < num_vector[i]; k++) {
				if (num_vector[i] % (2 * k + 1) == 0)
					ji_num = 2 * k + 1;
			}
			if (ou_num != 0 && ou_num != 0)
				cout << ji_num << " " << ou_num << endl;
			else
				cout << "NO";
		}
	}
	return 0;
}
