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
void preorder(struct Node*root)
{
    if(root==NULL) return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node*root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void postorder(struct Node*root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}
int main() {
	// your code goes here
	struct Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	preorder(root);
	inorder(root);
	postorder(root);
}

