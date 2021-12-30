#include <iostream>
using namespace std;
#define size 10;
class Multiplestack
{
    int top1;
    int top2;
    int stack[10];

public:
    Multiplestack()
    {
        top1 = -1;
        top2 = 4;
    }
    int pushInStackOne(int element)
    {
        if (!isfullStackONe())
        {
            
            stack[++top1] = element;
        }
        else
            cout << "stack is full" << endl;
    }
    int pushInStackTwo(int element)
    {
        if (!isfullstacktwo())
        {
           
            stack[++top2] = element;
        }
        else
            cout << "stack is full" << endl;
    }
    int popfromStackOne()
    {
        if (!isemptyStackOne())
        {
            int element = stack[top1--];
            return (element);
        }
        else
            cout << "stack is empty so can't be popped" << endl;
    }
    int popfromStackTwo()
    {
        if (!isemptyStackTwo())
        {
            int element = stack[top2--];
            return (element);
        }
        else
            cout << "stack is empty so can't be popped" << endl;
    }
    bool isemptyStackOne()
    {
        return top1 == -1;
    }
    bool isemptyStackTwo()
    {
        return top2 == 4;
    }
    bool isfullStackONe()
    {
        return top1 == 4;
    }
    bool isfullstacktwo()
    {
        return top2 == 9;
    }
    void display()
    {
        if (!isemptyStackOne())
        {
            for (int i = 0; i <= top1; i++)
                cout << stack[i] << endl;
        }
        else
            cout << "stack is empty" << endl;

        if (!isemptyStackTwo())
        {
            for (int i = 5; i <= top2; i++)
                cout << stack[i] << endl;
        }
        else
            cout << "stack is empty" << endl;
    }
};
int main()
{
 Multiplestack stack;
//  stack.popfromStackOne();
//  stack.popfromStackTwo();
 stack.pushInStackOne(9);
 stack.pushInStackTwo(8);
 stack.display();



}
