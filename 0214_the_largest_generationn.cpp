#include<iostream>
#include<vector>
using namespace std;
#define maxn 110

int m, n;
int l[maxn]={0};
vector<int> nd[maxn];

void dfs(int x, int level){
    l[level]+=1;
    for(int i=0; i<nd[x].size();i++){
        dfs(nd[x][i], level+1);
    }
}


int main(){
    //
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int id, k, child;
        cin >> id >> k;
        for(int j=0; j<k; j++){
            cin >> child;
            nd[id].push_back(child);
        }
    }

    //
    dfs(1, 1);
    
    //
    int maxvalue=-1, maxindex= -1;
    for(int i=0; i<maxn; i++){
        if(l[i]>maxvalue){
            maxvalue= l[i];
            maxindex= i;
        }
    }
    cout << maxvalue << " "<< maxindex<< endl;
    return 0;
}