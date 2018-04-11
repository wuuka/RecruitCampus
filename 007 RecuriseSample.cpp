//递归函数的案例
//https://blog.csdn.net/sinat_38052999/article/details/73303111

#include <iostream>
#include <math.h>
#include <string>

using namespace std;
void swap_(char *a, char *b);

#define Element char
typedef struct Node {
	Element data;
	struct Node *left;
	struct Node *right;
} *Tree;

//*******************类别一：问题的定义是按递归定义的*******************
///*******************************阶乘数********************************
int Factorial_Recur(int n) {  //使用递归
	if (n == 1)   // 递归终止条件 
		return 1;    // 简单情景

	return n * Factorial_Recur(n - 1);  // 相同重复逻辑，缩小问题的规模
}

int Factorial_loop(int n) {  //使用循环
	int result = n;
	while (n > 1) {
		n = n - 1;
		result = result * n;
	}
	return result;
}

///*****************************裴波那契数列*****************************
int Fibonacci_Recur(int n) {  //使用递归
	if (n == 1 || n == 2)
		return 1;
	return Fibonacci_Recur(n - 1) + Fibonacci_Recur(n - 2);
}

/*@param first 数列的第一项
  @param second 数列的第二项
  @param n 目标项*/
int Fibonacci_OptiRecur(int a, int b, int c) {  //使用递归优化
	if(c > 0) {
		if (c == 1) {
			return a;
		}
		else if (c == 2) {
			return b;
		}
		else if (c == 3) {  //f(1, 1, 5) = f(1, 2, 4) = f(2, 3, 3); 
			return a + b;  // 当c=3时，2+3 = 5
		}
		return Fibonacci_OptiRecur(b, a + b, c - 1);
	}
	return -1;
}

int Fibonacci_Loop(int n) {  //使用循环
	if (n > 0) {
		int* arr = new int[n];
		arr[0] = arr[1] = 1;
		for(size_t i = 2; i < n; i++)
			arr[i] = arr[i - 1] + arr[i - 2];
		return arr[n - 1];
	}
	return -1;
}

///*************************杨辉三角************************************
/*@x  指定行
  @y  指定列*/
int PascalTriangle(int x, int y) {  //递归
	if (y <= x && y > 0) {
		if (y == 1 || y == x)
			return 1;
		return PascalTriangle(x - 1, y - 1) + PascalTriangle(x - 1, y);
	}
}

///***********************回文字符串**********************************
bool Palindrome_Recur(string s) {  //递归
	int start = 0;
	int end = s.length() - 1;
	if (end > start) {
		if (s[start] != s[end])
			return false;
		else {
			string s_tmp(s);
			s_tmp.erase(start, 1);
			s_tmp.erase(end - 1, 1);
			return Palindrome_Recur(s_tmp);
		}
	}
	return true;
}

bool Palindrome_Loop(string s) {  //循环
	int start = 0;
	int end = s.length() - 1;
	while(end > start) {
		if (s[start] != s[end])
			return false;
		else {
			start++;
			end--;
		}
	}
	return true;
}

///******************************字符串全排列*****************************
/*
@param s     字符数组
@param from  起始下标
@param to    终止下标*/
void Permutation(char* sourceStr, char* changeStr)
{
	if (*changeStr == '\0')
		cout << sourceStr << endl;
	else {
		//比如源字符串当前是sourceStr="abc",交换字符串也为changeStr="abc",
		//需要注意的是，函数void Permutation(str,str)传的是指向同一个字符串的指针
		for (char* pCh = changeStr; *pCh != '\0'; pCh++) {
			swap_(changeStr, pCh);//交换第一个和后面一个  
			Permutation(sourceStr, changeStr + 1);//固定前面的，后面再排列  
			swap_(changeStr, pCh);//再换回原来的  
		}
	}
	//一次完整的打印是这样的，首先sourceStr、changeStr都指向"abc"，接着swap第一个，结果还是"abc"，
	//这个时候就会输出'abc'。接着会退回的固定'a','b'和'c'进行交换，这个时候//sourceStr="acb"，经过后面全排列后，又会换回来，这样"acb"也就打印出来 
}

void swap_(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

///***********************************二分查找********8********************
/*@param array 目标数组
* @param low 左边界
* @param high 右边界
* @param target 目标值
* @return 目标值所在位置*/
int binarySearch_Recurise(int* array, int low, int high, int target) {  //递归
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (array[mid] == target)
		return (mid + 1);  // 返回目标值的位置，从1开始
	else if (array[mid] > target)
		// 由于array[mid]不是目标值，因此再次递归搜索时，可以将其排除
		binarySearch_Recurise(array, low, mid - 1, target);
	else
		// 由于array[mid]不是目标值，因此再次递归搜索时，可以将其排除
		binarySearch_Recurise(array, mid + 1, high, target);
	//表示没有搜索到
}

int binarySearch_loop(int *array, int high, int target) {  //循环
	int mid, low = 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (array[mid] > target)
			high = mid - 1;
		else if (array[mid] < target)
			low = mid + 1;
		else
			return mid + 1;
	}
	return 0;
}


//*******************类别二：问题解法按递归算法实现*************************
///*******************************汉诺塔问题********************************
/*@param level：盘子的个数
* @param from 盘子的初始地址
* @param inter 转移盘子时用于中转
* @param to 盘子的目的地址*/
void hanoiTower(int level, char from, char inter, char to) {
	if (level == 1) // 递归终止条件
		cout << "从" << from << "移动盘子" << level << "号到" << to << endl;
	else {
		// 递归调用：将level-1个盘子从from移到inter(不是一次性移动，每次只能移动一个盘子,其中to用于周转)
		hanoiTower(level - 1, from, to, inter); // 递归调用，缩小问题的规模
											  // 将第level个盘子从A座移到C座
		cout << "从" << from << "移动盘子" << level << "号到" << to << endl;
		// 递归调用：将level-1个盘子从inter移到to,from 用于周转
		hanoiTower(level - 1, inter, from, to); // 递归调用，缩小问题的规模
	}
}

//*******************类别三：数据的结构是按递归定义的***********************
///*******************************二叉树深度********************************
//二叉树构造器,按先序遍历顺序构造二叉树
//无左子树或右子树用'#'表示
int index = 0;  //全局索引变量
void treeNodeConstructor(Tree &root, Element data[]) {
	Element e = data[index++];
	if (e == '#') {
		root = NULL;
	}
	else {
		root = (Node *)malloc(sizeof(Node));
		root->data = e;
		treeNodeConstructor(root->left, data);  //递归构建左子树
		treeNodeConstructor(root->right, data);  //递归构建右子树
	}
}

int getTreeDepth(Tree t) {
	// 树为空
	if (t == NULL) // 递归终止条件
		return 0;

	int left = getTreeDepth(t->left); // 递归求左子树深度，缩小问题的规模
	int right = getTreeDepth(t->left); // 递归求右子树深度，缩小问题的规模

	return left > right ? left + 1 : right + 1;

}    


//主函数
int main() {
	int Fac_recur = Factorial_Recur(10);  //阶数
	int Fac_loop = Factorial_loop(10);
	
	int Fib_recur = Fibonacci_Recur(7);  //裴波那契数列
	int Fib_optirecur = Fibonacci_OptiRecur(1, 1, 7);
	int Fib_loop = Fibonacci_Loop(7);

	int pascal = PascalTriangle(4, 3);  //杨辉三角
	
	string tt = "sdtds";  //回文字符串
	bool palindrome_recur = Palindrome_Recur(tt);
	bool palindrome_loop = Palindrome_Loop(tt);

	char str[] = "sdgs";  //字符串全排列
	Permutation(str, str);

	int bianry[8] = { 2, 5, 7, 14, 19, 45, 87, 100 };  //二分查找
	int binar_1 = binarySearch_Recurise(bianry, 0, 8, 45);
	int binar_2 = binarySearch_loop(bianry, 8, 45);

	int nDisks = 4;  //汉诺塔
	hanoiTower(nDisks, 'A', 'B', 'C');

	//二叉树 https://www.cnblogs.com/rednodel/p/7737686.html
	Element data[15] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#' };
	Tree tree;
	treeNodeConstructor(tree, data);
	int Hight = getTreeDepth(tree);

	//使用boolalpha输出为bool类型;使用noboolalpha输出为数字类型
	cout << "阶乘值:" << endl << Fac_recur << endl << Fac_loop << endl << endl
		<< "裴波那契：" << endl << Fib_recur << endl << Fib_optirecur << endl << Fib_loop << endl << endl
		<< "杨辉三角：" << endl << pascal << endl << endl
		<< "回文字符串判断：" << endl << boolalpha << palindrome_recur << endl << palindrome_loop << endl << endl
		<< "二分查找;" << endl << binar_1 << endl << binar_2 << endl
		<< "二叉树的深度：" << endl << Hight << endl;
	

	//字符串与字符数组的区别
	string sstri = "sdgjwers";
	char stri_[] = "sdgjwers";
	cout <<"内存所占空间："<<endl<< sizeof(sstri) << endl << sizeof(stri_) << endl
		<< "字符长度："<<endl<<sstri.length() << endl << strlen(stri_) << endl;
	system("pause");

	return 0;
}