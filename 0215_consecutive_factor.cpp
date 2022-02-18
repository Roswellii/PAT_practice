#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long sqr= (long long)sqrt(1.0*n);
    long long first=0, len= 0;

    for(long long i=2; i<=sqr; i++){
        long long temp=1, j;
        for(j=i;;j++){//连续数连乘
            temp*=j;
            if(n%temp!=0) break;
        }
        if(j-i>len){
            len= j-i;
            first= i;
        }
    }
    if(len==0) cout<< 1<< endl << n;
    else{
        cout << len << endl;
        for(long long i=0; i<len; i++){
            cout << first+ i;
            if(i< len-1) cout<<"*";
        }
    }
    return 0;
}