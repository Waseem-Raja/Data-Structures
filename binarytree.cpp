//LINKED  REPRESENTATION BINARY TREE
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

struct Node *Create(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right=NULL;
    return(newnode);
}
//Treversal preorder
void preorderTreversal(struct Node* temp)
{
    if (temp!=NULL)
    {
        cout<<"  "<< temp->data;
        preorderTreversal(temp->left);
        preorderTreversal(temp->right);
    }
}
//Treversal INorder
void InorderTreversal(struct Node* temp)
{
    if (temp!=NULL)
    {
       
        InorderTreversal(temp->left);
         cout<<"  "<< temp->data;
       InorderTreversal(temp->right);
    }
}
 //Treversal postorder
void postorderTreversal(struct Node* temp)
{
    if (temp!=NULL)
    {
       
        postorderTreversal(temp->left);
        postorderTreversal(temp->right);
         cout<<"  "<< temp->data;
    }
}
 
int main()
{
    struct Node* root=Create(1);
    root->left=Create(3);
    root->right=Create(4);
    root->left->left=Create(5);
    cout<<"Preorder Treversal of binary tree is "<<endl;
    preorderTreversal(root);
    cout<<endl;
     cout<<"Inorder Treversal of binary tree is "<<endl;
    InorderTreversal(root);
     cout<<endl;
     cout<<"Postorder Treversal of binary tree is "<<endl;
    postorderTreversal(root);
}