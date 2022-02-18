#include<bits/stdc++.h>
#definx maxn 100005
#define inf 1e6
using namespace std;

//paras
int n;
double p, r;
const double eps = 1.e-8;
//@ what for?
int f[maxn]; // parent
double a[maxn];  // cost

double get(int x){
    if(a[x]> -1){
        return a[x];
    }
    return a[x]= get(f[x])* r;
}

int main(){
    //input paras
    scanf("%d %lf %lf", &n, &p, &r);// %f for float, %lf for double
    // increasment rate
    r/= 100;
    r+=1; 

    // input parents
    for(int i=0; i<n; i++){
        scanf("%d", f+i); // save parent
        a[i]= (f[i]<0)?p :(-inf); // set cost
    }

    // count highest price num 
    double max_price= -inf, price= -inf;
    int num; 
    for(int i=0;i<n; i++){
        price= get(i); //each node price
        if(price> max_price+ eps){
            max_price= price;
            num= 1;
        }else if((price+ eps> max_price)&& (price< max_price+eps)){
            ++num; //
        }
    }

    return 0;
}