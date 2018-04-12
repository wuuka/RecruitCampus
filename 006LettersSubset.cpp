//腾讯编程 【A-Z子集遍历】
//集合是由大字字母（A-Z）组成的，要求输出集合的所有子集，每个子集一行，不能使用递归。

//http://blog.csdn.net/sinat_30071459/article/details/72867136

#include <iostream>
#include <math.h>
#include <string>
#define N 26
using namespace std;

int main()
{

	for (size_t i = 1; i < (pow(2.0, N) - 1); ++i)
	{
		int mask = i;
		for (size_t j = 0; j < N; ++j)
		{
			if (i & mask)
				printf("%c ", 'A'+j);
			mask = mask << 1;
		}
		printf("\n");
	}
}