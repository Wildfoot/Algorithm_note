#include <iostream>

using namespace std;

struct Date {
    Date(int i, int j,int k) : day(i), month(j), year(k){}

    int month;
    int day;
    int year;
};

int main()
{
    Date mydate(1,1,1900);
    mydate.month = 2;
    cout << mydate.month << "/" << mydate.day << "/" << mydate.year << endl;

    Date *mydate2 = new Date(1,1,2000);
    mydate2->month = 2;
    cout << mydate2->month << "/" << mydate2->day << "/" << mydate2->year << endl;

    Date *mydate3 = &mydate;
    mydate3->year = 2100;
    cout << mydate3->month << "/" << mydate3->day << "/" << mydate3->year << endl;
    
    cout << " mydate. year = " << mydate.year ;
    cout << "\t&mydate  .year = " << &mydate.year ;
    cout << "\t &mydate = " << &mydate << endl;
    
    cout << "mydate3->year = " << mydate3->year ;
    cout << "\t&mydate3->year = " << &mydate3->year ;
    cout << "\t&mydate3 = " << &mydate3 << endl;
    
    delete mydate2;
}
