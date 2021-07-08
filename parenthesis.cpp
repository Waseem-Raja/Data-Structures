#include<iostream>
using namespace std;
#include <bits/stdc++.h>

char push(char x, int top, char stack[])
{
    top++;
    stack[top] = x;
}
char pop(char stack[], int top)
{
    char y;
    y = stack[top];
    top--;
    return (y);
}

int main()
{
    int len = 0, top = -1;
    cout << "Enter the length of your expression" << endl;
    cin >> len;
    if (len <= 0)
        cout << "Enter the length greater then zero" << endl;
    else
    {
        char stack[len];
        char arr[len];
        cout << "Enter the expression" << endl;
        cin >> arr;
        for (int i = 0; i < len; i++)
        {
            if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
            {
                // Push the element in thestack
                push(arr[i], top, stack);
                top++;
            }
            else if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
            {
                if (top < 0)
                {
                    cout << "The expression is Unbalanced" << endl;
                    exit(0);
                }
                else
                {
                    char x = pop(stack, top);
                    top--;
                    if (arr[i] == x - 1 || arr[i] == x - 2 || arr[i] == x - 2)
                    {
                        continue;
                    }
                    else
                    {
                        cout << "The expression is Unbalanced" << endl;
                        exit(0);
                    }
                }
            }
        }

        if (top < 0)
        {
            cout << "The Expression is balanced" << endl;
        }
    }
}

/*Algorithm

Read the arring 
if the element is opening bracket then push it into the stack
else if the element is closing bracket then
check stack is empty
if stack is empty then print out unbalanced expression
else if stack is not empty then
pop the element from the stack and compare it with the current  element
if it matched then continue till the length of the arring
else if not matched then print out unbalanced expression
after executing whole this in the loop
check if the stack is empty then print out expression is balanced













*/