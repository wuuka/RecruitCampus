//[��Ѷ�����] �㷨����-�ַ���λ
//СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣���ܰ��СQ��
//��������:���������ж��飬ÿ�����һ���ַ���s���ұ�֤:1<=s.length<=1000.

//http://blog.csdn.net/xubinlxb/article/details/52432291

//ð������˼��
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		if (s.length() >= 1 && s.length() <= 1000) {
			for (int i = 0; i < s.size() - 1; i++)
				for (int j = 0; j < s.size() - 1 - i; j++)
					if ((s[j] >= 'A'&&s[j] <= 'Z') && (s[j + 1]<'A' || s[j + 1]>'Z')) {
						char c = s[j];
						s[j] = s[j + 1];
						s[j + 1] = c;
					}
			cout << s << endl;
		}
	}
}

 