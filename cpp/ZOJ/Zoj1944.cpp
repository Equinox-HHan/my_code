#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    char value;
    TreeNode *leftNode;
    TreeNode *rightNode;
    TreeNode(char value):value(value),leftNode(nullptr),rightNode(nullptr){}
    TreeNode(char Value,TreeNode *left,TreeNode *right)
    {
        this->value=value;
        leftNode=left;
        rightNode=right;
    }
};
class BuildTree//根据先序遍历和中序遍历重建一棵树
{
    public:
        void lastOrder(TreeNode* Head)
        {
            if(Head==nullptr)
            {
                return;
            }
            lastOrder(Head->leftNode);
            lastOrder(Head->rightNode);
            cout<<Head->value<<endl;
        }
    private:
        TreeNode* func(string &pre,int l1,int r1,string &in,int l2,int r2,unordered_map<char,int> &map)
        {
            if(l1>r1)
            {
                return nullptr;
            }
            TreeNode *head=new TreeNode(pre[l1]);
            if(l1==r1)
            {
                return head;//优化减少递归
            }
            int k=map[pre[l1]];
            head->leftNode=func(pre,l1+1,l1+k-l2,in,l2,k-1,map);
            head->rightNode=func(pre,l1+k-l2+1,r1,in,k+1,r2,map);
            return head;
        }
        TreeNode* buildTree(string &preOrder,string &inOrder)
        {
            if(preOrder.size()==0||inOrder.size()==0||preOrder.size()!=inOrder.size())
            {
                return nullptr;
            }
            unordered_map<char,int> Hashmap;
            for(int i=0;i<inOrder.size();i++)
            {
                Hashmap[inOrder[i]]=i;
            }
            func(preOrder,0,preOrder.size()-1,inOrder,0,inOrder.size()-1,Hashmap);
        }
};
int main()
{
    return 0;
}