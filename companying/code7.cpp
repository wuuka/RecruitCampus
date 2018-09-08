#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {

	int t;
	vector<int> vec;
	cin >> t;
	for (int s = 0; s < t; s++) {
		int N, M;
		cin >> N >> M;

		int ** a = new int *[N];  //指针方式
		for (int i = 0; i < N; i++)
			a[i] = new int[M];
		for (int w1 = 0; w1<N; w1++)
			for(int w2 = 0; w2<M; w2++)
			a[w1][w2] = 0;

		for (int m = 0; m < N; m++) {
			for (int n = 0; n < M; n++) {
				a[m][n]++;
				if (m - 1 >= 0) {
					a[m - 1][n]++;
					if(n - 1 >= 0)
						a[m - 1][n - 1]++;
					if(n+1<M)
						a[m - 1][n + 1]++;
				}
				if (m + 1 < N) {
					a[m + 1][n]++;
					if (n - 1 >= 0)
						a[m + 1][n - 1]++;
					if (n + 1 < M)
						a[m + 1][n + 1]++;
				}

				if(n - 1 >= 0)
					a[m][n - 1]++;
				if(n + 1 < M)
					a[m][n + 1]++;
			}
		}
		
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] % 2 != 0)
					ans++;
			}
		}

		vec.push_back(ans);
	}
	for(int i = 0; i< t; i++)
		cout << vec[i] << endl;
	return 0;
}
