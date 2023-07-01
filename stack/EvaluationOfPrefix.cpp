// Evaluation of postfix expression
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int evaluatePrefixExpression(string expression);
bool isOperator(char ch);
int main(void)
{
    string postfix = "+9*26";
    cout << "The value of the expression is => " << evaluatePrefixExpression(postfix);
    return 0;
}
bool isOperator(char ch)
{
    if (ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '%')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int evaluatePrefixExpression(string expression)
{
    stack<int> st;
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        char ch = expression.at(i);

        if (!isOperator(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int element1 = st.top();
            st.pop();
            int element2 = st.top();
            st.pop();
            switch (ch)
            {
            case '+':
                st.push(element2 + element1);
                break;

            case '-':
                st.push(element2 - element1);
                break;
            case '*':
                st.push(element2 * element1);
                break;
            case '/':
                st.push(element2 / element1);
                break;
            }
        }
    }
    return st.top();
}