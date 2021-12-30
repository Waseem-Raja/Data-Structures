//Check for balanced paranthesis by using Stacks
// #include<iostream>
// using namespace std;
// #include <bits/stdc++.h>

// int push(char x, int top, char stack[])
// {
//     top++;
//     stack[top] = x;
//     return(top);
// }
// char pop(char stack[], int top)
// {
//     char y;
//     y = stack[top];
//     top--;
//     return (y);
// }

// int main()
// {
//     int len = 0, top = -1;
//     cout << "Enter the length of your expression" << endl;
//     cin >> len;
//     if (len <= 0)
//         cout << "Enter the length greater then zero" << endl;
//     else
//     {
//         char stack[len];
//         char arr[len];
//         cout << "Enter the expression" << endl;
//         cin >> arr;
//         for (int i = 0; i < len; i++)
//         {
//             if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
//             {
//                 // Push the element in thestack
//                 int x=push(arr[i], top, stack);
//                 top=x;
//             }
//             else if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
//             {
//                 if (top < 0)
//                 {
//                     cout << "The expression is Unbalanced" << endl;
//                     exit(0);
//                 }
//                 else
//                 {
//                     char x = pop(stack, top);
//                     top--;
//                     if (arr[i] == x - 1 || arr[i] == x - 2 || arr[i] == x - 2)
//                     {
//                         continue;
//                     }
//                     else
//                     {
//                         cout << "The expression is Unbalanced" << endl;
//                         exit(0);
//                     }
//                 }
//             }
//         }

//         if (top < 0)
//         {
//             cout << "The Expression is balanced" << endl;
//         }
//     }
// }

/*Algorithm

Read the array 
if the element is opening bracket then push it into the stack
else if the element is closing bracket then
check stack is empty
if stack is empty then print out unbalanced expression
else if stack is not empty then
pop the element from the stack and compare it with the current  element
if it matched then continue till the length of the array
else if not matched then print out unbalanced expression
after executing whole this in the loop
check if the stack is empty then print out expression is balanced

*/

#include <iostream>
using namespace std;

class Parenthesis
{
    char stack[10];
    int top;

public:
    Parenthesis()
    {
        top = -1;
    }
    void push(char x)
    {
        top++;
        stack[top] = x;
    }
    char pop()
    {
        char x;
        x = stack[top];
        top--;
        return (x);
    }
    bool isempty()
    {

        if (top == -1)
            return true;
        else
            return false;
    }
    bool isEqual(char c1, char c2)
    {

        if (c1 == '(' && c2 == ')')
            return true;
        else if (c1 == '{' && c2 == '}')
            return true;
        else if (c1 == '[' && c2 == ']')
            return true;
        else
            return false;
    }
    bool isParenthesisBalanced(char s[])
    {

        int i = 0;

        /* Traverse the given string expression
            to check matching brackets */

        while (s[i])
        {
            /*If the s[i] is a opening bracket then
                  push it to Stack*/

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                push(s[i]);
            }
            /* If s[i] is a opening bracket then
                  *get top character from stack and match it
                  *to the current character if match
                  *found then pop it from Stack else
                  *return false*/

            else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (isempty())
                {
                    return false;
                }
                else
                {
                    //Corresponding brackets matched
                    //pop it from stack
                    char y = pop();
                    if (!(isEqual(y, s[i])))
                        return false;
                   // else
                     //   NULL;
                }
            }
            i++;
        }

        /*If Stack is empty then parenthesis
            are balanced or else not balanced
            */

        return isempty();
    }
};

/* Test program */

int main()
{
    char str[10]; // = {'{', '}'};
    Parenthesis p;

    cout << "Enter parenthesis expression:" << endl;
    cin.getline(str, 50);

    bool isBalanced = p.isParenthesisBalanced(str);

    if (isBalanced)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}