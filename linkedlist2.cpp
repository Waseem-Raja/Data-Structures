#include <iostream>
using namespace std;

// Making a node struct containing a data int and a pointer
// to another node
struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    // start pointer
    Node *start;
    Node *tail;

public:
    // default constructor. Initializing start pointer
    LinkedList()
    {
        start = NULL;
        tail = NULL;
    }

    // inserting elements (At start of the list)
    void insert(int element)
    {
        // make a new node
        Node *newnode = new Node;
        newnode->data = element;
        newnode->next = NULL;

        // If list is empty, make the new node, the start
        if (start == NULL)
            start = newnode;
        // else, make the newnode the start and its next, the previous start(insert at the start)
        //else, make  another pointer equal to start pointer then traverse until you find last
        //node containing null then put newnode in that using the same pointer

        else
        { //inserting at the end
            Node *current = start;
            // Node *tail=NULL;
            while (current->next != NULL)
            {

                current = current->next;
                // tail = current;
            }
            current->next = newnode;
            tail = current->next;
            //inserting at the start that's in reverse
            //newnode->next = start;
            // start = newnode;
        }
    }
    //
    int search(int element)
    {
        int count = 0;         //count will contain number of times
        Node *search = start;  //creating another pointer for traversing equal to start
        while (search != NULL) //conditon will false at the last node whose pointer field will be containing null
        {
            if (search->data == element) //comparing the nodes data value pointed by search pointer
            {                            // with the passed element
                count++;                 //if matched count will be incremented
                search = search->next;   // and for traversing to other nodes search pointer needs
            }                            // their address so putting their pointerfield address into search
            else
                search = search->next; // if match not found still it has to traverse inorder to search all elements
        }
        return (count); //returning the count value
    }

    int deletion(int element)
    {
        if (start == NULL) //if start is null that means list is empty
        {
            cout << "list is Empty" << endl;
        }
        else if (start->next == NULL && start->data == element) // if list has only one node
        {
            Node *temp = start;
            //creating another pointer which points to the first node
            delete temp;  //by assigning start value to it, then freeing the memory
            start = NULL; //using this pointer and assigning NUll to the start
        }
        else //if list has more then one elements
        {
            Node *temp = start; //creating another pointer pointing to the first node
            Node *prev = NULL;  //creating another pointer which will point to the prev node
            //of the matched node
            while (temp != NULL && temp->data != element) //then traversing the list upto previous node
            {
                prev = temp;       //as temp will stop at prev node so now prev will also point to that node
                temp = temp->next; // for traversing
            }
            if (temp == NULL) //if temp reaches to the end and it will contain NULL so that is list is empty
            {
                cout << "Element not present in the list" << endl;
            }
            else
            {
                prev->next = temp->next; //here temp will point to the matched node to be deleted
                                         //and that node will contain the address of the next node so putting that nodes addres
                                         //in the prev nodes pointer field
                delete temp;             //then matched nodes memory will be freed
                cout << "Element deleted successfully" << endl;
            }
        }
    }
    int updation(int element, int updatedelement)
    {
        int count = 0;
        Node *temp = start;

        while (temp != NULL)
        {
            if (temp->data == element)
            {
                temp->data = updatedelement;
                cout << "Updated " << endl;
                count++;
            }
            temp = temp->next;
        }
        if (count == 0)
            cout << "Element not present so can't be updated" << endl;
    }
    void reverse()
    {
        if (start == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *next = NULL;   //this pointer will be used for traverse
            Node *temp = start;  //temp will help in storing each nodes address by traversing each node
            Node *store = start; //store pointer will store the nodes address
            next = temp->next;   //next will contain next nodes address
            temp->next = NULL;   //so its first node after reverse it will be last so putting nULL into its pointer field
            temp = next;         //inorder to traverse temp it should contain the next nodes address which is in next pointer
            while (next != NULL) // now for rest of the nodes
            {

                next = temp->next;  //firstly store next nodes address in next pointer
                temp->next = store; //then put previous nodes address into its pointer field
                store = temp;       //then store this nodes address into store pointer
                temp = next;        //inorder to traverse temp it should contain the next nodes address which is in next pointer
            }
            start = store; //then putting store pointers address into start so that start will
            //point to last node which will be first node after reverse
        }
    }

    void mergee(LinkedList &mylist) //calling with list one sending argument list two
    {

        if (mylist.start == NULL) //firstly if merging list ie second list countains nothing
        {
            cout << "can't merge an empty list" << endl;
        }
        else if (this->start == NULL) // if first list countains nothing
        {
            this->start = mylist.start; //then ist list head should point to 2nd list's first node so
                                        //putting 2nd list's first nodes address into it
            this->tail = mylist.tail;   //same goes with the tail
            mylist.start=NULL;      //now second list should be empty so putting null in its head
            mylist.tail=NULL;      // same with tail
        }
        else //if both the lists contain elements
        {

            this->tail->next = mylist.start; //putting 2nd list first nodes addres into tail of ist list pointer field
            this->tail = mylist.tail;        // also now tail should point to the last element of second list node so putting
                                             //2nd list tail address into first list tail point
            mylist.start=NULL;//now second list should be empty so putting null in its head
            //now new values can be inserted in second list as its previous values are merged with list one
            mylist.tail=NULL;   // same with tail
        }
    }
    void popAll()//deleting entire list
    {
        if(this->start==NULL)
        cout<<"can't pop as list is empty"<<endl;
        else{
            Node *current=start;
            Node *store=NULL;
            while (current!=NULL)
            {
                  store=current->next;
                  delete current;
                  current =store;
            }
            start=NULL;

            
        }
    }
    void display()
    {
        if (start != NULL)
        {
            Node *temp = start;
            // cout << "Elements are :" << endl;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
            cout << "List is empty" << endl;
    }
};
int main()
{

    LinkedList l;
    // inserting elements
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    cout << "Current Linked List1: " << endl;
    l.display();
    l.popAll();
    l.display();

   // LinkedList l2;
    // inserting elements for list two
    // l2.insert(6);
    // l2.insert(7);
    // l2.insert(8);
    // l2.insert(9);
    // l2.insert(10);
    // l2.display();
    // l.mergee(l2);
    // cout << "after mergee" << endl;
    // l.display();
    // l2.insert(1);
    // l2.display();

    // l.updation(6, 0);
    // l.display();
    // cout << "list after reverse" << endl;
    //l.reverse();
    //l.display();
    // cout << "after deleteion" << endl;
    // l.deletion(6);

    // int x = l.search(7);
    // if (x > 0)
    // {
    //     cout << "Element found " << x << " times" << endl;
    // }
    // else
    //     cout << "Element not found" << endl;
}
