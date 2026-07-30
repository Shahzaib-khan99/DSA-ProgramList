#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                result += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;

    return 0;
}