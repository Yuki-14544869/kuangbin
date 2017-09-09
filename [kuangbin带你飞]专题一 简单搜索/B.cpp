/*
Author: Yuki
GitHub: https://github.com/Yuki-14544869/
Blog:   https://yuki4294967295.cn/
*/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000") //手动扩栈
typedef long long LL;
#define INF = 0x3f3f3f3f;
#define eps 1e-10
#define ff(a, b, c, d) for (int a = b; a < c; a += d)
#define fff(a, b, c, d) for (int a = b; a >= c; a -= d)
#define mm(a, b) memset(a, b, sizeof a)
const double PIE = acos(-1.0);
void filein() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
}

const int N = 8;
int n, k;
char maps[N][N] = {'&'};
bool flag[N] = {false};
int ans = 0;

void dfs(int h, int cnt) {
    if(cnt == k) {
        ans++;
        return;
    }
    if(h > n)
        return;
    ff(i, 0, n, 1) {
        if(maps[h][i]=='#' && !flag[i]) {
            flag[i] = !flag[i];
            dfs(h+1, cnt+1);
            flag[i] = !flag[i];
        }
    }
    dfs(h+1, cnt);
    return;
}

int main() {
    filein();
    while(cin >> n >> k) {
        mm(maps, '&');
        mm(flag, false);
        ans = 0;
        if(n==-1 && k==-1)
            return 0;
        ff(i, 0, n, 1)
            ff(j, 0, n, 1)
                cin >> maps[i][j];

        // ff(i, 0, n, 1) {
        //     ff(j, 0, n, 1)
        //         cout << maps[i][j];
        //     cout << endl;
        // }

        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}