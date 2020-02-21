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
int main()
{
    binarytree<int>* root = takeinputlevelwise();
    printtree(root);
    return 0;   
}
