#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
namespace Genomery2D {
    const double eps = 1e-6;
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
        Point operator -=(const Point &a)
         {
            *this = *this - a;
            return *this;
        }
        friend ostream &operator<<(ostream& os, const Point &a) {
            os << "(" << a.x << ", " << a.y << ")";
            return os;
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
    };
}using namespace Genomery2D;

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

Line box[5200];
int record[5200];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    init();
    int n, m, j;
    Point left, right;
    while(II(n), n) {
        // cout << n << endl;
        memset(record, 0, sizeof record);
        //scanf("%d%lf%lf%lf%lf", &m, &left.x, &left.y, &right.x, &right.y);
        II(m);
        int tmp;
        II(tmp);
        left.x = tmp;
        II(tmp);
        left.y = tmp;
        II(tmp);
        right.x = tmp;
        II(tmp);
        right.y = tmp;
        // cin >> m >> left.x >> left.y >> right.x >> right.y;
        box[0] = {{left.x, right.y}, left};
        // cout << box[0];
        for(int i=1; i<=n; ++i) {
            // cin >> box[i].b.x >> box[i].a.x;
            // scanf("%lf%lf", &box[i].b.x, &box[i].a.x);
            II(tmp);
            box[i].b.x = tmp;
            II(tmp);
            box[i].a.x = tmp;
            box[i].a.y = right.y;
            box[i].b.y = left.y;
        }
        box[n+1] = {right, {right.x, left.y}};
        // cout << box[n+1];

        // for(int i=0; i<=10; ++i) {
        //     auto &t = box[i];
        //     cout << t << endl;
        // }
        // return 0;
        Point toy;
        for(int i=1; i<=m; ++i) {
            // cin >> toy.x >> toy.y;
            // scanf("%lf%lf", &toy.x, &toy.y);
            II(tmp);
            toy.x = tmp;
            II(tmp);
            toy.y = tmp;
            int front = 0;
            int rear = n+1;

            while(front <= rear) {
                int mid = (front+rear) >> 1;
                // double ans = box[front].Cross(toy);
                // cout << ans << endl;
                if(box[front].Cross(toy)>0 && box[mid].Cross(toy)<0) {
                    // cout << box[front] << endl;
                    // cout << box[mid] << endl;
                    // cout << toy << endl;
                    // // return 0;
                    // cout << box[front].Cross(toy) << "\n" << box[mid].Cross(toy) << endl;
                    // return 0;
                    if(mid == front+1) {
                        record[front]++;
                        // cout << front << ":::test" << endl;
                        break;
                    }
                    rear = mid;
                    continue;
                } else {
                    if(mid+1 == rear) {
                        record[mid]++;
                        // cout << mid << ":::test" << endl;
                        break;
                    }
                    front = mid;
                    continue;
                }

            }
        }
        for(int i=0; i<=n; ++i)
            // printf("%d: %d\n", i, record[i]);
            cout << i << ": " << record[i] << endl;
        cout << endl;
        // printf("\n");
    }
    return 0;
}
