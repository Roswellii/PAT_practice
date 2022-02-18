#include<bits\stdc++.h>
#define maxn 250
#define inf 1e9
using namespace std;

//paras
int g[maxn][maxn], hp[maxn];
int n, k;
//dij
bool visited[maxn];
int dis[maxn];
vector<int> pre[maxn];
//path
vector<int> tpath, path;
int c_path= 0;
//compare
int max_hp, max_avghp;
//cities
map<string, int> m;
map<int, string> m2;

void dfs(int v){
    tpath.push_back(v);
    //return
    if(v==1){
        int total_hp= 0;
        for(int i=0; i<tpath.size(); i++){
            total_hp+= hp[tpath[i]];
        }
        double avg_hp= total_hp/(1.0* (tpath.size()-1));
        if(total_hp> max_hp){
            max_hp= total_hp;
            path= tpath;
        }else if(total_hp== max_hp&& avg_hp> max_avghp){
            max_hp= total_hp;
            path= tpath;
        }
        c_path+=1;
        tpath.pop_back();
        return;
    }
    //dfs
    for(int i=0; i<pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    tpath.pop_back();
    return;
}


void dij(){
    dis[1]= 0;
    for(int i=0; i<n; i++){
        int u= -1;
        int min_d= inf;
        
        //? find min_d cit
        for(int j=0; j<n; j++){
            if(dis[j]< min_d){
                min_d= dis[j];
                u= j;
            }
        }
        //@ 
        if(u== -1) break;
        //? update distance
        visited[u]= 1;
        for(int v=1; v<=n; v++){
            if(dis[v]> dis[u]+ g[u][v]){
                pre[v].clear();
                pre[v].push_back(u);
                dis[v]=  dis[u]+ g[u][v];
            }else if(dis[v]== dis[u]+ g[u][v]){
                pre[v].push_back(u);
            }
        }

    }
}

int main(){
    //init
    fill(dis, dis+ maxn, inf);
    fill(g[0], g[0]+ maxn* maxn, inf);
    //input
    string s;
    scanf("%d %d", &n, &k);
    cin >> s; 
    m[s]= 1;
    m2[1]= s;
    //? input hp
    for(int i=2; i<=n; i++){
        string c;
        int thp;
        cin >> c;
        scanf("%d", &thp);
        hp[i]= thp;
        m[c]= i;
        m2[i]= c;
    }
    //? input roads
    for(int i=0; i<k; i++){
        string x, y;
        int cost;
        cin >> x >> y;
        scanf("%d", &cost);
        g[m[x]][m[y]]= cost;
        g[m[y]][m[x]]= cost;
    }
    //---
    dij();
    dfs(m["ROM"]);
    //result
    cout << c_path << " " << dis[m["ROM"]]<< " "<< max_hp << " " << max_avghp << endl;
    for(int i=path.size()-1; i>0; i--){
        cout << m2[path[i]]<< "->";
    }
    cout << "ROM";
    return 0;
}
