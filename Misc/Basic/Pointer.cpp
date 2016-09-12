#include <iostream>

using namespace std;

int main()
{
    int n1 = 1, n2 = 2;
    int *p = &n1;
    int **p2 = &p;

    cout << " n1 = " << n1 ;
    //cout << "*n1 = " << *n1 << endl;
    cout << "\t\t\t\t\t\t&n1 = " << &n1 << endl;

    cout << "  p = " << p ;
    cout << "\t *p = " << *p ;
    cout << "\t\t\t &p = " << &p << endl;
  
    cout << " p2 = " << p2 ;
    cout << "\t*p2 = " << *p2 ;
    cout << "\t&p2 = " << &p2 << endl;

    cout << endl << "\t\t\t\tp++" << endl;
    p++;

    cout << " n1 = " << n1 ;
    //cout << "*n1 = " << *n1 << endl;
    cout << "\t\t\t\t\t\t&n1 = " << &n1 << endl;
    
    cout << " n2 = " << n2 ;
    //cout << "*n1 = " << *n1 << endl;
    cout << "\t\t\t\t\t\t&n2 = " << &n2 << endl;

    cout << "  p = " << p ;
    cout << "\t *p = " << *p ;
    cout << "\t\t\t &p = " << &p << endl;
  
    cout << " p2 = " << p2 ;
    cout << "\t*p2 = " << *p2 ;
    cout << "\t&p2 = " << &p2 << endl;

 }
