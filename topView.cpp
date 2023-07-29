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


int main()
{
    Node* root= new Node(1);
    root->left= new Node(2); 
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->left->right->left= new Node(6);
    root->left->right->right= new Node(7);
 /*
   .. -2 -1 0 1 2 ..
   we only want first of all the lines so we can do this by hashing
 */
   map<int, int>mp;//line number and node value , sorted 
   queue< pair<Node*, int>>q;  //node and the line number
   q.push({root, 0});
   while(!q.empty())
   {
       Node* temp=q.front().first;
       int line=q.front().second;
       q.pop();
       if(mp.find(line) == mp.end())
          mp[line]=temp->data;
       if(temp->left)
        q.push({temp->left, line-1});
       if(temp->right)
        q.push({temp->right, line+1});
   }
   vector<int>ans;
   for(auto it: mp)
   {
     ans.push_back(it.second);
   }
   for(auto it: ans)
   cout <<it << " ";






    return 0;
}
