// BINARY SEARCH TREE REPRESENATION AND ITS OPERATIONS
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};
class Binarysearchtree
{
    Node *root;
    Node *track;

public:
    Binarysearchtree()
    {
        root = NULL;
        track = NULL;
    }
    struct Node *inertINbinarytree(int data)
    {
        Node *newnode = new Node;
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;

        if (root == NULL)
            root = newnode;
        else
        {
            Node *traverse = root;
            Node *point = NULL;
            while (traverse != NULL)
            {
                point = traverse;
                if (data > traverse->data) //its newnode-> data
                    traverse = traverse->right;
                else
                    traverse = traverse->left;
            }
            newnode->parent = point;
            if (data < point->data)
                point->left = newnode;
            else
                point->right = newnode;
        }
        return root;
    }
    struct Node *searchInBST(struct Node *traverse, int data)
    {
        if (traverse != NULL)
        {
            if (data == traverse->data)
                return traverse;
            else if (data < traverse->data)
                searchInBST(traverse->left, data);
            else
                searchInBST(traverse->right, data);
        }
        else
            return NULL;
    }

    struct Node *FindMaz(struct Node *find)
    {
        track = find;
        while (track->right != NULL)
            track = track->right;

        return track;
    }
    struct Node *FindMin(struct Node *find) // time complexity O(h)
    {
        track = find;
        while (track->left != NULL)
            track = track->left;

        return track;
    }

    struct Node *Delete(struct Node *root, int data)
    {
        struct Node *delte = searchInBST(root, data);
        if (delte == NULL)
            return NULL;
        else
        {
            // Case 1:  No child
            if (delte->left == NULL && delte->right == NULL)
            {
                if (data < delte->parent->data)
                    delte->parent->left = NULL;
                else
                    delte->parent->right = NULL;

                delete delte;
            }
            //Case 2: One child
            else if (delte->left == NULL)
            {
                if (data < delte->parent->data)
                    delte->parent->left = delte->right;
                else
                    delte->parent->right = delte->right;

                delete delte;
            }
            else if (delte->right == NULL)
            {
                if (data < delte->parent->data)
                    delte->parent->left = delte->left;
                else
                    delte->parent->right = delte->left;
                delete delte;
            }
            // case 3: 2 children
            else
            {
                struct Node *temp = FindMin(delte->right);
                delte->data = temp->data;
                if (temp->data < temp->parent->data)
                    temp->parent->left = NULL;
                else if (temp->left == NULL && temp->right == NULL)
                    temp->parent->right = NULL;

                else
                    temp->parent->right = temp->right;

                delete temp;
                //OR 
                /* 
                delte->right=Delete(delte->right,temp->data);
                */
            }
        }
        // return delte;
    }

    struct Node *Getsuccessor(struct Node *root, int data)
    {
        // Search the Node - O(h)
        struct Node *current = searchInBST(root, data);
        if (current == NULL)
            return NULL;
        if (current->right != NULL)
        {                                   //Case 1: Node has right subtree
            return FindMin(current->right); // O(h)
        }
        else
        { //Case 2: No right subtree  - O(h)
            struct Node *successor = NULL;
            struct Node *ancestor = root;
            while (ancestor != current)
            {
                if (current->data < ancestor->data)
                {
                    successor = ancestor; // so far this is the deepest node for which current node is in left
                    ancestor = ancestor->left;
                }
                else
                    ancestor = ancestor->right;
            }
            return successor;
        }
    }
    void printInorder(struct Node *walk) //O(n)
    {
        if (walk != NULL)
        {

        /* first recur on left child */
        printInorder(walk->left);

        /* then print the data of node */
        cout << walk->data << " ";

        /* now recur on right child */
        printInorder(walk->right);
        }
    }

    int getHeight_recursive(struct Node *node)
    {
        int x, y;

        if (node != NULL)
        {
            x = getHeight_recursive(node->left);
            y = getHeight_recursive(node->right);

            if (x > y)
                return x + 1;
            else
                return y + 1;
        }
    }
};
int main()
{
    Binarysearchtree bst;
    struct Node *root =bst.inertINbinarytree(15);
    bst.inertINbinarytree(3);
    bst.inertINbinarytree(4);
    bst.inertINbinarytree(13);
    bst.inertINbinarytree(14);
    bst.inertINbinarytree(12);
    bst.inertINbinarytree(5);
    bst.inertINbinarytree(1);
    bst.inertINbinarytree(8);
    bst.inertINbinarytree(2);
    bst.inertINbinarytree(7);
    bst.inertINbinarytree(9);
    bst.inertINbinarytree(11);
    bst.inertINbinarytree(6);
    bst.inertINbinarytree(20);
    bst.printInorder(root);
    cout << endl;

    // struct Node *point = bst.searchInBST(root, 15);
    // if (point == NULL)
    //     cout << "Element is not present in the tree" << endl;
    // else
    //     cout << point->data << " Element Found" << endl;

    // //  bst.FindMaz(root);
    // cout << "Maximum Element :" << bst.FindMaz(root)->data << endl;
    // cout << "Minimum Element :" << bst.FindMin(root)->data << endl;

    if (bst.Delete(root, 4) == NULL)
        cout << "Element is not present in the tree so can't delete" << endl;
    bst.printInorder(root);
    // Find Inorder successor of some node.
    // struct Node *successor = bst.Getsuccessor(root, 22);
    // if (successor == NULL)
    //     cout << "No successor Found\n";
    // else
    //     cout << "Successor is  :" << successor->data << "\n";
}
