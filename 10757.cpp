#include <iostream>
#include <stack>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int lenA = a.length();
    int lenB = b.length();

    stack<int> s;

    if (lenB > lenA) {
        swap(a, b);
        swap(lenA, lenB);
    }

    string tmp = "";
    if (lenA != lenB) {
        for (int i = 0; i < (lenA - lenB); i++)
            tmp += "0";
    }
    b = tmp + b;

    int carry = 0;

    for (int i = lenA - 1; i >= 0; i--) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        int digit = x + y + carry;

        if (digit > 9) {
            carry = 1;
            digit -= 10;
        }
        else {
            carry = 0;
        }

        s.push(digit);
    }

    if (carry == 1)
        s.push(1);

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}
