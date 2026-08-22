#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
vector<vector<int>>LevelOrderTraversal(struct Node*root)
{
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<struct Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int i;
        int len=q.size();
        vector<int>a;
        for(i=0;i<len;i++)
        {
            struct Node*node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            a.push_back(node->data);
        }
        ans.push_back(a);
    }
    int i;
    int j;
    for(i=0;i<ans.size();i++)
    {
        for(j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<endl;
        }
    }
    return ans;
}
int main() {
	// your code goes here
	struct Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	LevelOrderTraversal(root);
}

