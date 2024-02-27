#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    while (true) {
        string input;
        getline(cin, input);

        if (input == ".") {
            break;
        }

        stack<char> s;

        bool balanced = true;
        for (char c : input) {
            if (c == '(' || c == '[') {
                s.push(c);
            }
            else if (c == ')') {
                if (s.empty() || s.top() != '(') {
                    balanced = false;
                    break;
                }
                s.pop();
            }
            else if (c == ']') {
                if (s.empty() || s.top() != '[') {
                    balanced = false;
                    break;
                }
                s.pop();
            }
        }

        if (balanced && s.empty()) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
