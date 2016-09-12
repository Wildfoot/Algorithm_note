/*  alogorithm Andrew
 *
 *
 *
 *              Wildfoot
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0):x(x), y(y) {}
    bool operator < (const Point& rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

typedef Point Vector;

Vector operator + (Vector A,Vector B) {return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Point A,Point B) {return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double t) {return Vector(A.x*t,A.y*t);}
Vector operator / (Vector A,double t) {return Vector(A.x/t,A.y/t);}

typedef vector<Point> Polygon;

double Cross(Vector A, Vector B)
{
    return A.x * B.y - A.y * B.x;
}

Polygon ANS;

int ConvexHull(Point p[],int n)
{
    sort(p, p + n);
    ANS.clear();
    ANS.push_back(p[0]);
    int str = 1;
    for(int i = 1;i < n;i++)
    {
        if(Cross(ANS[str - 1] - ANS[str - 2], p[i] - ANS[str - 1]) > 0 || str == 1)     //Cross > 0 => 左轉 
        {
            ANS.push_back(p[i]);    str++;
        }
        else
        {
            ANS.pop_back(); str--;
            i--;
            continue;
        }
    }
    for(int i = n - 1, tstr = str;i >= 0;i--)   //tstr => 不刪到原本的下凸包
    {
        if(Cross(ANS[str - 1] - ANS[str - 2], p[i] - ANS[str - 1]) > 0 || str == tstr)     //Cross > 0 => 左轉 
        {
            ANS.push_back(p[i]);    str++;
        }
        else
        {
            ANS.pop_back(); str--;
            i++;
            continue;
        }
    }
    ANS.pop_back();
    for(int i = 0, tstr = str;i < ANS.size();i++)
    {
        cout << ANS[i].x << ", " << ANS[i].y << endl;
    }

    return 0;
}

int main()
{
    int n;
    while(cin >> n)
    {
        Point p[n];
        for(int i = 0;i < n;i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        cout << "= = = = = = = = = =" << endl;
        ConvexHull(p, n);
    
    }
    return 0;
}
