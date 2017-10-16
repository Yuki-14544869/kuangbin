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

namespace Genomery2D {
    const double eps = 1e-8;
    int sgn(double x) {
        if(fabs(x) < eps)
            return 0;
        if(x < 0)
            return -1;
        return 1;
    }

    struct Point {
        double x, y;
        Point(){}
        Point(double _x, double _y) : x(_x), y(_y) {}

        Point operator -(const Point &a)const {
            return Point(x-a.x, y-a.y);
        }
        Point operator +(const Point &a)const {
            return Point(x+a.x, y+a.y);
        }
        double operator *(const Point &a)const {
            return x*a.x + y*a.y;
        }
        double operator ^(const Point &a)const {
            return x*a.y + y*a.x;
        }
        Point operator +=(const Point &a) {
            *this = *this + a;
            return *this;
        }
        Point operator -=(const Point &a) {
            *this = *this - a;
            return *this;
        }
        friend ostream &operator<<(ostream& os, const Point &a) {
            os << "(" << a.x << ", " << a.y << ")";
            return os;
        }
        double dist(Point &b) {                        //两点间距
            Point temp = *this-b;
            return sqrt(temp*temp);
        }

    };

    struct Vector {
        double x, y;
        Vector() {}
        Vector(double _x, double _y) :  x(_x), y(_y) {}
        Vector(Point s, Point e) : x(e.x-s.x), y(e.y-s.y) {}

        double operator ^(const Vector &a) const {            //向量叉积
            return x*a.y - y*a.x;
        }
    };

    struct Line {
        Point a, b;
        Line() {}
        Line(Point _a, Point _b) : a(_a), b(_b) {}

        friend ostream &operator<<(ostream& os, const Line &a) {
            os << "{(" << a.a.x << ", " << a.a.y << "), ("
                << a.b.x << ", " << a.b.y <<")}" << endl;
            return os;
        }
        double Cross(const Point& p) const {                    //线段与点的位置关系
            Vector tmpa(this->a, this->b);                   //大于0顺时针，小于0逆时针，等于0在线段上
            Vector tmpb(this->a, p);                         //两个向量分别为line::a->line::b & line::a->p
            return tmpb ^ tmpa;
        }
        bool JudgeCross(Line l) {                           //判断this的线段所在的直线是否与线段l相交
            return sgn((*this).Cross(l.a)) * sgn((*this).Cross(l.b)) <= 0;
        }
    };
}using namespace Genomery2D;

double ans;
Line line[110];

bool check(Line l, int n) {
    if(sgn(l.a.dist(l.b)) == 0)
        return false;
    for(int i=0; i<n; ++i) {
        if(!l.JudgeCross(line[i]))
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    filein();
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);

        double x1, x2, y1, y2;
        for(int i=0; i<n; ++i) {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            line[i] = {{x1, y1}, {x2, y2}};
        }
        bool flag = false;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(check(Line(line[i].a, line[j].a), n) || check(Line(line[i].a, line[j].b), n)
                    || check(Line(line[i].b, line[j].a), n) || check(Line(line[i].b, line[j].b), n)) {
                        flag = true;
                        break;
                }
                if(flag)
                    printf("Yes!\n");
                else printf("No!\n");
    }
    return 0;
}
