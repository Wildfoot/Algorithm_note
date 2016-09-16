#include <iostream>
#define sum 10
using namespace std;
//O(nlogn)

int buf[sum];
void merge(int l,int r,int arr[])
{
    if(l == r)
        return;
    int m = (r + l) / 2;
    merge(l, m, arr);
    merge(m + 1, r, arr);
    //l ~ m     m+1 ~ r
    int lptr = l, rptr = m + 1, ptr = l;
    while(lptr < m + 1 || rptr < r + 1)
    {
        while(lptr < m + 1 && rptr < r + 1)
        {
            if(arr[lptr] > arr[rptr])
            {
                buf[ptr] = arr[rptr];
                rptr++;     ptr++;
            }
            else
            {
                buf[ptr] = arr[lptr];
                lptr++;     ptr++;
            }
        }
        if(lptr < m + 1)
        {
            buf[ptr] = arr[lptr];
            lptr++;     ptr++;
        }
        else
        {
            buf[ptr] = arr[rptr];
            rptr++;     ptr++;
        }
    }
    for(int i = l;i <= r;i++)
    {
        arr[i] = buf[i];
    }
}
int main()
{
    int arr[sum];
    for(int i = 0;i < sum;i++)
        cin >> arr[i];
    merge(0,sum - 1,arr);
    for(int i = 0;i < sum;i++)
        cout << buf[i] << " ";
}
/*void merge(int l,int r,int arr[])
{
    if(l == r)
        return;
    int m = (l + r) / 2;
    merge(l,m,arr);
    merge(m + 1,r,arr);
    /*$//////////////////////////////////////////////////////////////
    int lptr = l,rptr = m + 1;
    while(lptr < m + 1 || rptr <= r)
    {
        if(lptr < m + 1 && rptr <= r)
        {
            if(arr[lptr] < arr[rptr])
            {
                buf[lptr - l + rptr - m - 1] = arr[lptr];
                lptr++;
            }
        }
    }
    for(int i = 0;i < r - 1 +1;i++)
    {
        arr[l + i] = buf[i];
    }
}*/

