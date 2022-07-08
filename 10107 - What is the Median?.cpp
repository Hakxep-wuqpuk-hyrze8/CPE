#include <bits/stdc++.h>

using namespace std;

const int mxN = 100005;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0,  1, 1};

int main()
{
    int N;
    vector<int> v;

    while (cin >> N) {

        v.insert(lower_bound(all(v), N), N);

        if (v.size() % 2) {
            cout << v[v.size() / 2] << '\n';
        } else {
            cout << ( v[v.size() / 2 - 1] + v[v.size() / 2] ) / 2 << '\n';
        }
        //for (auto e : v) cout << e << ' ';cout << '\n';
    }

    return 0;
}
