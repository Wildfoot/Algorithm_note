//sort, reverse

#include <algorithm>
#include <cstdio>

using namespace std;

int cmp(int a,int b){
    return a>b;//小於:由小而大 ，大於:由大而小 
}

int main(int argc, char** argv) {
    int arr[]={9,5,88,92,7,6,50,88,754,32,1,0};
    sort(arr,arr+sizeof(arr)/sizeof(arr[0]),cmp);
    //stable_sort(arr,arr+sizeof(arr)/sizeof(arr[0]),cmp);
    //reverse(arr,arr+sizeof(arr)/sizeof(arr[0]));
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d,",arr[i]);
    }
}
