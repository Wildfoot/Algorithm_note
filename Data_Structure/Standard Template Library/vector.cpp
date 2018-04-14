// vector

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    vector<int> v;
    v.clear();

    for(int n : {11, 22, 22,  99, 11, 22})
        v.push_back(n);

    v.insert(v.begin()+1, 1);
    v.pop_back();

    /////////////// print all item ////////////////////////
    vector<int>::iterator iter;
    for(iter=v.begin();iter!=v.end();iter++){
        cout << *iter << ", ";
    }
    cout<<endl;

    for(int i=0; i < v.size() ; i++){
        cout << v[i] << ", ";
    }

    cout<<endl;

    for(int i:v)
    {
        cout << i << ", ";
    }
    cout << endl;
    ///////////////////////////////////////////////////////

    cout << "v.empty() = " << v.empty() << endl;

    v.reserve(50);//保留空間
    cout << "v.size() = " << v.size() << endl;//6
    cout << "v.capacity() = " << v.capacity() << endl;//50

    v.resize(50, 123);//小於原來大小，會刪掉多餘元素，大於原來大小會補123(如果沒寫就補0)

    cout << v.front() << v.back() << endl;//最前和最後一筆資料
    v.back(); //O(1)
    v.size(); //O(1)
    v.clear(); //O(n)

    v.erase(v.begin()+3);
    v.erase(v.begin()+3, v.begin()+6);
}
