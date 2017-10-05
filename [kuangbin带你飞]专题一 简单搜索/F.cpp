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


namespace Prime {
    const int M = 9999;
    bool visit[M];
    int prime[M];

    void table(const int x) {
        // memset(visit,true,sizeof(visit));
        // memset(prime, 0, sizeof(prime));
        for(int i=0; i<=x; ++i) {
            visit[i] = true;
            prime[i] = 0;
        }
        int num = 0;
        for (int i = 2; i <= x; ++i) {
            if (visit[i] == true) {
                num++;
                prime[num] = i;
            }
            for (int j = 1; ((j <= num) && (i * prime[j] <= M));  ++j) {
                visit[i * prime[j]] = false;
                if (i % prime[j] == 0) break; //点睛之笔
            }
        }
    }

    void print_prime() {
        table(M);
        int x;
        int tmp = 0;
        int cnt = 0;
        for(int i=1; i<5761500; ++i) {
            if(prime[i])
                cnt++;
            if(prime[i] > tmp)
                tmp = prime[i];
        }
        cout << tmp << endl ;
        cout << "total : " << cnt << endl;
    }

    void judge_prime(const int x) {
        if(visit[x])
            cout << "true" << endl;
        else cout << "no" << endl;
    }
}using namespace Prime;


int T;
int a, b;
int ans = 0;
int dp[10015];

int get_next(int number, int digit, int change) {
    switch(digit) {
        case 0:
            return number/10*10 + change;
        case 1:
            return number/100*100 + number%10 + change*10;
        case 2:
            return number/1000*1000 + number%100 + change*100;
        case 3:
            return number%1000 + change*1000;
        default :
            return 0;
    }
}
namespace Search2D {
    struct point {
        int x, y;

        point() {}
        point(int _x, int _y):x(_x), y(_y) {}
        friend ostream &operator<<(ostream &os, const point &a) {
            os << a.x << " " << a.y;
            return os;
        }
        point operator+(const point &a) {
            return point(x+a.x, y+a.y);
        }
        point operator-(const point &a) {
            return point(x-a.x, y-a.y);
        }
        point operator+=(const point &a) {
            *this = *this + a;
            return *this;
        }
    };
    //point dis[4] = {(-1,0),(0,-1),(1,0),(0,1)};
    point dis[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool flag[10] = {false};

    void BFS() {
        mm(dp, 0x3f3f3f3f);
        dp[a] = 0;
        queue<int> q;
        q.push(a);

        while(!q.empty()) {
            const int now = q.front();
            q.pop();
            if(now==b)
                return ;
            for(int i=0; i<4; ++i) {
                ff(j, 0, 10, 1) {
                    if(i==3 && j==0)
                        continue;
                    int tmp = get_next(now, i, j);
                    if(!visit[tmp] || dp[tmp]<=dp[now])
                        continue;
                    dp[tmp] = dp[now] + 1;
                    q.push(tmp);
                }
            }
        }
    }

}using namespace Search2D;


int main() {
    //ios::sync_with_stdio(false);
    filein();
    init();
    table(9999);
    II(T);
    while(T--) {
        II(a);II(b);
        // cout << a << " " << b << endl;
        BFS();
        // cout << a << " " << b << endl;
        cout << dp[b] << endl;
    }
    return 0;
}
