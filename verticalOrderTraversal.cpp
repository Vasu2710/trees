
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

    //we express in terms of coordinates
    /*
   .. -2 -1 0 1 2 .. on x axis
   .. 0 1 2 3 .. on y axis 
   so that the root have the coordinate (0,0)
   */
   queue<pair<Node*, pair<int, int>>>q;
   map<<int, map<int, multiset<int>>>mp;
   q.push({root, {0, 0}});
   while(!q.empty())
   {
        Node* temp=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        mp[x][y].insert(temp->data);
        q.pop();
        if(temp->left)
          q.push({temp->left, {x-1, y+1}});
        if(temp->right)
          q.push({temp->right, {x+1, y+1}});
   }
   vector<vector<int>>ans;  //vector of levels
   for (auto p: mp) {
    vector < int > col;
    for (auto q: p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  
   






    return 0;
}
