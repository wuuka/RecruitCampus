#include<cstdio>
#include<vector>

using namespace std;

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true。否则返回false。假设输入的数组的任意两个数字都互不相同
class Solution24 {
public:
	bool VerifySquenceOfBST(vector<int> sequence)  //容器
	{
		int len = sequence.size();
		if (len <= 0) return false;
		vector<int> left, right;
		int root = sequence[len - 1];
		int i = 0;
		while (i<len - 1)  // 处理left部分 
		{
			if (sequence[i]>root) break;
			left.push_back(sequence[i]);
			i++;
		}
		int j = i; // 处理right部分，此时i为left部分最后一个结点的下标 
		while (j < len - 1)
		{
			if (sequence[j] < root) return false;
			right.push_back(sequence[j]);
			j++;
		}
		bool bleft = true; // 应初始化为true，left部分是BST序列，才能调用VerifySquenceOfBST()	
		if (i != 0) bleft = VerifySquenceOfBST(left); // i为left部分最后一个结点的下标 ，i!=0表示有左子树 
		bool bright = true;
		if (i != len - 1) bright = VerifySquenceOfBST(right);  // i!= len-1表示有右子树
		return (bleft && bright);
	}

	bool verifySquenceOfBST(int seq[], int length) {
		if (seq == NULL || length < 0)
			return false;

		int root = seq[length - 1];
		int i = 0;
		for (; i < length - 1; ++i) {  //left子树
			if (seq[i] > root)
				break;
		}

		for (int j = i; j < length - 1; ++j) {  //右子树
			if (seq[j] < root)
				return false;
		}

		bool left = true,right = true;  //递归区域
		if (i > 0)
			left = verifySquenceOfBST(seq, i);
		if (i < length - 1)
			right = verifySquenceOfBST(seq + i, length - i - i);

		return (left && right);

	}
};
// 以下为测试部分 
int main()
{
	Solution24 sol;
	vector<int> vec1 = { 2,5,3,7,9,8,6 };
	vector<int> vec2 = { 5,7,6,9,11,10,8 };
	vector<int> vec3 = { 7,4,6,5 };
	bool res1 = sol.VerifySquenceOfBST(vec1);
	bool res2 = sol.VerifySquenceOfBST(vec2);
	bool res3 = sol.VerifySquenceOfBST(vec3);

	printf("%d\n", res1);
	printf("%d\n", res2);
	printf("%d\n", res3);

	int arrary1[] = { 2,5,3,7,9,8,6 };
	int arrary2[] = { 5,7,6,9,11,10,8 };
	int arrary3[] = { 7,4,6,5 };

	bool res11 = sol.verifySquenceOfBST(arrary1,7);
	bool res21 = sol.verifySquenceOfBST(arrary2,7);
	bool res31 = sol.verifySquenceOfBST(arrary3,4);

	printf("%d\n", res11);
	printf("%d\n", res21);
	printf("%d\n", res31);
	return 0;
}
