#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sqr=(long long)sqrt(1.0*n);
    long long first=0,len=0;               //len为最长连续整数的长度，first是其中第一个
    for(long long i=2;i<=sqr;i++){         //遍历第一个整数
        long long temp=1,j;                //temp为当前连续整数的乘积
        for(j=i;;j++){
            temp*=j;
            if(n%temp!=0) break;           //j不断加1直到temp不能整除n
        }
        if(j-i>len){                       //更新最长长度与第一个整数
            len=j-i;
            first=i;
        }
    }
    if(len==0) cout<<1<<endl<<n;          //根号n范围内都无解，只能输出n本身（素数）
    else{
        cout<<len<<endl;
        for(long long i=0;i<len;i++){
            cout<<first+i;
            if(i<len-1) cout<<"*";
        }
    }
    return 0;
}
