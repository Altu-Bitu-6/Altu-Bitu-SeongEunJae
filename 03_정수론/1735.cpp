#include <iostream>
using namespace std;

// 함수 선언
int gcd(int x, int y);

int main() {
    // 입력 받기
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 분수 계산
    int e = a * d + c * b;
    int f = b * d;

    // 최대공약수 계산
    int temp = gcd(e, f);
    e /= temp;
    f /= temp;

    // 결과 출력
    cout << e << ' ' << f << '\n';

    return 0;
}

// 함수 정의
int gcd(int x, int y) {
    // 최대공약수 계산
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}
