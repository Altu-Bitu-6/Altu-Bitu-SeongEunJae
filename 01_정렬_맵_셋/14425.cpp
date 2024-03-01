#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N, M, ans;
string s;
vector<string> vec;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        vec.push_back(s);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < M; i++)
    {
        cin >> s;
        if (binary_search(vec.begin(), vec.end(), s))
            ans++;
    }

    cout << ans << '\n';
}
