//百度 买帽子
//度度熊想去商场买一顶帽子，商场里有N顶帽子，有些帽子的价格可能相同。度度熊想买一顶价格第三便宜的帽子，问第三便宜的帽子价格是多少？ 
//输入描述:首先输入一个正整数N（N<=50），接下来输入N个数表示每顶帽子的价格（价格均是正整数，且小于等于1000）
//输出描述:如果存在第三便宜的帽子，请输出这个价格是多少，否则输出-1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int N;
	vector<int> price;
	
	while (cin >> N) {
		int s = 0;
		for (int i = 0; i<N; i++) {
			cin >> s;
			price.push_back(s);
		}
		sort(price.begin(), price.end());
		int end = price[0];
		int num = 1;
		int third;
		for (int j = 0; j < N; j++) {
			if (price[j] == end)
				continue;
			else {
				num++;
				end = price[j];
			}
			if (num == 3) {
				third = price[j];
				break;
			}
		}
        if(num == 3)
            cout << third;
        else
            cout << -1;
	}
	return 0;
}