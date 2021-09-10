#include <iostream>
using namespace std;
#include <math.h>

struct Node
{
    int cofficent; //cofficent of a variable
    int power;     //power of a variable
    Node *next;    // pointer to link next node
};
class Polynomiall
{
    Node *head;

public:
    Polynomiall() //default constructor
    {
        head = NULL;
    }

    int insert(int cofficent, int power) //insert function to store coffient and power of a variable
    {

        Node *newNode = new Node; //creating a new node
        newNode->cofficent = cofficent;
        newNode->power = power;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;

        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            // current = newNode;
            // current->cofficent = cofficent;
            // current->power = power;
            // current->next = NULL;
        }
    }

    int Evaluate(int x)
    {
        int sum = 0;
        Node *current = head;

        while (current != NULL)
        {
            sum += current->cofficent * pow(x, current->power);
            current = current->next;
        }
        return (sum);
    }

    Polynomiall *addition(Polynomiall &poly)
    {
        Polynomiall *sum = new Polynomiall; //allocating memory for sum object as it is a pointer
        Node *p1 = this->head;
        Node *p2 = poly.head;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->power > p2->power)
            {
                sum->insert(p1->cofficent, p1->power);
                p1 = p1->next;
            }
            else if (p1->power < p2->power)
            {
                sum->insert(p2->cofficent, p2->power);
                p2 = p2->next;
            }
            else
            {
                sum->insert(p1->cofficent + p2->cofficent, p1->power);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        while (p1 != NULL)
        {
            sum->insert(p1->cofficent, p1->power);
            p1 = p1->next;
        }

        while (p2 != NULL)
        {

            sum->insert(p2->cofficent, p2->power);
            p2 = p2->next;
        }
        return sum;
    }

    void display()
    {
        Node *current = head;
        cout << current->cofficent << "x^" << current->power << " ";
        current = current->next;
        while (current != NULL)
        {
            if (current->next == NULL)
            {
                if ((current->next == NULL && current->power == 0) && current->cofficent >= 1)
                    cout << "+" << current->cofficent << " ";
                else if (current->power == 0)
                    cout << current->cofficent << " ";
                else if (current->power > 1 && current->cofficent > 0)
                    cout << "+" << current->cofficent << "x^" << current->power << " ";

                else if (current->cofficent > 0)
                    cout << "+" << current->cofficent << "x"
                         << " ";
                else
                    cout << current->cofficent << "x"
                         << " ";
            }
            else
            {
                if (current->cofficent >= 1)
                {
                    if (current->power == 1)
                        cout << "+" << current->cofficent << "x"
                             << " ";
                    else
                        cout << "+" << current->cofficent << "x^" << current->power << " ";
                }
                else
                {
                    if (current->power == 1)
                        cout << current->cofficent << "x"
                             << " ";
                    else
                        cout << current->cofficent << "x^" << current->power << " ";
                }
            }
            current = current->next;
        }
    }
};

int main()
{

    Polynomiall p, p2;
    p.insert(3, 2);
    p.insert(2, 1);
    p.insert(1, 0);
    p.display(); cout<<endl;
    p2.insert(4, 3);
    p2.insert(3, 2);
    p2.insert(2, 1);
    p2.display(); cout<<endl;

    Polynomiall *sum = p.addition(p2);
    cout << "Addition :" << endl;
    sum->display();
    return 0;
}
