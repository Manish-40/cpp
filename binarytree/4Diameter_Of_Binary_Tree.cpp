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
int DiameterOfBinaryTree(struct Node*root, int maxi)
{
    if(root==NULL) return 0;
    int lh=DiameterOfBinaryTree(root->left,maxi);
    int rh=DiameterOfBinaryTree(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return (1+max(lh,rh));
}
int main() {
	// your code goes here
	struct Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->right->left=new Node(4);
	root->right->right=new Node(5);
	root->right->left->left=new Node(5);
	
	int maxi=0;
	int diameter=DiameterOfBinaryTree(root,maxi);
	cout<<diameter<<endl;
}

