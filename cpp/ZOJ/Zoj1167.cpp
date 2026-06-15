#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    bool exist;//节点是否被赋值过
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *l,TreeNode *r):val(x),left(l),right(r){}
};
class Solution
{
    public:
        TreeNode *root=nullptr;
        bool isFailed=false;//是否重复赋值，只有错改对没有对改错
        void deleteNode(TreeNode *Head)
        {
            if(Head==nullptr)
            {
                return;
            }
            deleteNode(Head->left);
            deleteNode(Head->right);
            delete Head;
        }
        void addNode(int x,string path)
        {
            TreeNode *cur=root;
            for(char move:path)
            {
                if(move=='L')
                {
                    if(!cur->left)
                    {
                        cur->left=new TreeNode();
                    }
                    cur=cur->left;
                }
                else if(move=='R')
                {
                    if(!cur->right)
                    {
                        cur->right=new TreeNode();
                    }
                    cur=cur->right;
                }
            }
            if(cur->exist)
            {
                isFailed=true;
            }
            cur->exist=true;
            cur->val=x;
        }
        void BFS()
        {
            if(isFailed)
            {
                cout<<"not complete"<<endl;
                return;
            
            }
            vector<int> ans;
            queue<TreeNode*> QUEUE;
            QUEUE.push(root);
            while(!QUEUE.empty())
            {
                TreeNode *cur=QUEUE.front();
                QUEUE.pop();
                if(!cur->exist)
                {
                    cout<<"not complete"<<endl;
                    return;
                }
                ans.push_back(cur->val);
                if(cur->left)
                {
                    QUEUE.push(cur->left);
                }
                if(cur->right)
                {
                    QUEUE.push(cur->right);
                }
            }
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<((i==ans.size()-1)?"":" ");
            }
            cout<<endl;
        }

};
bool parseAndRun() 
{
    string s;
    Solution *sol = new Solution();
    bool hasData = false;

    while (cin >> s) {
        if (s == "()") {
            sol->BFS();
            sol->deleteNode(sol->root);
            delete sol;
            return true;
        }
        
        hasData = true;
        int val;
        char path_buf[300];
        // 解析 (val,path) 格式
        if (sscanf(s.c_str(), "(%d,%[^)]", &val, path_buf) == 2) {
            sol->addNode(val, string(path_buf));
        } else {
            // 处理路径为空的情况 (根节点)
            sscanf(s.c_str(), "(%d,)", &val);
            sol->addNode(val, "");
        }
    }
    return false; // EOF
}
int main() 
{
    while (parseAndRun());
    return 0;
}
