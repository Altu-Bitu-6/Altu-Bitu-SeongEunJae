#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int cmp(string a, string b) {
    int asize = a.size();
    int bsize = b.size();
    
    if (asize != bsize) {
        return asize < bsize;
    }

    int asum = 0, bsum = 0;
    for (int i = 0; i < asize; i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            asum += a[i] - '0';
        }
        if (b[i] >= '0' && b[i] <= '9') {
            bsum += b[i] - '0';
        }
    }

    if (asum != bsum) {
        return asum < bsum;
    }

    return a < b;
}

int main() {
    int n;
    cin >> n;

    vector<string> serial(n);
    for (int i = 0; i < n; i++) {
        cin >> serial[i];
    }

    sort(serial.begin(), serial.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << serial[i] << "\n";
    }

    return 0;
}
