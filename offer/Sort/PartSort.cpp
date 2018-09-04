#include <iostream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <stack>
using namespace std;

//快速排序--递归
int PartSort(int* array, int left, int right)
{
	int key = array[left];
	while (left < right)
	{
		while (left < right && array[right] >= key)
			right--;
		swap(array[left], array[right]);

		while (left < right && array[left] <= key)
			left++;
		swap(array[left], array[right]);
	}
	return left;
}

void QuickSort(int* array, int left, int right)
{
	//assert(array);
	int pivot;
	if (left < right)//表示已经完成一个组
	{
		pivot = PartSort(array, left, right);//枢轴的位置
		QuickSort(array, left, pivot - 1);
		QuickSort(array, pivot + 1, right);
	}
}


/*    //非递归排序
基本思路：利用栈保存左右区间
1、左右区间入栈（先右后左）
2、取栈顶元素，出栈
3、排序
4、入栈，先右后左*/
void QiockSortNor(int arr[], int left, int right)
{
	stack<int> s;
	//右边先入栈，左边后入栈
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		left = s.top();
		s.pop();
		right = s.top();
		s.pop();
		if (left < right)
		{
			int div = PartSort(arr, left, right);
			s.push(right);
			s.push(div + 1);
			s.push(div - 1);
			s.push(left);
		}
	}
}

int main()
{
	int array[] = {4,1,3,6,12,67,5};
	int len = sizeof(array) / sizeof(array[0]);
	//QuickSort(array, 0, len-1);
	QiockSortNor(array, 0, len - 1);

	for (int s = 0; s < len;++s)
		cout << array[s] << " ";
	return 0;
}
