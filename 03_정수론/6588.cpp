#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 에라토스테네스의 체를 이용하여 소수를 구하는 함수
vector<int> sieve() {
    const int MAX = 1000000;
    vector<bool> is_prime(MAX + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= MAX; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX; i += p)
                is_prime[i] = false;
        }
    }

    for (int p = 2; p <= MAX; ++p) {
        if (is_prime[p])
            primes.push_back(p);
    }

    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes = sieve();

    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < primes.size(); ++i) {
            if (primes[i] > n / 2)
                break;

            int complement = n - primes[i];

            // 두 홀수 소수의 합으로 n을 만들 수 있는지 확인
            if (binary_search(primes.begin(), primes.end(), complement)) {
                cout << n << " = " << primes[i] << " + " << complement << "\n";
                break;
            }
        }
    }

    return 0;
}
