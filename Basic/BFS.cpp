queue<int> q;
q.push (1);
while(! q.empty())
{
    for(int j=0;j<q[i].size();j++)
    {
        if(!u[g[i][j]])
        {
        q.push(g[i][j]);
        u[g[i][j]]=1;
        
        
        }
    }
}
