#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y) {}
    bool operator < (const Point& rhs) const {return x<rhs.x || (x==rhs.x && y<rhs.y);}     //水平序排序
};


typedef Point Vector;   //向量

// Vector + Vector = Vector
Vector operator + (Vector A,Vector B) {return Vector(A.x+B.x,A.y+B.y);}
// Point - Point = Vector
Vector operator - (Point A,Point B) {return Vector(A.x-B.x,A.y-B.y);}
// Vector * num = Vector
Vector operator * (Vector A,double t) {return Vector(A.x*t,A.y*t);}
// Vector / num = Vector
Vector operator / (Vector A,double t) {return Vector(A.x/t,A.y/t);}

double Dot(Vector A,Vector B) {return A.x * B.x + A.y * B.y;}

double Length(Vector A) {return sqrt(Dot(A,A));} // sqrt(A.x*A.x + A.y*A.y)

double getangle(Vector A,Vector B) {return acos( Dot(A,B)/Length(A)/Length(B)  );}

double Cross(Vector A,Vector B) {return A.x*B.y - A.y*B.x;}

double Area(Point A,Point B,Point C) {return Cross(B-A,C-A) / 2.0;}

struct Line
{
    Point p;
    Vector v;
    double ang;
    Line(Point p,Vector v):p(p),v(v) {ang=atan2(v.y,v.x);}
    //atan * 180 / PI = 角度
};

typedef vector<Point> Polygon;  //頂點按照逆時針存下

struct Circle
{
    Point c;
    double r;
    Circle(Point c,double r=0):c(c),r(r) {}
};


// Andrew
// 回傳凸包頂點數量
int ConvexHull(Point* p,int n,Point* ch)
{
    sort(p,p+n);
    int m=0;
    // 下凸包
    for(int i=0;i<n;i++)
    {
        while(m > 1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <=0 ) m--;
        ch[m++]=p[i];
    }
    int k=m;
    // 上凸包
    for(int i=n-2;i>=0;i--)
    {
        while(m > k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <=0 ) m--;
        ch[m++]=p[i];
    }
    // 注意p[0]會重複選到
    if(n>1) m--;
    return m;
}

int main()
{
    return 0;
}
