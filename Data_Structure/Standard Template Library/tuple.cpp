tuple<int,int,int,int> T;
T = make_tuple(1,2,3,4);
int a,b,c,d;
tie(a,b,c,d) = T
c = get<2>(T);
