//simple
#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{    
    double x,upper,lower=0,N,temp;    
    cin >> x;   
    upper = x;
    N = (upper + lower) / 2;
    temp = N * N;
    while( !((temp - x < 0.00001) && (x - temp < 0.00001)))
    {
        
        N = (upper + lower)/2;
        temp = N * N;
        cout << "u " << upper << " m " << N << " l " << lower <<" temp " <<temp<< endl;
        if(temp > x)
        {
            upper = N;
        }
        else
        {
            lower = N;
        }
    }
    cout << fixed << setprecision (5)<< N;
    return 0;
}
