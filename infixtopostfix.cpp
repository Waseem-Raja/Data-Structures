// #include <iostream>
// using namespace std;
// #include <string>
// string output;
// class Infixtopostfix
// {
//     char stack[10];
//     int top;

// public:
//     Infixtopostfix()
//     {
//         top = -1;
//         // string output;
//     }
//     int infixtopostfixx(string arr)
//     {
//         int size = arr.length();

//         int i = 0;
//         while (i < size)
//         {
//             if (arr[i] == '*' || arr[i] == '/' || arr[i] == '+' || arr[i] == '-')
//             {
//                 if (!isempty())
//                 {
//                     char c = peek();
//                     int x = getPriority(c);
//                     int y = getPriority(arr[i]);
//                     if (y > x)
//                         push(arr[i]);
//                     else
//                     {
//                         while (getPriority(peek()) >= getPriority(arr[i]))
//                         {
//                             output += pop();
//                             //push(arr[i]);
//                         }
//                         push(arr[i]);
//                     }
//                 }
//                 else
//                     push(arr[i]);
//             }
//             else
//             {
//                 char y = arr[i];
//                 output += y;
//             }

//             i++;
//         }
//         while (!isempty())
//         {
//             output += pop();
//         }
//     }
//     void push(char opratorr)
//     {
//         stack[++top] = opratorr;
//     }
//     int getPriority(char c)
//     {
//         if (c == '^')
//             return 3;
//         else if (c == '/' || c == '*')
//             return 2;
//         else if (c == '+' || c == '-')
//             return 1;
//         else
//             return -1;
//     }
//     char pop()
//     {
//         char element;
//         element = stack[top--];
//         return element;
//     }
//     char peek()
//     {
//         return stack[top];
//     }
//     bool isempty()
//     {
//         return top < 0;
//     }
//     void display()
//     {
//         cout << "postfix expression :" << output << endl;
//     }
// };
// int main()
// {
//     Infixtopostfix obj;
//     string arr = "a+b*c";
//     obj.infixtopostfixx(arr);
//     obj.display();
// }

#include <iostream>
using namespace std;
#include <string>
//string output;
class Infixtopostfix
{
    char stack[10];
    int top;
    // string output;
public:
    Infixtopostfix()
    {
        top = -1;
        //string output;
    }
    void infixtopostfixx(string arr)
    {
        string output;
        int size = arr.length();

        int i = 0;
        while (i < size)
        {
            if (arr[i] == ')')
            {
                while (peek() != '(')
                {
                    output += pop();
                }
                pop();
            }
            else
            {
                if (arr[i] == '*' || arr[i] == '/' || arr[i] == '+' || arr[i] == '-' || arr[i] == '(')
                {
                    if (!isempty())
                    {
                        if (arr[i] == '(')
                            push(arr[i]);
                        else
                        {
                            char c = peek();
                            if (c == '(')
                                push(arr[i]);
                            else
                            {
                                int x = getPriority(c);
                                int y = getPriority(arr[i]);
                                if (y > x)
                                    push(arr[i]);
                                else
                                {
                                    while (getPriority(peek()) >= getPriority(arr[i]))
                                    {
                                        output += pop();
                                        //push(arr[i]);
                                    }
                                    push(arr[i]);
                                }
                            }
                        }
                    }
                    else
                        push(arr[i]);
                }
                else
                {
                    char y = arr[i];
                    output += y;
                }
            }
            i++;
        }
        while (!isempty())
        {
            output += pop();
        }
        cout << " Postfix Expression of this infix is:" << output << endl;
    }
    void push(char opratorr)
    {
        stack[++top] = opratorr;
    }
    int getPriority(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    char pop()
    {
        char element;
        element = stack[top--];
        return element;
    }
    char peek()
    {
        return stack[top];
    }
    bool isempty()
    {
        return top < 0;
    }
};
int main()
{
    Infixtopostfix obj;
    string arr = "c*(a+b)";
    obj.infixtopostfixx(arr);
    //obj.display();
}
/*    
if i is an oprand then add to the output string
or if i is an operator then and stack is empty then push it directly into the stack
or if  stack is not empty then check the precedence of peek() value if
it is greater then the new operator then pop until it becomes greater then all
all operators int stack  and add to the output string and push new operator 
into the string. else if it has less priority then the new operator then just push new
operator dirctly into the stack.
now if we have braces then if it is an opening brace then push it on the stack
and if next element is an operator and peek of stack is opening brace then push it 
into the stack then same logic will be applied as was for without braces
now if incoming elelment is an closing brace then pop all the operators 
until peek is equal to the opening brace and add them to the output string  also pop opening brace in last.


*/