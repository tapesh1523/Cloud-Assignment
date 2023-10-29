#include<bits/stdc++.h>
#include<string>
#include<ctype.h>
using namespace std;
class Node{
    public:
        int val;
        Node *left;
        Node *right;

    Node(int data){
        this->val=data;
        this->left=this->right=NULL;
    }
};

// FindMax Added by Tapesh Sharma
int findMax(Node* root)
{
    if (root == NULL)
        return INT_MIN;
    int res = root->val;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

// Level order traversal Added by Manish Kumar Monu

void printLevelOrder(Node* root)
{
    // Base Case
    if (root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
 
    while (q.empty() == false) {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
 
        // Enqueue right child
        if (node->right != NULL)
            q.push(node->right);
    }
}
 

int main(){
    Node *root=new Node(3);
    root->left=new Node(9);
    root->left->left=new Node(4);
    root->left->left->right=new Node(5);
    root->left->left->left=new Node(4);
    root->left->right=new Node(5);  
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    root->right->right->left=new Node(7);
    root->right->right->left->left=new Node(6);
    
    int result=findMax(root);
    cout<<"Max Value in Tree:"<< result;
}
