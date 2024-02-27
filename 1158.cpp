#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    deque<int> q;
    for (int i = 1; i <= n; i++) {
        q.push_back(i);
    }

    cout << "<";

    while (q.size() > 1) {
        for (int i = 1; i < k; i++) {
            int tmp = q.front();
            q.pop_front();
            q.push_back(tmp);
        }
        cout << q.front() << ", ";
        q.pop_front();
    }
    cout << q.front() << ">\n";

    return 0;
}
