//指针和引用
//https://blog.csdn.net/qq_27678917/article/details/70224813

#include"stdafx.h"
#include<iostream>
#include<stdlib.h>
using namespace std;


void swap_int(int *a, int *b)
{
	int c = 10;
	int *temp = &c;
	*temp = *a;
	*a = *b;
	*b = *temp;
}

void test(int *p)
{
	int a = 1;
	p = &a;
	cout << p << " " << *p << endl << endl;;
}

void test_(int &a)
{
	cout << &a << " " << a << endl << endl;
}

void test_pro(int *&p)
{
	int a = 1;
	p = &a;
	cout << p << " " << *p << endl << endl;
}

int main(void)
{
	int a = 1, b = 2;
	int *p = NULL;
	swap_int(&a, &b);
	cout << a << " " << b << endl << endl;
	//test(p);

	cout << &a << " " << a << endl << endl;
	test_(a);

	test_pro(p);
	if (p != NULL)
		cout << "指针p不为NULL" << endl << endl;
	cout << p << " " << *p << endl << endl;

	//指针大小sizeof与引用大小的问题
	char* ss = "0123456789";
	cout << sizeof(ss) << endl << sizeof(*ss) << endl;
	char ss_1[] = "01233456789";
	cout << sizeof(ss_1) << endl << sizeof(*ss_1) << endl;

	char ss_3[100] = "01233456789";
	cout << sizeof(ss_3) << endl << strlen(ss_3) << endl;
	int ss_4[100] = { 0,1,2,3,4,5,6,7,8,9};
	cout << sizeof(ss_4) << endl;  // << endl << strlen(ss_4)错误的操作

	system("pause");
}
