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



    deque
    push_back(x)
    pop_back(x)
    push_front()
    pop_front()
    size
    empty
    clear
    []//可用中括號存取值
    deque<int> dq;
    dq.push_back(0);
    dq.push_back(1);
    dq.push_back(2);
    cout << dq[2];  //cout << 2
}
