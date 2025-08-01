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
        Node* parent = q.front();
        q.pop();

        Node* myLeft, *myRight;
        int l, r; cin >> l >> r;
        if(l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        
        if(r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);
        
        parent->left = myLeft;
        parent->right = myRight;

        if(parent->left)
            q.push(parent->left);

        if(parent->right)
            q.push(parent->right);
        
    }
    return root;

}

void print_left_root(Node* root)
{
    if(root == NULL)
        return;

    if(root->left)
        print_left_root(root->left);
    else
        print_left_root(root->right);

    cout << root->val << " ";
}

void print_right_root(Node* root)
{
    if(root == NULL)
        return;
    
    cout << root->val << " ";

    if(root->right)
        print_right_root(root->right);
    else
        print_right_root(root->left);
}

int main()
{
    Node* root = input_tree();
    print_left_root(root->left);
    cout << root->val << " ";
    print_right_root(root->right);
    // cout << root->val << " " << root->left->val << " " << root->right->val;



    return 0;
}