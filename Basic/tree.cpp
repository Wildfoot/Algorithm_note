
int edge[500000][26];
int count[500000];

int p=0;

int root;

int newNode(){
    int ind = p;
    p++;
    for(int i=0;i<26; i++)
        edge[ind][i] = -1;
    count[ind] = 0;
    return ind;
}

root = newNode();

char str[30];

for(int i=0, where=root; i<len; i++){
    if(edge[where][ str[i]-'a' ] == -1) edge[where][str[i]-'a'] = newNode();
    where = edge[where][str[i]-'a'];
}
count[where]++;
