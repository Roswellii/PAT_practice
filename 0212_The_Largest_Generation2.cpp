#include<bits/stdc++.h>
using namespace std;
#define maxn 110

int n, m;
int level[maxn]={0}, maxlevel= -1, maxnum= -1;
vector<int> node[maxn];//保存每一个结点的子节点情况

void dfs(int x, int l){
    level[l]+=1;
    if(level[l]> maxnum){
        maxnum= level[l];
        maxlevel= l;
    }
    //dfs访问其子结点
    for(int i=0; i<node[x].size(); i++){
        dfs(node[x][i], l+1);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int f, cn,c;
        cin >> f >> cn;
        for(int j=0; j<cn; j++){
            cin >> c;
            node[f].push_back(c);
        }
    }
    dfs(1, 1);
    cout << maxnum << " " << maxlevel;
    return 0;
}