#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <sstream>
#include <cctype>
#include "Scientificcalculator.h"

int calculator::prec(char op)
{
    if (op == '^')
    {
        return 3;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    if (op == '+' || op == '-')
    {
        return 1;
    }
    return 0;
}

bool calculator::checkvalid(const std::string & data)
{
    std::stack<char> s;

    for (int i = 0; i < data.length(); i++)
    {
        char ch = data[i];

        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            if (s.empty()) return false;
            s.pop();
        }
        else if (!std::isdigit(ch) && ch != '^' && ch != '*' && ch != '/' && ch != '+' && ch != '-' && ch != ' ')
            
        {
            return false;
        }
    }

    return s.empty();
}

int calculator::usedop(int a, int b, char op)
{
    if (op == '^')
    {

        return (int)std::pow(a, b);
    }
    if (op == '*')
    {
        return a * b;
    }
    if (op == '/')
    {
        if (b == 0)
        {
            std::cout << "error we cannot divided by zero " << std::endl;
            return 0;
        }
        return a / b;
    }

    if (op == '+')
    {

        return a + b;
    }
    if (op == '-')
    {
    
    return a - b;
}

    return 0;
}

std::string calculator::infix_to_postfix(const std::string& exp)
{
    std::stack<char> st;
    std::stringstream results;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == ' ') 
            continue;

        if (std::isdigit(ch))
        {
            while (i < exp.length() && std::isdigit(exp[i]))
            {
                results << exp[i];
                i++;
            }
            results << " ";
            i--;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                results << st.top() << " ";
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else
        {
            while (!st.empty() && this->prec(st.top()) >= this->prec(ch))
            {
                results << st.top() << " ";
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        results << st.top() << " ";
        st.pop();
    }

    return results.str();
} 

int calculator::solved_postfix(const std::string& exp)
{
    std::stack<int> st;

      std::stringstream input(exp);

        std::string t;

    while (input >> t)
    {
        if (std::isdigit(t[0]))
        {
             st.push(std::stoi(t));
        }
        else
        {
            if (st.size() < 2)
            {
                std::cout << "Input is invalid" << std::endl;
                return 0;
            }

            int b = st.top(); st.pop();
              int a = st.top(); st.pop();

            st.push(this->usedop(a, b, t[0]));
        }
    }

    return st.top();
}

void calculator::solve(const std::string& exp)
{
    if (!this->checkvalid(exp))
    {
        std::cout << "Expression is not valid." << std::endl;
        return;
    }

    std::string postfix = this->infix_to_postfix(exp);
    int answer = this->solved_postfix(postfix);

    std::cout << "\n====================\n";

        std::cout << "your input is  " << exp << std::endl;
           std::cout << "calculated answer is  " << answer << std::endl;
              std::cout << "=====================\n";
}

void calculator::help()
{
    std::cout << "How to use this Scientificcalculator?? \n";

         std::cout << "write in  calculator  like \"10 + (5 * 2)\" \n";

            std::cout << "we can also write another method like calculator 10 + 20 \n";
}

int main(int argc, char* argv[])
{
    calculator obj;
      std::string expr;

    if (argc == 2 && std::string(argv[1]) == "--help")
    {
        obj.help();
        return 0;
    }

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            expr+= argv[i];
            expr += " ";
        }
        obj.solve(expr);
    }
    else
    {
        std::cout << "enter your expresion here:: ";

         std::getline(std::cin, expr);
           obj.solve(expr);
    }

    return 0;
}