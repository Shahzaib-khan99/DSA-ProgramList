 #include<iostream>
#include<string>

using namespace std;

class stack {
private:
	int top;
	int arr[100];
public:
	stack() {
		top = -1;

	}
	void push(int val) {
		if (top == 99) {
			cout << "stack is overflow" << endl;
		}
		else {
			//++top;
			//arr[top] == val;
			arr[++top] = val;
		}
	}
	int pop() {
		if (top == -1) {
			cout << "stack is empty" << endl;
		}
		else {
			top--;
			int val = arr[top];
			return val;
		}
	}
	int top() {
		return arr[top];
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == 99;
	}

	int precedence(char op)
	{
		if (op == '^')
		{
			return 3;
		}
		else if (op == '*' || op == '/')
		{
			return 2;
		}
		else if (op == '+' || op == '-')
		{
			return 1;
		}
		else {
			return -1;
		}
	}

	bool isoperator (char c)
	{
		return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
	}

	void infixToPostfix(string s) {
		stack st;
		string result;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
				result += c;
			}
			else if (c == '(') {
				st.push('(');
			}
			else if (c == ')') {
				while (!st.empty() && st.top() != '(') {
					result += st.top();
					st.pop();
				}
				st.pop();
			}
			else if (isoperator(c)) {
				while (!st.empty() && precedence(st.top()) >= precedence(c)) {
					result += st.top();
					st.pop();
				}
				st.push(c);
			}
		}
		while (!st.empty()) {
			result += st.top();
			st.pop();
		}
		cout << result << endl;
	}
};
int main() {
	
	string infix;
	cout << "Enter an infix expression: ";	
	cin >> infix;
 
	stack st;
	st.infixTopostfix(infix);
}