#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> seq(N);
    for (int i = 0; i < N; ++i)
        cin >> seq[i];

    vector<int> ans(N, -1);
    stack<pair<int, int>> st;

    for (int i = 0; i < N; ++i) {
        while (!st.empty() && st.top().first < seq[i]) {
            ans[st.top().second] = seq[i];
            st.pop();
        }
        st.push(make_pair(seq[i], i));
    }

    for (int i = 0; i < N; ++i)
        cout << ans[i] << " ";

    return 0;
}
