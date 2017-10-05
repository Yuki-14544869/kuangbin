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
#include <iomanip>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000") //手动扩栈
typedef long long LL;
#define pb push_back
#define ff(a, b, c, d) for (int a = b; a < c; a += d)
#define fff(a, b, c, d) for (int a = b; a >= c; a -= d)
#define mm(a, b) memset(a, b, sizeof a)
const double PIE = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;
namespace IO {
    const int MX = 4e7;
    char buf[MX]; int c, sz;
    void init(){
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool II(int &t){
    while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}using namespace IO;
void filein() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
}
queue<long long> q;
long long bfs(int x) {
    q.push(1);

    while(!q.empty()) {
        long long now = q.front();
        q.pop();

        if(now%x==0)
            return now;
        q.push(now * 10);
        q.push(now*10 + 1);
    }
    return 0;
}

int x;
int main() {
    ios::sync_with_stdio(false);
    filein();
    //init();
    while(cin>>x, x) {
        while(!q.empty())
            q.pop();
        cout << bfs(x) << endl;
    }

    return 0;
}