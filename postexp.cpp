//Evaluation of postfix expression
#include <iostream>
#include "stack"
using namespace std;
#include <stdlib.h>

class postexpression
{
    int stackk[10];
    int top;

public:
    postexpression()
    {
        top = -1;
    }
    int push(int element)
    {
        if (!isfull())
        {
            top++;
            stackk[top] = element;
        }
        else
            cout << "stack is full" << endl;
    }
    int pop()
    {
        if (!isempty())
        {
            int element = stackk[top];
            top--;
            return (element);
        }
        else
            cout << "stack is empty so can't be popped" << endl;
    }
    bool isempty()
    {
        return top == -1;
    }
    bool isfull()
    {
        return top >= 9;
    }

    int EvaluatePostexp(int op1, int op2, int sym)
    {
        int sum = 0;
        if (sym == 1)
            return (op1 + op2);
        else if (sym == 2)
            return (op1 - op2);
        else if (sym == 3)
            return (op1 * op2);
        else if (sym == 4)
            return (op1 / op2);
    }
    int checkOprand(int x)
    {
        switch (x)
        {
        case 43:
            return 1;
            break;
        case 45:
            return 2;
            break;
        case 42:
            return 3;
            break;
        case 47:
            return 4;
            break;

        default:
            return 0;
            break;
        }
    }
    void display()
    {
        cout << stackk[top] << endl;
    }
};
int main()
{
    int op1, op2;
    postexpression p;
    int arr[5] = {'*', 3, 3, '*', '+'};
    int i = 0;
    while (i < 5)
    {
        int x = arr[i];
        int y = p.checkOprand(x);
        if (y >= 1 && y <= 4)
        {
            if (p.isempty()){
             
                cout << "can't be evualvated try to enter valid expresssion" << endl;
                exit(0);
            }
            else
            {
                op1 = p.pop();
                op2 = p.pop();
                int sum = p.EvaluatePostexp(op1, op2, y);
                p.push(sum);
            }
        }
        else
            p.push(x);

        i++;
    }
    cout << "postfix expression evuluation is :" << endl;
    p.display();
}
