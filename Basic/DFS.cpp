void dfs (int i)
{
   u[i]=true;
   for(int j=0;j<g[i].size();j++)
   {
       if(!u[g[i][j])
           dfs(g[i][j]);
   }
}
