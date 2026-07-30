#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <sstream>
#include <cctype>
#include "Advancedcalculator.h"

using namespace std;


    int calculator:: prec(char op)
    {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    bool calculator:: checkvalid(const std::string& data)
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

    int calculator :: usedop(int x, int y, char op)
    {
        if (op == '^')
        return std::pow(x, y);

        if (op == '*')

            return x * y;

        if (op == '/')
        {
            if (y == 0)
            {
                std::cout << "Error: Division by zero" << std::endl;
                return 0;
            }
            return x / y;
        }

        if (op == '+')

             return x + y;

        if (op == '-')
          return x - y;

        return 0;
    }
          
    std::string calculator :: infix_to_postfix(const std::string& exp)
    {
        std::stack<char> s;
        std::stringstream out;

        for (int i = 0; i < exp.length(); i++)
        {
            char ch = exp[i];

            if (ch == ' ') continue;

            if (std::isdigit(ch))
            {
                while (i < exp.length() && std::isdigit(exp[i]))
                {
                    out << exp[i];
                    i++;
                }
                out << " ";
                i--;
            }
            else if (ch == '(')
            {
                s.push(ch);
            }
            else if (ch == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    out << s.top() << " ";
                    s.pop();
                }
                if (!s.empty()) s.pop();
            }
            else
            {
                while (!s.empty() && this->prec(s.top()) >= this->prec(ch))
                {
                    out << s.top() << " ";
                    s.pop();
                }
                s.push(ch);
            }
        }

        while (!s.empty())
        {
            out << s.top() << " ";
            s.pop();
        }

        return out.str();
    }

    int calculator :: solved_postfix(const std::string& exp)
    {
        std::stack<int> s;

        std::stringstream ss(exp);

        std::string val;

        while (ss >> val)
        {
            if (std::isdigit(val[0]))
            {
                s.push(std::stoi(val));
            }
            else
            {
                int y = s.top(); s.pop();

                int x = s.top(); s.pop();

                s.push(this->usedop(x, y, val[0]));
            }
        }

        return s.top();
    }

    void calculator :: solve(const std::string& exp)
    {
        if (!this->checkvalid(exp))
        {
            std::cout << "Invalid expression" << std::endl;

            return;
        }

        std::string post = this->infix_to_postfix(exp);

        int result = this->solved_postfix(post);

        std::cout << "------------------------" << std::endl;

        std::cout << "Expression  is: " << exp << std::endl;

        std::cout << "Result  is   : " << result << std::endl;

        std::cout << "------------------------" << std::endl;
    }

    void calculator :: help()
    {
        std::cout << "Usage menu calculator" << std::endl;

        std::cout << "calculator \"101 - ( 2 + 43 )\"" << std::endl;

        std::cout << "calculator 101 + 200" << std::endl;
    }


int main(int argc, char* argv[])
{
    calculator obj;
    std::string exp;

    if (argc == 2 && std::string(argv[1]) == "--help")
    {
        obj.help();
        return 0;
    }

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            exp += argv[i];
            exp += " ";
        }
        obj.solve(exp);
    }
    else
    {
        std::cout << "Enter the your expression  ";
        std::getline(std::cin, exp);

        obj.solve(exp);
    }

    return 0;
} 