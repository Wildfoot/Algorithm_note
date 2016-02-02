

int a[5] = {1,5,2,3,4};
//c++ lambda
sort(a, a+5 , [](int a,int b)
{
    a = a * 10 % 3;
    b = b * 10 % 3;
    return a < b;
});

//lower_bound >= k
//upper_bound >k
//
cout << *lower_bound(v.begin(),v.end(),6) << endl;
cout << lower_bound(v.begin(),v.end(),6) - v.begin() << endl; //位址
cout << *upper_bound(v.begin(),v.end(),6) << endl;


cout << *max_element(a,a+5) << endl;
cout << max_element(a,a+5) - a << endl; //位址

int a[7] = { 1,2,3,4,5,5,5 };
cout << count(a,a+7,5) << endl;

int a[4] = {1,2,3,4};
do{
    for(int i:a)
        cout << i << " ";
    cout << endl;
}while( next_permutation(a,a+4) );


int a[7] = {1,2,3,5,5,5,4}
reverse(a,a+7)
for(int i:a)cout << i <<" ";

replace(c,c+6,5,10); //5 -> 10
