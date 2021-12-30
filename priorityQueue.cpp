//PriorityQueue using Lilnked List
//                       peek() |   push() |   pop()
//Linked List |    O(1)       O(n)      O(1)
#include <iostream>
using namespace std;
struct Node
{
    int data;
    int priority;
    Node *next;
};
class PriorityQueue
{
    Node *head = NULL;

public:
    int insert(int data, int priority) //inserting elements
    {
        Node *newnode = new Node; //creating node
        newnode->data = data;
        newnode->priority = priority;
        newnode->next = NULL;
        if (head == NULL) //this is for first node
            head = newnode;

        else //if there is already a node pointed by top
        {
            Node *temp = NULL;
            if (newnode->priority > head->priority) // checking priority according to decending order
            {
                temp = head;
                head = newnode; //prepend method
                head->next = temp;
            }
            else if (head->next == NULL)
            {
                head->next = newnode;
            }
            else
            //postpend
            {
                Node *current = head;
                Node *prev = head;
                while (current != NULL)
                {
                    if (newnode->priority > current->priority)
                    {
                        prev->next = newnode;
                        newnode->next = current;
                        current=NULL;
                    }
                    else
                    {
                        prev = current;
                        current = current->next;
                    }
                }
                prev->next=newnode;
            }
        }
    }
    int DeleteHigestPriority()
    {
        if (head != NULL)
        {
            Node *temp = head;
            int element = head->data;
            head = temp->next;
            delete temp;
            return element;
        }
        else
            cout << "list is empty" << endl;
    }
    int Gethighestpriority()
    {
        if (head != NULL)
        {
            return head->data; //highest priority element will be always pointed by head
        }
        else
            cout << "llist is empty" << endl;
    }
    void display()
    {
        Node *traverse = head;
        while (traverse != NULL)
        {
            cout << traverse->data << endl;
            traverse = traverse->next;
        }
    }
    // ~PriorityQueue() //destructor
    // {
    //     if (this->head != NULL)
    //     {
    //         Node *current = NULL;

    //         while (head != NULL)
    //         {
    //             current = head;
    //             head = current->next;
    //             delete current;
    //         }
    //     }
    // }
};

int main()
{
    PriorityQueue list;
    list.insert(4, 9);
    list.insert(5, 2);
    list.insert(6, 10);
    list.insert(7, 5);
    list.insert(7, 7);
    list.display();
    // list.DeleteHigestPriority();
    // cout << "Element with Highest Priority is: " << list.Gethighestpriority() << endl;
    // list.display();
}