// ������������˫������
//����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

//http://blog.csdn.net/zengzhen_csdn/article/details/51198530

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)//����һ��һ�ҵ�ִ��
            return NULL;
        if(pRootOfTree->left==NULL&&pRootOfTree->right==NULL)
            return pRootOfTree;//�����Ҷ�ӽ����͵ط��أ�Ϊ��ɶҲ���ɾͻ�����
        TreeNode* left = Convert(pRootOfTree->left);//�ҵ�����������˽ڵ�
        TreeNode* curr = left;
        while(curr!=NULL&&curr->right!=NULL)//�ҵ����������ұ߽ڵ�
            curr=curr->right;//������ɺ��������ƶ���һ��
        //�����ⷵ����������������ߵ�λ�ã������������������Ļ�����Ҫ�õ����ұ߽��
        if(curr!=NULL)//���Ӹ��ڵ��������
        {
            curr->right=pRootOfTree;
            pRootOfTree->left = curr;
        }//������ұ�һ����ͷָ��������
        TreeNode* right = Convert(pRootOfTree->right);//�ҵ�����������˽ڵ�
        if(right!=NULL)//���Ӹ��ڵ��������
        {
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        return left!=NULL?left:pRootOfTree;//������ǵݹ鷵�صĵط� ����������ߵ�λ��
    }
};