//priority_queue

#include <iostream>
#include <queue>

using namespace std;

template<typename T> void print_queue(T q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << '\n';
}

class cp{
    public:
    bool operator()(int &a, int &b){
        return a>b;//小於:由小而大 ，大於:由大而小 ，但取出(top())時是從最後面取出 
    }
};
//或用struct
/*struct cp{
    bool operator()(int &a, int &b){
        return a<b;
    }
};*/

int main(int argc, char** argv) {
    priority_queue<int> pq;
    //priority_queue<int,vector<int>,cp> pq;//自訂順序
    //priority_queue<int,vector<int>,greater<int> > pq;//由大到小

    for(int n:{555, 222, 333, 22, 2252, 333})
        pq.push(n);

    print_queue(pq);
    cout << " pq.top = " << pq.top() << endl;
    cout << " length = " << pq.size() << endl;

    while(!pq.empty()){
        cout<<pq.top()<<",";
        pq.pop();
    }
}
