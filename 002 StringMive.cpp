//[腾讯编程题] 算法基础-字符移位

//小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。你能帮帮小Q吗？
//输入描述:输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.

//http://blog.csdn.net/xubinlxb/article/details/52432291

//冒泡排序思想
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

 
