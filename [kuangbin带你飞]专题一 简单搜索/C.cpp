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
#pragma comment(linker, "/STACK:1024000000,1024000000")     //ÊÖ¶¯À©Õ»
typedef long long LL;
#define INF = 0x3f3f3f3f;
#define eps 1e-10
#define ff(a, b, c, d) for(int a=b; a<c; a+=d)
#define fff(a, b, c, d) for(int a=b; a>=c; a-=d)
#define mm(a, b)       memset(a, b, sizeof(a))
const double PIE = acos(-1.0);


const int N = 100000+50;
int n;
bool vis[N] = {false};;
typedef struct node{
    int n;
    int cnt;

    node() {}
    node(int _n, int _cnt):n(_n),cnt(_cnt) {}
};
bool check(int x) {
    if(x<0 || x>N)
        return false;
    return !vis[x];
}
int bfs(int n, int k) {
    queue< node > q;
    q.push({n, 0});

    while(!q.empty()) {
        node now = q.front();
        q.pop();

        if(now.n == k)
            return now.cnt;
        ff(i, 0, 3, 1) {
            int tmp;
            if(i==0)
                tmp = now.n + 1;
            else if(i==1)
                tmp = now.n - 1;
            else tmp = now.n * 2;
            if( !check(tmp) )
                continue;
            node next = {tmp, now.cnt+1};
            q.push(next);
            vis[tmp] = true;
        }
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if(n>=k)
        cout << n-k << "\n";
    else
        cout << bfs(n, k) << "\n";
    return 0;
}
