// By KRT girl xiplus
// http://t...content-available-to-author-only...s.org/oj/pro/37/
#include<iostream>
#include<sstream>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        int ans=0;
        stringstream ss(s);     //string 附值方法
        //stringstream ss;
        //ss << s;
        int t;
        while(ss>>t){
            ans++;
        }
        cout<<ans<<endl;
    }
}
