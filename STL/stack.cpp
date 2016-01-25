//stack

#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
    stack<int> s;
    s.push(111);
    s.push(222);
    s.push(333);
    
    cout<<"s.top="<<s.top()<<endl;
    cout<<"length="<<s.size()<<endl;
    
    while(!s.empty()){
        cout<<s.top()<<",";
        s.pop();
    }
}
