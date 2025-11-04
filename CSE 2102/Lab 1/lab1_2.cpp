#include <bits/stdc++.h>
using namespace std;

int prec(char c)
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

string infixToPostfix(string s)
{
	stack<char> st;
	string result;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;
		else if (c == '(')
			st.push('(');
		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while (!st.empty()
				&& prec(s[i]) <= prec(st.top())) {
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

	return result;
}
int evaluatePostfix(string exp)
{
    stack<int> st;
    for (int i = 0; i < exp.size(); ++i) {
        if (isdigit(exp[i]))
            st.push(exp[i] - '0');

        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (exp[i]) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
	string exp = "((2+3)-4*(6/3))+8";
	cout<<"Infix: "<<exp<<endl;
	string postexp= infixToPostfix(exp);
	cout<<"Postfix: "<<postexp<<endl;
    cout << "postfix evaluation: " << evaluatePostfix(postexp);
	return 0;
}
