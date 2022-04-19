#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e4;
#define M_PI 3.14159265358979323846
#define endl '\n'
int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};

//we will dfs over grid to check if we have a winner(X) or not
//then re-check for winner(O)

char grid[3][3];
bool check_winning1 = false;

bool valid(int x, int y) {
    return x >= 0 and x < 3 and y < 3 and y >= 0;
}

void dfs(int i, int j, int p, int cnt) {
    if (cnt == 3) {
        check_winning1 = true;
        return;
    }
    for (int k = 0; k < 8; ++k) {
        int x = dx[k] + i;
        int y = dy[k] + j;
        if (!valid(x, y))continue;
        if (grid[i][j] == grid[x][y] and (k == p or p == -1)) {
            dfs(x, y, k, cnt + 1);
        }
    }
}

int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //    freopen("closing.out", "w", stdout);
#endif
    string t;
    while (cin >> t and t != "end") {
        int x = 0, o = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                grid[i][j] = t[3 * i + j];
                if (grid[i][j] == 'X')x++;
                if (grid[i][j] == 'O')o++;
            }
        }
        if (o > x or x - o > 1) {
            cout << "invalid\n";
            continue;
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 'X') {
                    dfs(i, j, -1, 1);
                }
            }
        }
        bool check_winning2 = false;
        if (check_winning1)
            check_winning2 = true, check_winning1 = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 'O') {
                    dfs(i, j, -1, 1);
                }
            }
        }
        if ((check_winning1 and !check_winning2 and o == x)//if O won and X lose
            or (check_winning2 and !check_winning1 and x > o) //if X won and O lose
            or (!check_winning1 and !check_winning2 and x + o == 9))// if neither X nor O won but grid is fully marked
            cout << "valid\n";// print valid
        else cout << "invalid\n";//else print invalid
        check_winning1 = false;//re-initialize global variables

    }

}
