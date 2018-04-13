//字符串循环左移

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Bstring(string a, string b) {
	int len = a.length();
	int ss = 0;
	char tmp;
	for(int i = 0; i<len; i++) {
		int s = a.compare(b);
		if (a.compare(b) == 0)
			return ss;
		else{
			tmp = b[0];
			for (int j = 0; j<len - 1; j++) {
				b[j] = b[j + 1];
			}
			b[len - 1] = tmp;
			ss++;
		}
	}
	return -1;
}

int main() {
	int N;
	while (cin >> N) {

		vector<string> string_vector;
		string s;
		for (int i = 0; i<N; i++) {
			cin >> s;
			string_vector.push_back(s);
		}

		int len = string_vector[1].length();
		int tem = 0;
		int	sum = 0;
		for (int j = 0; j<N - 1; j++) {
			tem = Bstring(string_vector[j], string_vector[j + 1]);
			if (tem > (len/2))
				tem = len - tem;
			sum = sum + tem;
		}
		cout << sum;
	}
	return 0;
}
