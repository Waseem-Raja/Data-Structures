// TODAY WE ARE GOING TO TALK ABOUT LINKED LIST INSERTION
// THERE ARE SEVERAL WAYS TO INSERT IN A LINKED LIST BUT WE WILL ONLY SEE TWO OF THEM
// FIRST ONE IS  INSETING AT THE BACK OF A LINKED LIST
// SECOND ONE IS AT THE FRONT WITH O(1) TIME COMPLELXLITY
// SO LETS START
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class linkedlist
{
    Node *head;
    linkedlist()
    {
        head = NULL;
    }

    void insertattheback(int data)
    {
        Node *newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;
        if (head == NULL)
            head = newnode;
        else
        {
            //At the back
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newnode;
            //now at the start
            newnode->next=head;
            head=newnode;
        }
    }
};
