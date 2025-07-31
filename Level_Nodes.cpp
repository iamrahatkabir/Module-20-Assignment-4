#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree()
{
    int val; cin >> val;
    Node* root;
    if(val == -1)
        root = NULL;
    else 
        root = new Node(val);

    queue<Node*> q;
    if(root)
        q.push(root);

    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();

        int l, r; cin >> l >> r;
        Node* myLeft, *myRight;

        if(l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);

        if(r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if(p->left)
            q.push(p->left);

        if(p->right)
            q.push(p->right);
    }

    return root;

}

void level_print(Node* root, int x)
{
    if(root == NULL)
        return;

    queue<pair<Node*, int>> q;
    queue<pair<int, int>> q_level;

    if(root)
    {
        q.push({root, 0});
        q_level.push({root->val, 0});
    }

    while(!q.empty())
    {
        pair<Node*, int> parent = q.front();
        Node* node = parent.first;
        int level = parent.second;
        q.pop();

        if(node->left)
        {
            q.push({node->left, level+1});
            q_level.push({node->left->val, level+1});
        }

        if(node->right)
        {
            q.push({node->right, level+1});
            q_level.push({node->right->val, level+1});
        }
    }

    while(!q_level.empty())
    {
        pair<int, int> q_print = q_level.front();
        pair<int, int> qBack = q_level.back();

        
        if(x > qBack.second)
        {
            cout << "Invalid" << endl;
            break;
        }
        else if(q_print.second == x)
        {
            cout << q_print.first << " ";
            q_level.pop();
        }
        else
            q_level.pop();

    } 
}

int main()
{
    Node* root = input_tree();
    int x; cin >> x;

    level_print(root, x);



    return 0;
}