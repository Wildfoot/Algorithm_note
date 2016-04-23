// By KRT girl xiplus
#include <fstream>
#include <cstring>
using namespace std;
int main(){
    fstream filein,fileout;
    filein.open("in.txt",fstream::in);
    fileout.open("out.txt",fstream::out);
    string s;
    while(filein>>s){                       //從in.txt讀入
        fileout<<"Hello, "<<s<<"!"<<endl;   //輸出out.txt
    }
}
