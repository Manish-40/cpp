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
int MaximumDepthOrHeightOfATree(struct Node*root)
{
    if(root==NULL) return 0;
    int leftDepth=MaximumDepthOrHeightOfATree(root->left);
    int rightDepth=MaximumDepthOrHeightOfATree(root->right);
    return (1+max(leftDepth,rightDepth));
}
int main() {
	// your code goes here
	struct Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->right->left=new Node(4);
	root->right->right=new Node(6);
	root->right->left->left=new Node(5);
	
	int depth=MaximumDepthOrHeightOfATree(root);
	cout<<depth<<endl;
}

