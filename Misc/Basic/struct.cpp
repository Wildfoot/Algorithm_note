struct student{              // = class public
    int id;
    string name;

    student(){          //初始化
        id = 123;
        name = "none";
    }
    student(int _id){     //參數
        id = _id;
        name = "id def";
    }
}

bool operator < (const student &a,const student &b)//定義<再student的意義
{
    return a.id < b.id;
}

int main()
{
    student A;
    cout << A.id << " "<< A.name << endl;
    student B(15); //加參數
    cout << B.id << " "<< B.name << endl;
    set<student> v;//一定要定義小於  不然比較會壞掉
    
}
