#include <iostream>
using namespace std;

// �Լ� ����
int gcd(int x, int y);

int main() {
    // �Է� �ޱ�
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // �м� ���
    int e = a * d + c * b;
    int f = b * d;

    // �ִ����� ���
    int temp = gcd(e, f);
    e /= temp;
    f /= temp;

    // ��� ���
    cout << e << ' ' << f << '\n';

    return 0;
}

// �Լ� ����
int gcd(int x, int y) {
    // �ִ����� ���
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}
