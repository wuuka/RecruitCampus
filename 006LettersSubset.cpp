//��Ѷ��� ��A-Z�Ӽ�������
//�������ɴ�����ĸ��A-Z����ɵģ�Ҫ��������ϵ������Ӽ���ÿ���Ӽ�һ�У�����ʹ�õݹ顣

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