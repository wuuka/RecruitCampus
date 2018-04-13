// 二叉搜索树与双向链表
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

//http://blog.csdn.net/zengzhen_csdn/article/details/51198530


class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)//总是一左一右的执行
            return NULL;
        if(pRootOfTree->left==NULL&&pRootOfTree->right==NULL)
            return pRootOfTree;//如果是叶子结点则就地返回，为空啥也不干就回来了
        TreeNode* left = Convert(pRootOfTree->left);//找到左子树最左端节点
        TreeNode* curr = left;
        while(curr!=NULL&&curr->right!=NULL)//找到左子树最右边节点
            curr=curr->right;//操作完成后往后面移动了一下
        //子问题返回左右子树的最左边的位置，但是如果是左边子树的话，我要得到左右边结点
        if(curr!=NULL)//连接根节点和左子树
        {
            curr->right=pRootOfTree;
            pRootOfTree->left = curr;
        }//完成最右边一个与头指针相连接
        TreeNode* right = Convert(pRootOfTree->right);//找到右子树最左端节点
        if(right!=NULL)//连接根节点和右子树
        {
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        return left!=NULL?left:pRootOfTree;//这里才是递归返回的地方 ，返回最左边的位置
    }
};
