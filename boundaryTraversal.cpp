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
bool isLeaf(Node* root)
{
    return root->left==NULL && root->right==NULL;
}
void addLeft(Node* root, vector<int>&ans)
{
    Node* temp=root->left;
    while(temp)
    {
        if(!isLeaf(temp))
          ans.push_back(temp->data);
        if(temp->left)
            temp=temp->left;
        else 
            temp=temp->right;
           
    }

}
void addLeaves(Node* root, vector<int>&ans)
{
    //inorder for adding leaves,  -->>-->> this pattern
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)
       addLeaves(root->left, ans);
    if(root->right)
       addLeaves(root->right, ans);
}
void addRight(Node* root, vector<int>&ans)
{
    vector<int>vec;
    Node* temp=root->right;
    while(temp)
    {
        if(!isLeaf(temp))
            vec.push_back(temp->data);
        if(temp->right)
          temp=temp->right;
        else
          temp=temp->right;
    }
    for(int i=vec.size()-1;i>=0;i--)
      ans.push_back(vec[i]);
}

int main()
{
    Node* root= new Node(1);
    root->left= new Node(2); 
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->left->right->left= new Node(6);
    root->left->right->right= new Node(7);

                     //boundaryTraversal
     /*  
        add all the left nodes ->iterative
        add all the leaf nodes ->recursive
        add all the right nodes in reverse fashion -> iterative 
    */
    vector<int>ans;
    ans.push_back(root->data);
    addLeft(root, ans);
    addLeaves(root, ans);
    addRight(root, ans);
    for(auto it: ans)
       cout << it << " ";



    return 0;
}
