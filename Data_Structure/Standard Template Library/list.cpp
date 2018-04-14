//list

#include <iostream>
#include <list>

using namespace std;

bool cmp (int a, int b){
    return a<b;
}

int main(int argc, char** argv) {
    list<int> l;
    l.clear();
    
    l.push_back(11);
    l.push_back(22);
    l.push_back(22);
    l.push_back(99);
    l.push_back(11);
    l.push_back(22);
    l.push_front(88);
    
    list<int>::iterator iter;
    for(iter=l.begin();iter!=l.end();iter++){
        cout << *iter << ", ";
    }
    cout<<endl;
    
    l.sort();
    //l.sort(cmp);
    
    l.insert(++l.begin(),1);//不能用l.begin()+1 
    l.pop_back();
    l.pop_front();
    
    //cout<<l[3]<<endl; //不能用中括號讀取(會編譯錯誤) 
    
    cout<<l.empty()<<endl;
    
    cout<<l.size()<<endl;
    
    l.resize(50,123);//小於原來大小，會刪掉多餘元素，大於原來大小會補123(如果沒寫就補0)
    
    cout<<l.front()<<l.back()<<endl;//最前和最後一筆資料
    
    l.erase(++++++l.begin());
    l.erase(++++l.begin(),----l.end()); 
    l.remove(22);//移除value為22的元素
    
    l.reverse();
    l.unique();//移除連續重複 
    
    cout<<*(--l.end());//讀取最後一筆資料，end()讀到的是最後一筆資料的下一個位置 
}
