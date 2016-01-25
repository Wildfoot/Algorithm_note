//map

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    map<string,int> m;
    
    m.clear();//清除全部 
    
    m["b"]=22;
    m["a"]=21;
    m["c"]=33;
    m.insert(make_pair("abb",99));
    m.insert(pair<string,int>("bbb",56));
    
    cout << m["abb"] << endl;
    
    map<string,int>::iterator iter;
    for(iter=m.begin();iter!=m.end();iter++){
        cout << iter->first << ":" << iter->second << ", ";
    }
    cout<<endl;
    
    cout<<(m.find("k")!=m.end())<<endl;//如果找不到傳回map.end()
    cout<<m.count("k")<<endl;//找到傳回1，找不到傳回0 
    cout<< m.find("a")->second << endl;
    cout<<m["k"]<<endl;//沒有k，傳回0
    
    //移除
    m.erase("b");
    //或者
    /*iter = m.find("b");
    m.erase (iter);*/
    
    cout<<m.empty()<<endl;
    cout<<"length="<<m.size()<<endl;
}
