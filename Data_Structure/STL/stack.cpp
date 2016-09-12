//stack

#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
    stack<int> s;
    s.push(111);        //O(1)
    s.push(222);
    s.push(333);
    
    cout<<"s.top="<<s.top()<<endl;      //O(1)
    cout<<"length="<<s.size()<<endl;    //O(1)
    
    while(!s.empty()){
        cout<<s.top()<<",";
        s.pop();
    }
    s.empty(); // O(1)
}
