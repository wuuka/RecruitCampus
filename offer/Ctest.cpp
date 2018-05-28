#include "stdafx.h"
//剑指offer面试编程案例

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//01 二维数组的查找
class Solution01 {
public:
	bool Find(int target, vector<vector<int> > array) {  //用两次vector来定义数组（动态数组定义）

														 //vector定义数组的行列长度查找；
		int row = array.size();
		int col = array[0].size();

		//判断数组含有变量
		if (row > 0 && col > 0) {

			int i = 0, j = col - 1;
			while (i < row && j >= 0) {  //方案一：选用数组右上角的点数做判断
				if (array[i][j] == target)
					return true;
				else if (array[i][j] > target)
					j--;
				else
					i++;
			}

			/*
			int i_ = row - 1, j_ = 0;
			while (i_ >= 0 && j_ < col) {  //方案二：选用数组左下角的点数做判断
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
			cout << "target " << target[i] << boolalpha <<  //bool类型数据显示
				"    std:" << (1 <= target[i] && target[i] <= 20) <<  //判断在（1， 20）范围之内
				"  res:" << Find(target[i], array) << endl;
		}
	}

};

//02 字符串空格的替换
class Solution02 {
public:
	void replaceSpace(char *str, int length) {

		if (str == NULL || length <= 0)  //判断字符串内存
			return;

		int numblank = 0, numlength = 0, i = 0;
		while (str[i] != '\0') {  //将原有字符串扩展后长度计算
			if (str[i] == ' ')
				++numblank;

			++numlength;
			++i;
		}

		int newlength = numlength + 2 * numblank;
		if (newlength > length)
			return;

		while (newlength != numlength) {  //将字符串从末尾开始添加“%20”，向前移动
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

//03 从尾到头来打印链表
class Solution03 {
	struct ListNode {  //定义指针结构
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};

public:
	vector<int> dev;
	vector<int> printListFromTailToHead_recuit(ListNode* head) {  //采用递归的思想进行输出链表
		if (head != NULL) {
			if (head->next != NULL)
				dev = printListFromTailToHead_recuit(head->next);
			dev.push_back(head->val);
		}
		return dev;
	}

	void printListFromTailToHead_itler(ListNode* head) {  //使用栈先入后出的方式
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

//04 重建二叉树
class Solution04 {
	struct TreeNode {  //树结构
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) :
			val(x), left(NULL), right(NULL) {}
	};

public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		//判断函数参数有意义
		int length = vin.size();
		if (pre.size() !=vin.size() || length <= 0) {
			return NULL;
		}

		//查找前序遍历中的根节点
		int lable_root;
		for (int i = 0; i<length; i++) {
			if (vin[i] == pre[0]) {
				lable_root = i;
				break;
			}
		}

		//将树分成左子树和右子树
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

		//递归查找左右子树的根
		TreeNode* head = new TreeNode(pre[0]);
		head->left = reConstructBinaryTree(pre_left, vin_left);
		head->right = reConstructBinaryTree(pre_right, vin_right);
		return head;
	}

	// 先序遍历打印  
	void preOrderTraverse(TreeNode * T) {
		if (T) {
			cout << T->val << " ";
			preOrderTraverse(T->left);
			preOrderTraverse(T->right);
		}
	}

	// 中序遍历打印  
	void midOrderTraverse(TreeNode * T) {
		if (T) {
			midOrderTraverse(T->left);
			cout << T->val << " ";
			midOrderTraverse(T->right);
		}
	}

	// 后序遍历打印  
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
			cout << "前序遍历:" << endl;
			preOrderTraverse(res); 
			cout << endl << "中序遍历:" << endl;
			midOrderTraverse(res);
			cout << endl << "后序遍历:" << endl;
			endOrderTraverse(res);
		}
	}
};

//06 旋转数组的最小数字
class Solution06 {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() <= 0)
			return 0;

		//二分查找法
		int vectorfirst = 0;
		int vectorend = rotateArray.size() - 1;
		int vectorMid = 0;
		while (rotateArray[vectorfirst] > rotateArray[vectorend]) {  //判断循环体注意对于一个元素时，不应该用相等去判断
			if (vectorend - vectorfirst == 1) {
				vectorMid = vectorend;
				break;
			}
			vectorMid = (vectorfirst + vectorend) / 2;
			if (rotateArray[vectorfirst] <= rotateArray[vectorMid])
				vectorfirst = vectorMid;
			else if (rotateArray[vectorend] >= rotateArray[vectorMid])
				vectorend = vectorMid;
		}
		return rotateArray[vectorMid];
	}

	void test() {
		vector<vector<int>> arr{ { 1, 2, 3, 4, 5 },{ 3, 4, 5, 1, 2 },
		{},{ 1 },{ 2, 1 },{ 1, 2 },{ 3, 1, 2 },{ 1, 2, 2, 3, 4,4, 5, 5, 5, 6, 6, 6 } ,
		{ 1, 1, 1,1, 1,1,1 } };
		for (int i = 0; i != arr.size(); i++) {
			cout << minNumberInRotateArray(arr[i]) << endl;
		}
	}
};

int main()
{
	Solution04 temp;  //调用实用类
	temp.test();

	system("pause");
	return 0;
}
