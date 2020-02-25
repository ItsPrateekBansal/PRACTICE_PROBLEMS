#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

template<typename T>
class binarytree
{
    public:
    binarytree* left;
    binarytree* right;
    T data;
    binarytree(int data)
    {
        this->data=data;
        left = NULL;
        right = NULL;
    }
    ~binarytree()
    {
        delete left;
        delete right;
    }
};
//function to find if a particular element is present in the given binary tree or not
//STARTS
bool isNodePresent(binarytree<int>* root, int x) {
    if(root == NULL)
        return false;
    if(root->data == x)
        return true;
    bool ans = isNodePresent(root->left,x);
    bool ans2= isNodePresent(root->right,x);
    return (ans||ans2);

}
//function to find if a particular element is present in the given binary tree or not
//ENDS

//function to mirror the given binary tree
//STARTS
void mirrorBinaryTree(binarytree<int>* root) {
    if(root == NULL)
        return;
    binarytree<int>* temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
//ENDS
//function to mirror the given binary tree
void printtree(binarytree<int>* root)
{   
    if(root == NULL)
    return;
    cout<<root->data<<" : ";
    if(root->left != NULL){
        cout<<" L : "<<root->left->data;
    }
      if(root->right != NULL){
        cout<<" R : "<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}
binarytree<int>* takeinput()
{
     int rootdata;
     cout << "Enter Data " << endl;
     cin >> rootdata;
     if(rootdata == -1)
     return NULL;
     binarytree<int>* root = new binarytree<int>(rootdata);
     binarytree<int>* leftchild = takeinput();
     binarytree<int>* rightchild = takeinput();
     root->right = rightchild;
     root->left = leftchild;
     return root;
}
binarytree<int>* takeinputlevelwise()
{
    int rootdata;
    cout << "\nEnter the Root Data : " << endl;
    cin >> rootdata;
    if(rootdata == -1)
    return NULL;
    binarytree<int>* root = new binarytree<int>(rootdata);
    queue<binarytree<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0){

    binarytree<int>* front = pendingnodes.front();
    pendingnodes.pop();
    cout << "\nEnter the Left Children of " <<front->data << endl;
    int left_data;
    cin >> left_data;
    if(left_data != -1)
    {
        binarytree<int>* left = new binarytree<int>(left_data);
        front->left = left;
        pendingnodes.push(left);
    }
    else
    {
       // binarytree<int>* left = NULL;
        front->left = NULL;
       // pendingnodes.push(left);
    }
    
    
    int right_data;
    cout << "\nEnter the Right Children of " << front->data << endl;
    cin >> right_data;
    if(right_data != -1)
    {
        binarytree<int>* right = new binarytree<int>(right_data);
        front->right = right;
        pendingnodes.push(right);
    }
    else
    {
       // binarytree<int>* right = NULL;
        front->right = NULL;
       // pendingnodes.push(right);
    } 
    }
    return root;
}
//FUNCTION TO PRINT THE GIVEN BINARY TREE IN A ZIG ZAG ORDER
//STARTS HERE
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int>*> s1,s2;
    s1.push(root);
    while(s1.size() != 0 || s2.size() != 0)
    {
        while(s1.size() != 0)
        {
            cout<<s1.top()->data<<" ";
            if(s1.top()->left)
            s2.push(s1.top()->left);
            if(s1.top()->right)
            s2.push(s1.top()->right);
            s1.pop();
        }
        cout<<endl;
        while(s2.size() != 0)
        {
            cout<<s2.top()->data<<" ";
            if(s2.top()->right)
            s1.push(s2.top()->right);
            if(s2.top()->left)
            s1.push(s2.top()->left);
            s2.pop();
            
        }
        cout<<endl;
    }
}
//FUNCTION TO PRINT THE GIVEN BINARY TREE IN A ZIG ZAG ORDER
//STARTS HERE
int main()
{
    binarytree<int>* root = takeinputlevelwise();
    printtree(root);
    return 0;   
}
