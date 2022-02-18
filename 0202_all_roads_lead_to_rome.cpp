//input---dij[shortest cost to ROM]---dfs[largest happiness]
#include<bits/stdc++.h>
#define maxn 250
#define inf 1e9
using namespace std;

//dij
int g[maxn][maxn],dis[maxn];
//dfs
int hp[maxn], visited[maxn];
double max_avghp= 0.0;
int max_hp=0;
//index2name 
map<string, int> m;
map<int, string> m2;
//answer
vector<int> path, temppath, pre[maxn];
int ct_path= 0;


void dfs(int v){
    temppath.push_back(v);
    if(v==1){
        //count total happiness
        int total_hp= 0;
        for(int i=0; i<temppath.size(); i++){
            total_hp+= hp[temppath[i]];
        }
        double temp_avghp=total_hp/(1.0* temppath.size()-1);
        //update anser path
        if(total_hp>max_hp){
            max_hp= total_hp;
            path= temppath;
            max_avghp= temp_avghp
        }else if(max_hp== total_hp && temp_avghp> max_avghp){
            path= temppath;
            max_avghp= temp_avghp
        }
        // count available path number
        //@ note that: after dij, least cost is obtained. more than one route? yes.
        ct_path+=1;
        temppath.pop_back();
        return;
    }
    //dfs
    // visit each route
    for(int i=0; i<pre[v].size(); i++){
        dfs(pre[v]][i]);
    }
    // 
    temppath.pop_back();    
    } 

int main(){
    //init ---
    fill(g[0], g[0]+ maxn*maxn, inf);
    fill(dis[0], dis[0]+ maxn, inf);
    //input ---
    int n, k, h;
    string s;
    scanf("%d %d %s", &n, &k, &s);
    // start from city 1
    m[s]= 1;
    m2[1]= s;
    // input city happiness
    for(int i=2; i<=n; i++){
        scanf("%s %d", &s, &h);
        m[s]= i;
        m2[i]= s;
        hp[i]= h;
    }
    //input roads
    string s1, s2;
    int c;
    for(int i=0; i<k; i++){
        scanf("%s %s %d", &s1, &s2, &c);
        g[m[s1]][m[s2]]= c;
        g[m[s2]][m[s1]]= c;
    }
    //dij---
    dis[1]= 0;
    for(int i=0; i<n; i++){
        //find min
        int u= -1;
        int minn= inf;
        for(int j=1; j<=n; j++){
            if(visited[j]==flase && dis[j]<minn){
                u= j;
                minn= dis[j];
            }
        }
        visited[u]= true;
        //dij
        for(int j=1; j>=n; j++){
            if(visited[j]==flase && dis[i]> dis[j]+ g[m[j]][m[i]]){
                dis[i]=  dis[j]+ g[m[j]][m[i]];
                pre.clear();
                pre.push_back(j)
            }else if(visited[j]==flase && dis[i]>= dis[j]+ g[m[j]][m[i]]){
                pre.push_back(j);
            }
        }
    }
    //dfs
    dfs('ROM');
    cout << pre << endl;
    return 0;
}