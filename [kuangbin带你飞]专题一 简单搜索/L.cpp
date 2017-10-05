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


int ans = 0;
int n, m;
char maps[105][105];


namespace Search2D {
    struct point {
        int x, y;

        point() {}
        point(int _x, int _y):x(_x), y(_y) {}
        friend ostream &operator<<(ostream &os, const point &a) {
            os << "(" << a.x << ", " << a.y << ")";
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
    bool check(point x) {
        if(x.x<0 || x.x>=m || x.y<0 || x.y>=n)
            return false;
        return maps[x.x][x.y] == '@';
    }

    point path[5][5];
    point end(0, 0);
    void BFS(point start) {
        queue<point> q;
        mm(path, 0);
        q.push(start);
        maps[start.x][start.y] = 1;
        path[start.x][start.y] = {-1, -1};

        while(!q.empty()) {
            point now = q.front();
            q.pop();


            for(int i=0; i<4; ++i) {
                point tmp = now;
                tmp += dis[i];
                if(!check(tmp))
                    continue;
                maps[tmp.x][tmp.y] = 1;
                q.push(tmp);
                path[tmp.x][tmp.y] = now;
                if(tmp.x==end.x && tmp.y==end.y)
                    return;
            }
        }
    }
    point dfs_dis[8] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1},
                        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    void DFS(int x, int y) {
        point now = {x, y};
        maps[x][y] = '*';
        for(int i=0; i<8; ++i) {
            point tmp(now);
            tmp+=dfs_dis[i];
            if(!check(tmp))
                continue;
            DFS(tmp.x, tmp.y);
        }
    }
}using namespace Search2D;


int main() {
    ios::sync_with_stdio(false);
    filein();
    while(cin >> m >> n, m+n) {
        mm(maps, 0);
        int cnt = 0;
        ff(i, 0, m, 1) {
            ff(j, 0, n, 1) {
                cin >> maps[i][j];
            }
        }
        // ff(i, 0, m, 1) {
        //     ff(j, 0, n, 1) {
        //         cout << maps[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        ff(i, 0, m, 1) {
            ff(j, 0, n, 1) {
                if(maps[i][j]=='@') {
                    cnt++;
                    DFS(i, j);
                }

            }
        }
        cout << cnt << endl;
    }
    return 0;
}