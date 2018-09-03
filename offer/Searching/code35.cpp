#include <iostream>
#include <string>

using namespace std;

class Solution35 {
	//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）
public:
	char FirstNotRepeatingChar(string str) {  //输入字符串
		if (str.size() == 0)
			return '\0';
		char ch[256] = { 0 };
		for (int i = 0; i<str.size(); i++)
			ch[str[i]]++;
		for (int i = 0; i<str.size(); i++)
			if (ch[str[i]] == 1)
				return str[i];
		return '\0';
	}

	char firstNotRepeatingChar(char* str) {  //输入指针
		if (str == NULL)
			return '\0';

		const int tableSize = 256;
		unsigned int hashTable[tableSize];
		for (int i = 0; i < tableSize; i++) //初始化哈西表
			hashTable[i] = 0;

		char* hashkey = str;
		while (*(hashkey) != '\0') {  //统计字符数
			hashTable[*(hashkey++)]++;
		}

		hashkey = str;
		while (*hashkey != '\0'){
			if (hashTable[*hashkey] == 1)  //key查找出现1次的字符
				return *hashkey;
			hashkey++;
		}

		return '\0';
	}
};

int main() {
	string str = "abaccdeff";
	char* stt = (char*)str.data();
	Solution35 test;
	char num_string = test.FirstNotRepeatingChar(str);
	char num_char = test.firstNotRepeatingChar(stt);
	cout << num_string << " " << num_char << endl;

	return 0;
}
