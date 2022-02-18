#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
const int inf =1e9;
//?
int e[205][205], weight[205], dis[205];
bool visit[205];
vector<int> pre[205], temppath, path;
map<string, int> m;
map<int, string> m2;
int maxvalue= 0, mindepth, cntpath= 0;
double maxavg;

// find max happiness
void dfs(int v){
    temppath.push_back(v);
    
    // retun
    if(v==1){ // path start from city 1s
        // dfs terminate, count happiness
        int value= 0;
        for(int i=0; i< temppath.size(); i++){
            value+= weight[temppath[i]];
        }
        // update happiness
        double tempavg= 1.0* value/ (temppath.size()-1);
        if(value> maxvalue){
            maxvalue= value;
            maxavg= tempavg;
            path= temppath;
        }else if(value== maxvalue && tempavg> maxavg){
            maxavg= tempavg;
            path= temppath;
        }
        temppath.pop_back();//@ must pop this node
        cntpath++; 
        return; 
    }
    // dfs
    //@ note that pre[v] is an array. each component capitalized one route. 
    for(int i=0; i<pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}


//find shortest distance
int main(){
    //initialize
    fill(e[0], e[0]+ 205* 205, inf);
    fill(dis, dis+205, inf);
    //input para
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    m[s]= 1;
    m2[1]= s;
    // input cities
    for(int i=1;i<n; i++){
        cin >> s >> weight[i+1];
        m[s]= i+1;
        m2[i+1]= s;
    }
    //input roads
    string sa, sb;
    int temp;
    for(int i=0; i<k; i++){
        cin >> sa >> sb >> temp;
        e[m[sa]][m[sb]]= temp;
        e[m[sb]][m[sa]]= temp;
    }
    // dij
    dis[1]= 0;
    for(int i=0; i<n; i++){
        int u= -1; //? 
        int minn= inf;
        //find the closest node
        for(int j=1; j<=n; j++){
            if(visit[j]==false && dis[j]< minn){
                u= j;
                minn= dis[j];
            }
        }
        // then visit it
        //@ no city available
        if(u ==-1){
            break;
        }
        visit[u]= true;
        // update node distance by loosing
        for(int v=1; v<=n; v++){
            if(visit[v]== false && e[u][v]!= inf){
                // better route, update distance and pre
                if(dis[u]+ e[u][v]< dis[v]){
                    dis[v]= dis[u]+ e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[v]== dis[u]+ e[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    //dfs
    int rom= m["ROM"];
    dfs(rom); //start from ROM
    // output result
    printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
    for(int i= path.size()-1; i>=1; i--){
        cout << m2[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}