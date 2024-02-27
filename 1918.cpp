#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string expression;
    cin >> expression;

    stack<char> operators;

    for (char c : expression) {
        if (isalpha(c)) {
            cout << c;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                cout << operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                cout << operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        cout << operators.top();
        operators.pop();
    }

    return 0;
}
