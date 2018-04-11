//�ݹ麯���İ���
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

//*******************���һ������Ķ����ǰ��ݹ鶨���*******************
///*******************************�׳���********************************
int Factorial_Recur(int n) {  //ʹ�õݹ�
	if (n == 1)   // �ݹ���ֹ���� 
		return 1;    // ���龰

	return n * Factorial_Recur(n - 1);  // ��ͬ�ظ��߼�����С����Ĺ�ģ
}

int Factorial_loop(int n) {  //ʹ��ѭ��
	int result = n;
	while (n > 1) {
		n = n - 1;
		result = result * n;
	}
	return result;
}

///*****************************�Შ��������*****************************
int Fibonacci_Recur(int n) {  //ʹ�õݹ�
	if (n == 1 || n == 2)
		return 1;
	return Fibonacci_Recur(n - 1) + Fibonacci_Recur(n - 2);
}

/*@param first ���еĵ�һ��
  @param second ���еĵڶ���
  @param n Ŀ����*/
int Fibonacci_OptiRecur(int a, int b, int c) {  //ʹ�õݹ��Ż�
	if(c > 0) {
		if (c == 1) {
			return a;
		}
		else if (c == 2) {
			return b;
		}
		else if (c == 3) {  //f(1, 1, 5) = f(1, 2, 4) = f(2, 3, 3); 
			return a + b;  // ��c=3ʱ��2+3 = 5
		}
		return Fibonacci_OptiRecur(b, a + b, c - 1);
	}
	return -1;
}

int Fibonacci_Loop(int n) {  //ʹ��ѭ��
	if (n > 0) {
		int* arr = new int[n];
		arr[0] = arr[1] = 1;
		for(size_t i = 2; i < n; i++)
			arr[i] = arr[i - 1] + arr[i - 2];
		return arr[n - 1];
	}
	return -1;
}

///*************************�������************************************
/*@x  ָ����
  @y  ָ����*/
int PascalTriangle(int x, int y) {  //�ݹ�
	if (y <= x && y > 0) {
		if (y == 1 || y == x)
			return 1;
		return PascalTriangle(x - 1, y - 1) + PascalTriangle(x - 1, y);
	}
}

///***********************�����ַ���**********************************
bool Palindrome_Recur(string s) {  //�ݹ�
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

bool Palindrome_Loop(string s) {  //ѭ��
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

///******************************�ַ���ȫ����*****************************
/*
@param s     �ַ�����
@param from  ��ʼ�±�
@param to    ��ֹ�±�*/
void Permutation(char* sourceStr, char* changeStr)
{
	if (*changeStr == '\0')
		cout << sourceStr << endl;
	else {
		//����Դ�ַ�����ǰ��sourceStr="abc",�����ַ���ҲΪchangeStr="abc",
		//��Ҫע����ǣ�����void Permutation(str,str)������ָ��ͬһ���ַ�����ָ��
		for (char* pCh = changeStr; *pCh != '\0'; pCh++) {
			swap_(changeStr, pCh);//������һ���ͺ���һ��  
			Permutation(sourceStr, changeStr + 1);//�̶�ǰ��ģ�����������  
			swap_(changeStr, pCh);//�ٻ���ԭ����  
		}
	}
	//һ�������Ĵ�ӡ�������ģ�����sourceStr��changeStr��ָ��"abc"������swap��һ�����������"abc"��
	//���ʱ��ͻ����'abc'�����Ż��˻صĹ̶�'a','b'��'c'���н��������ʱ��//sourceStr="acb"����������ȫ���к��ֻỻ����������"acb"Ҳ�ʹ�ӡ���� 
}

void swap_(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

///***********************************���ֲ���********8********************
/*@param array Ŀ������
* @param low ��߽�
* @param high �ұ߽�
* @param target Ŀ��ֵ
* @return Ŀ��ֵ����λ��*/
int binarySearch_Recurise(int* array, int low, int high, int target) {  //�ݹ�
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (array[mid] == target)
		return (mid + 1);  // ����Ŀ��ֵ��λ�ã���1��ʼ
	else if (array[mid] > target)
		// ����array[mid]����Ŀ��ֵ������ٴεݹ�����ʱ�����Խ����ų�
		binarySearch_Recurise(array, low, mid - 1, target);
	else
		// ����array[mid]����Ŀ��ֵ������ٴεݹ�����ʱ�����Խ����ų�
		binarySearch_Recurise(array, mid + 1, high, target);
	//��ʾû��������
}

int binarySearch_loop(int *array, int high, int target) {  //ѭ��
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


//*******************����������ⷨ���ݹ��㷨ʵ��*************************
///*******************************��ŵ������********************************
/*@param level�����ӵĸ���
* @param from ���ӵĳ�ʼ��ַ
* @param inter ת������ʱ������ת
* @param to ���ӵ�Ŀ�ĵ�ַ*/
void hanoiTower(int level, char from, char inter, char to) {
	if (level == 1) // �ݹ���ֹ����
		cout << "��" << from << "�ƶ�����" << level << "�ŵ�" << to << endl;
	else {
		// �ݹ���ã���level-1�����Ӵ�from�Ƶ�inter(����һ�����ƶ���ÿ��ֻ���ƶ�һ������,����to������ת)
		hanoiTower(level - 1, from, to, inter); // �ݹ���ã���С����Ĺ�ģ
											  // ����level�����Ӵ�A���Ƶ�C��
		cout << "��" << from << "�ƶ�����" << level << "�ŵ�" << to << endl;
		// �ݹ���ã���level-1�����Ӵ�inter�Ƶ�to,from ������ת
		hanoiTower(level - 1, inter, from, to); // �ݹ���ã���С����Ĺ�ģ
	}
}

//*******************����������ݵĽṹ�ǰ��ݹ鶨���***********************
///*******************************���������********************************
//������������,���������˳���������
//������������������'#'��ʾ
int index = 0;  //ȫ����������
void treeNodeConstructor(Tree &root, Element data[]) {
	Element e = data[index++];
	if (e == '#') {
		root = NULL;
	}
	else {
		root = (Node *)malloc(sizeof(Node));
		root->data = e;
		treeNodeConstructor(root->left, data);  //�ݹ鹹��������
		treeNodeConstructor(root->right, data);  //�ݹ鹹��������
	}
}

int getTreeDepth(Tree t) {
	// ��Ϊ��
	if (t == NULL) // �ݹ���ֹ����
		return 0;

	int left = getTreeDepth(t->left); // �ݹ�����������ȣ���С����Ĺ�ģ
	int right = getTreeDepth(t->left); // �ݹ�����������ȣ���С����Ĺ�ģ

	return left > right ? left + 1 : right + 1;

}    


//������
int main() {
	int Fac_recur = Factorial_Recur(10);  //����
	int Fac_loop = Factorial_loop(10);
	
	int Fib_recur = Fibonacci_Recur(7);  //�Შ��������
	int Fib_optirecur = Fibonacci_OptiRecur(1, 1, 7);
	int Fib_loop = Fibonacci_Loop(7);

	int pascal = PascalTriangle(4, 3);  //�������
	
	string tt = "sdtds";  //�����ַ���
	bool palindrome_recur = Palindrome_Recur(tt);
	bool palindrome_loop = Palindrome_Loop(tt);

	char str[] = "sdgs";  //�ַ���ȫ����
	Permutation(str, str);

	int bianry[8] = { 2, 5, 7, 14, 19, 45, 87, 100 };  //���ֲ���
	int binar_1 = binarySearch_Recurise(bianry, 0, 8, 45);
	int binar_2 = binarySearch_loop(bianry, 8, 45);

	int nDisks = 4;  //��ŵ��
	hanoiTower(nDisks, 'A', 'B', 'C');

	//������ https://www.cnblogs.com/rednodel/p/7737686.html
	Element data[15] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#' };
	Tree tree;
	treeNodeConstructor(tree, data);
	int Hight = getTreeDepth(tree);

	//ʹ��boolalpha���Ϊbool����;ʹ��noboolalpha���Ϊ��������
	cout << "�׳�ֵ:" << endl << Fac_recur << endl << Fac_loop << endl << endl
		<< "�Შ������" << endl << Fib_recur << endl << Fib_optirecur << endl << Fib_loop << endl << endl
		<< "������ǣ�" << endl << pascal << endl << endl
		<< "�����ַ����жϣ�" << endl << boolalpha << palindrome_recur << endl << palindrome_loop << endl << endl
		<< "���ֲ���;" << endl << binar_1 << endl << binar_2 << endl
		<< "����������ȣ�" << endl << Hight << endl;
	

	//�ַ������ַ����������
	string sstri = "sdgjwers";
	char stri_[] = "sdgjwers";
	cout <<"�ڴ���ռ�ռ䣺"<<endl<< sizeof(sstri) << endl << sizeof(stri_) << endl
		<< "�ַ����ȣ�"<<endl<<sstri.length() << endl << strlen(stri_) << endl;
	system("pause");

	return 0;
}