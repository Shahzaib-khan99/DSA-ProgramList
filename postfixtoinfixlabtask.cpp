#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postfixToInfix(string postfix)
{
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))
        {
            st.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op2 = st.top();
            st.pop();

            string op1 = st.top();
            st.pop();

            string exp = "(" + op1 + c + op2 + ")";
            st.push(exp);
        }
    }

    return st.top();
}

int main()
{
    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;

    return 0;
}