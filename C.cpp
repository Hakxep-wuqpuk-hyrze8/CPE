#include <bits/stdc++.h>

using namespace std;

const int mxN = 100005;
const double EPS = 1e-7;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

int lps[mxN], N, M;
char txt[mxN], pat[mxN];

void KMPtable() {

    int i = 1, len = 0;
    lps[0] = 0;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i++] = len;
        }
        else {
            if (len) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPsearch () {

    int i, j;
    i = j = 0;

    while (i < N) {
        if (txt[i] == pat[j]) {
            i++; j++;
        }

        if (i < N && txt[i] != pat[j]) {

            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return j;
}

void solve() {

    while (gets(txt)) {

        N = M = strlen(txt);
        for (int i = N-1, j = 0; i >= 0; i--, j++) {
            pat[j] = txt[i];
        }
        pat[M] = '\0';

        KMPtable();

        for (int i = 0; i < N; i++ ) {
            cout << txt[i];
        }
        for (int i = KMPsearch(); i < N; i++) {
            cout << pat[i];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}
