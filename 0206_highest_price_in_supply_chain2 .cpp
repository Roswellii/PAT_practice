#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

double n, p, r;
int f[maxn];
double pr[maxn];
double max_price= -999;
int num= 0;


//@ 1 目的是算出所有节点的price。 每一个结点dou'ya
double dfs(int x){
    if(f[x]!=-1) return pr[x];
    else return pr[x]=  dfs(f[x])* r; 
}

//@ 2
// double dfs(int x){
//     if(pr[x]!=-1) return pr[x];
//     else return pr[x]=  dfs(f[x])* r; 
// }


int main(){

    
    //input
    scanf("%lf %lf %lf", &n, &p, &r);
    r= r/100
    r= r+1;
    for(int i=0; i<n; i++){
        scanf("%d", f+i);
        pr[i]=  f[i]==-1? p: -1;
    }

    //tree
    dfs(0);
   

    //count
    for(int i=0; i<n; i++){
        if(pr[i]>max_price){
             max_price= pr[i];
             num= 1;
        }else if(pr[i]==max_price){
            num+=1;
            cout <<"***" << i << endl; 
        }
    }
    
    //output
    printf("%.2f %d", max_price, num); 
    return 0;
}
