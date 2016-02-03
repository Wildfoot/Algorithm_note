
//鄰接矩陣
edge[i][j]      //定義i -> j有/無邊  有 = true or 權重   空間O(n ^ 2) 

    //開List 紀錄點可以連到什麼點
    //vector        有權重時可用pair
    push_back() //加入元素
    
    typedef pair<int,int> pii;
    vector<pii> V[10];

    int M,s,e,w;
    cin >> M;
    while(M--)
    {
        cin >> s >> e >> w;
        V[s].push_back(make_pair(e,w));
    }

//example
//ZJa290

