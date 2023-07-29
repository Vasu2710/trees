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

void levelorder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
        Node* temp=q.front();
        cout << temp->data << " ";
        q.pop();

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        }
        cout << "\n";
    }

}
int main()
{
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right = new Node(3);


    levelorder(root);
    return 0;
}
