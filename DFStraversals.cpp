#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root)
{
    if(root==NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root)
{
    if(root==NULL) 
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    
}
int main()
{
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right = new Node(3);


    //inorder.  left, root, right
    inorder(root);
    cout << "\n";


    //preorder. root, left, right

    preorder(root);
    cout << "\n";
    //postorder. left, right, root

    postorder(root);
    cout << "\n";
    return 0;
}
