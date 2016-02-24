
//Mersenne Twister
//MT 19937
//
#include <random>

main{
    mt19937 mt(156);
    cout << mt.min() << ' ' << mt.max() << endl;
    for(int i = 0;i < 10;++i)
        cout << mt() << ' ';
}



//Las Vegas algorithm
//可能快可能慢 0錯誤機率

//random_shuffle(vec.begin(),vec.end(),亂數產生器)
//
//Mpmte Carlo algorithm
//有錯誤率 一定時間內跑出來（不一定正確）

