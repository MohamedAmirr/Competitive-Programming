#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

const int N = 3005, OO = 0x3f3f3f3f3f3f3f3f, MOD = 1e9 + 7;
long double x1, yy1, x2, y2, vx1, vy1, vx2, vy2;

long double valid(long double mid) {
    long double a, b, c, d;
    a = x1 + vx1 * mid;
    b = x2 + vx2 * mid;
    c = yy1 + vy1 * mid;
    d = y2 + vy2 * mid;
    long double ret = sqrt((b - a) * (b - a) + (c - d) * (c - d));
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> x1 >> yy1 >> x2 >> y2 >> vx1 >> vy1 >> vx2 >> vy2;
    long double l(0), r(1e6);
    for(int i = 0; i < 1000;i++){
        long double mid = l + (r - l) / 2;
        if (valid(mid) > valid((r + mid) / 2)) l = mid;
        else r = (r + mid) / 2;
    }
    cout << fixed << setprecision(15) << valid(l) << endl;
}
