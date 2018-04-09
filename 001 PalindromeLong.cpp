//[��Ѷ�����] �������
//����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
//�����Ҫɾ�����ַ�������

//http://blog.csdn.net/sinat_35512245/article/details/53675660

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1010;
int temp[MAXN][MAXN];

//����s�ķ���reverse��Ȼ�������ǵ���Ĺ��������У�Ҫɾ�����ַ���������֪��,ʱ�临�Ӷ�O(N^2)
int getRemoveNumber(string &s1)
{
	string s2(s1);
	reverse(s2.begin(), s2.end());
	int len = s1.length();
	memset(temp, 0, sizeof temp);
	for (int i = 0; i<len; ++i)
	{
		for (int j = 0; j<len; ++j)
		{
			if (s1[i] == s2[j])
				temp[i + 1][j + 1] = temp[i][j] + 1;
			else temp[i + 1][j + 1] = max(temp[i][j + 1], temp[i + 1][j]);
		}
	}
	return len - temp[len][len];
}

int main()
{
	string s;
	while (cin >> s)
	{
		cout << getRemoveNumber(s) << endl;
	}
	return 0;
}