//set

#include <iostream>
#include <set>

using namespace std;

int main(int argc, char** argv) {
    set<int> s;
    s.clear();
    
    s.insert(123);
    s.insert(456);
    s.insert(99);
    s.insert(4);
    s.insert(999);
    s.insert(999); //重複輸入沒用，用multiset才有用 
    
    cout<<s.empty()<<endl;
    cout<<s.size()<<endl;
    
    if(s.find(456) == s.end())
        cout << "Not found " << endl;
    else
        cout << "Found 456" << endl;
    
    cout<<s.erase(456)<<endl;//找到456傳回1，找不到傳回0 
    //s.erase(s.find(456));
    
    set<int>::iterator iter;
    for(iter=s.begin();iter!=s.end();iter++){
        cout<<*iter<<", ";
    }
    cout<<endl;
}
