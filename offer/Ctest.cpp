#include "stdafx.h"
//��ָoffer���Ա�̰���

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//01��ά����Ĳ���
class Solution01 {
public:
	bool Find(int target, vector<vector<int> > array) {  //������vector���������飨��̬���鶨�壩

														 //vector������������г��Ȳ��ң�
		int row = array.size();
		int col = array[0].size();

		//�ж����麬�б���
		if (row > 0 && col > 0) {

			int i = 0, j = col - 1;
			while (i < row && j >= 0) {  //����һ��ѡ���������Ͻǵĵ������ж�
				if (array[i][j] == target)
					return true;
				else if (array[i][j] > target)
					j--;
				else
					i++;
			}

			/*
			int i_ = row - 1, j_ = 0;
			while (i_ >= 0 && j_ < col) {  //��������ѡ���������½ǵĵ������ж�
			if (array[i_][j_] == target)
			return true;
			else if (array[i_][j_] > target)
			i_--;
			else
			j_++;
			}*/
		}
		return false;
	}

	void test() {
		vector <vector<int>> array{ { 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 },
		{ 16, 17, 18, 19, 20 } };
		vector<int> target{ 1, 2, 3, 10, 0, -1, 32, 34, 20, 16, 15, 6 };

		for (int i = 0; i != target.size(); i++) {
			cout << "target " << target[i] << boolalpha <<  //bool����������ʾ
				"    std:" << (1 <= target[i] && target[i] <= 20) <<  //�ж��ڣ�1�� 20����Χ֮��
				"  res:" << Find(target[i], array) << endl;
		}
	}

};

//02�ַ����ո���滻
class Solution02 {
public:
	void replaceSpace(char *str, int length) {

		if (str == NULL || length <= 0)  //�ж��ַ����ڴ�
			return;

		int numblank = 0, numlength = 0, i = 0;
		while (str[i] != '\0') {  //��ԭ���ַ�����չ�󳤶ȼ���
			if (str[i] == ' ')
				++numblank;

			++numlength;
			++i;
		}

		int newlength = numlength + 2 * numblank;
		if (newlength > length)
			return;

		while (newlength != numlength) {  //���ַ�����ĩβ��ʼ��ӡ�%20������ǰ�ƶ�
			if (str[numlength] == ' ') {
				str[newlength--] = '0';
				str[newlength--] = '2';
				str[newlength--] = '%';
			}
			else {
				str[newlength--] = str[numlength];
			}
			--numlength;
		}
	}

	void test() {
		vector<string> vec{ "We are Happy", "hello",
			"", "  hlee", "hll  ", "  srfe  ", "  se  sd " };
		for (int i = 0; i != vec.size(); i++) {
			char buf[256] = { 0 };
			strcpy_s(buf, vec[i].c_str());
			replaceSpace(buf, 256);
			cout << vec[i] << "   " << buf << endl;
		}
	}
};

//03��β��ͷ����ӡ����
class Solution03 {
	struct ListNode {  //����ָ��ṹ
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};

public:
	vector<int> dev;
	vector<int> printListFromTailToHead_recuit(ListNode* head) {  //���õݹ��˼������������
		if (head != NULL) {
			if (head->next != NULL)
				dev = printListFromTailToHead_recuit(head->next);
			dev.push_back(head->val);
		}
		return dev;
	}

	void printListFromTailToHead_itler(ListNode* head) {  //ʹ��ջ�������ķ�ʽ
		stack <ListNode*>node;
		ListNode* pnode = head;
		while (pnode != NULL) {
			node.push(pnode);
			pnode = pnode->next;
		}
		while (!node.empty()) {
			cout << node.top()->val << endl;
			node.pop();
		}
	}

	void test() {
		vector<int> vector_list;
		ListNode myHead(0), a(1), b(2), c(3), d(4), e(5), f(6);
		myHead.next = &a, a.next = &b, b.next = &c, c.next = &d,
			d.next = &e, e.next = &f;
		printListFromTailToHead_itler(&myHead);

		vector_list = printListFromTailToHead_recuit(&myHead);
		for (auto item : vector_list)
			cout << item << endl;
	}
};

//04�ؽ�������
class Solution04 {
	struct TreeNode {  //���ṹ
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) :
			val(x), left(NULL), right(NULL) {}
	};

public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		//�жϺ�������������
		int length = vin.size();
		if (pre.size() !=vin.size() || length <= 0) {
			return NULL;
		}

		//����ǰ������еĸ��ڵ�
		int lable_root;
		for (int i = 0; i<length; i++) {
			if (vin[i] == pre[0]) {
				lable_root = i;
				break;
			}
		}

		//�����ֳ���������������
		vector<int> pre_left, pre_right, vin_left, vin_right;
		for (int j = 1; j<length; j++) {
			if (j <= lable_root) {
				pre_left.push_back(pre[j]);
				vin_left.push_back(vin[j - 1]);
			}
			else {
				pre_right.push_back(pre[j]);
				vin_right.push_back(vin[j]);
			}
		}

		//�ݹ�������������ĸ�
		TreeNode* head = new TreeNode(pre[0]);
		head->left = reConstructBinaryTree(pre_left, vin_left);
		head->right = reConstructBinaryTree(pre_right, vin_right);
		return head;
	}

	// ���������ӡ  
	void preOrderTraverse(TreeNode * T) {
		if (T) {
			cout << T->val << " ";
			preOrderTraverse(T->left);
			preOrderTraverse(T->right);
		}
	}

	// ���������ӡ  
	void midOrderTraverse(TreeNode * T) {
		if (T) {
			midOrderTraverse(T->left);
			cout << T->val << " ";
			midOrderTraverse(T->right);
		}
	}

	// ���������ӡ  
	void endOrderTraverse(TreeNode * T) {
		if (T) {
			endOrderTraverse(T->left);
			endOrderTraverse(T->right);
			cout << T->val << " ";
		}
	}


	void test() {
		vector<vector<int>> pre{ { 1, 2, 4, 7, 3, 5, 6, 8 },
		{},{ 5 },{ 1, 2 },{ 1 },{ 1, 3 } };
		vector<vector<int>> in{ { 4, 7, 2, 1, 5, 3, 8, 6 },
		{},{ 5 },{ 1, 2 },{},{ 1, 2 } };
		for (int i = 0; i != pre.size(); i++) {
			TreeNode * res = reConstructBinaryTree(pre[i], in[i]);
			cout << "ǰ�����:" << endl;
			preOrderTraverse(res); 
			cout << endl << "�������:" << endl;
			midOrderTraverse(res);
			cout << endl << "�������:" << endl;
			endOrderTraverse(res);
		}
	}
};

int main()
{
	Solution04 temp;  //����ʵ����
	temp.test();

	system("pause");
	return 0;
}