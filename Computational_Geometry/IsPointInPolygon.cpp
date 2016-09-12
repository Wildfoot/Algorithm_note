#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point        //點
{
    double x, y;
    Point(double x = 0,double y = 0): x(x), y(y) {}
};

typedef Point Vector;   //向量

Vector operator + (Vector A,Vector B) {return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Point A,Point B) {return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double t) {return Vector(A.x*t,A.y*t);}
Vector operator / (Vector A,double t) {return Vector(A.x/t,A.y/t);}

double Dot(Vector A,Vector B) {return A.x * B.x + A.y * B.y;}

double Length(Vector A) {return sqrt(Dot(A,A));} // sqrt(A.x*A.x + A.y*A.y)

double getangle(Vector A,Vector B) {return acos( Dot(A,B)/Length(A)/Length(B)  );}

double Cross(Vector A,Vector B) {return A.x*B.y - A.y*B.x;}

double Area(Point A,Point B,Point C) {return Cross(B-A,C-A) / 2.0;}

typedef vector<Point> Polygon;  //頂點按照逆時針存下

bool IsPointOnSegment(Point P,Point A,Point B)
{
    return Cross(P-A,P-B) == 0 && Dot(P-A,P-B) <= 0;
}

int IsPointInPolygon(Point p,Polygon poly)
{
    int n = poly.size();
    int wn = 0;
    for(int i = 0;i < n;i++)
    {
        int d1 = poly[i].y - p.y;
        int d2 = poly[(i + 1) % n].y - p.y;
        if(IsPointOnSegment(p,poly[i],poly[(i+1)%n])) return -1; // 邊上
        int k = Cross( poly[(i+1)%n] - poly[i] , p - poly[i] );
        if(k > 0 && d1<=0 && d2>0) wn++; //逆時針穿過，繞數+1
        if(k < 0 && d1>0 && d2<=0) wn--; //順時針穿過，繞數-1
    }
    return wn!=0;
}

int main()
{
    int n;
    Point p;
    Polygon a;
    while(cin >> n)
    {
        a.clear();
        while(n--)
        {
            Point t;
            cin >> t.x >> t.y;
            a.push_back(t);
        }
        cin >> p.x >> p.y;
        cout << IsPointInPolygon(p, a) << endl;
    }
    return 0;
}
