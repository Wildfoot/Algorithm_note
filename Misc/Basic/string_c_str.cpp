
// By KRT girl xiplus
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(){
    fstream filein;
    string filename;
    cin>>filename;
    filename+=".txt";
    cout<<"open file "<<filename<<endl;
    filein.open(filename.c_str(),fstream::in);
    string s;
    while(filein>>s){
        cout<<"Hello, "<<s<<"!"<<endl;
    }
}
