#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int di[100005], pi[100005],ai[100005];

int main()
{
	int N, M, maxn = 0;
	while (cin >> N >> M) {

		map<int, int> Job;  //使用关联容器
		for (int i = 0; i < N; i++) {
			cin >> di[i] >> pi[i];
			Job[di[i]] = pi[i];
		}
		for (int j = 0; j < M; j++)
			cin >> ai[j];

		//维护di[i]下能得到的最大报酬
		for (map<int, int>::iterator it = Job.begin(); it != Job.end(); it++) {
			if (Job[it->first] >= maxn)
				maxn = Job[it->first];
			else
				Job[it->first] = maxn;
		}

		//找到ai[i]的下一个键后，迭代器减1输出相应的val
		for (int k = 0; k < M; k++) {
			map<int, int>::iterator it_ = Job.upper_bound(ai[k]);
			--it_;
			cout << Job[it_->first] << endl;
		}
	}
	return 0;
}