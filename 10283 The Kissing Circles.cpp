#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e9;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

int main()
{
    double R, K;

    while (cin >> R >> K) {
        double angle = ((180 / K) * PI) / 180;
        double val = sin(angle);

        double r = val * R / ( val + 1);
        cout << fixed << setprecision(10) << r << ' ';
        double rangle = 90 - 180 / K; // 扇形角度
        double cir = PI * r * r * (rangle / 360);  // 扇形面積
        double e = sqrt( (R-r) * (R-r) - r * r);// 另一個邊長
        double blue = (e * r / 2 - cir) * 2 * K; // 藍色
        cout << fixed << setprecision(10) << blue << ' ';

        double green = PI * R * R - blue - PI * r * r * K;
        cout << fixed << setprecision(10) << green << ' ';
    }

    return 0;
}
