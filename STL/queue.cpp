//queue

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
    queue<int> q;
    q.push(111);
    q.push(222);
    q.push(333);
    
    cout<<"q.front="<<q.front()<<",q.back="<<q.back()<<endl;
    cout<<"length="<<q.size()<<endl;
    
    while(!q.empty()){
        cout<<q.front()<<",";
        q.pop();
    }
}
