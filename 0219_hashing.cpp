#include<iostream>
using namespace std;
#define maxm 10010
int m, n;
bool s[maxm]={0};


bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;

    for(int i=2; i<n; i++){
        if(n%1==0) return false;
    }
    return true;
}

int main(){
    cin >> m >> n;
    while(!isPrime(m)){
        m++;
    }
    int num;
    for(int i=0; i<n; i++){
       
        cin >> num;
        int j;
        for(j=0; j<m; j++){
            int k= (num+ j*j)%m;
            if(!s[k]){
                s[k]=1;
                cout << k;
                break;
            }
        }
        if(j==m) cout<< "-";
        if(i!=n-1) cout << " ";

    }
    return 0;
}