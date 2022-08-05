//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;

const int OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const ll N = 1e5;
const double EPS = 1e-6;
#define M_PI 3.14159265358979323846
#define all(a)  a.begin(),a.end()
#define endl '\n'

int lg(int n) { return 31 - __builtin_clz(n); }

const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};
//#define int long long

int c;

void solve(char i, set<char> st, map<char, int> mp) {
    if (st.empty()) {
        c++;
        return;
    }
    if (i > '5')return;
    if (st.find(i) == st.end())solve(i + 1, st, mp);

    if (i == '2') {
        if (mp['2'] > 0) {
            st.erase('2');
            mp['2']--;
            solve(i + 1, st, mp);
            mp['2']++;
            st.insert('2');
        }
        if (mp['1'] > 1) {
            st.erase('2');
            mp['1'] -= 2;
            solve(i + 1, st, mp);
            mp['1'] += 2;
            st.insert('2');
        }

    } else if (i == '3') {
        if (mp['3'] > 0) {
            st.erase('3');
            mp['3']--;
            solve(i + 1, st, mp);
            st.insert('3');
            mp['3']++;
        }
        if (mp['1'] > 0 and mp['2'] > 0) {
            st.erase('3');
            mp['1']--;
            mp['2']--;
            solve(i + 1, st, mp);
            st.insert('3');
            mp['1']++;
            mp['2']++;
        }

    } else if (i == '4') {
        if (mp['2'] >= 2) {
            st.erase('4');
            mp['2'] -= 2;
            solve(i + 1, st, mp);
            st.insert('4');
            mp['2'] += 2;
        }
        if ((mp['1'] > 0 and mp['3'] > 0)) {
            st.erase('4');
            mp['1']--;
            mp['3']--;
            solve(i + 1, st, mp);
            st.insert('4');
            mp['1']++;
            mp['3']++;
        }
        if (mp['4'] > 0) {
            st.erase('4');
            mp['4']--;
            solve(i + 1, st, mp);
            st.insert('4');
            mp['4']++;
        }
    } else if (i == '5') {
        if (mp['2'] >= 1 and mp['3'] >= 1) {
            st.erase('5');
            mp['2']--;
            mp['3']--;
            solve(i + 1, st, mp);
            st.insert('5');
            mp['2']++;
            mp['3']++;
        }
        if ((mp['1'] >= 1 and mp['4'] >= 1)) {
            st.erase('5');
            mp['1']--;
            mp['4']--;
            solve(i + 1, st, mp);
            st.insert('5');
            mp['1']++;
            mp['4']++;
        }
        if (mp['5'] > 0) {
            st.erase('5');
            mp['5']--;
            solve(i + 1, st, mp);
            st.insert('5');
            mp['5']++;
        }
    }
    return;
}


signed main() {
    besmellah
//Sky is the limit ❤
#ifdef CLION
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
#endif
    int T = 1;
    cin >> T;
//remember data type long long or int
    while (T--) {
        string s;
        map<char, int> mp;
        for (int i = 0; i < 7; ++i) {
            char ch;
            cin >> ch;
            if (ch == 'A')ch = '1';
            if (ch == 'B')ch = '2';
            if (ch == 'C')ch = '3';
            if (ch == 'D')ch = '4';
            if (ch == 'E')ch = '5';
            mp[ch]++;
        }
        c = 0;
        bool ch = 1;
        set<char> st;
        for (char i = '1'; i <= '5'; ++i) {
            st.insert(i);
        }
        if (mp['1'] > 0)mp['1']--, st.erase('1');
        else ch = 0;
        if (ch)
            solve('2', st, mp);
        if (ch and c)cout << "YES\n";
        else cout << "NO\n";
    }
//remember data type long long or int

}
