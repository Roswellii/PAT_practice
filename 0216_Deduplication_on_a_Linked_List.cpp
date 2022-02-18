#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int Next[100000];
int a[1000000];
bool mark[10005];

int main(){
    //
    int n, head;
    cin >> head >> n;
    for(int i=0; i<n;i++){
        int x;
        scanf("%d",&x);
        scanf("%d%d", a+x, Next+x);
    }
    
    //
    int h1= -1, t1= -1, h2= -1, t2= -1;
    for(; head>=0; head=Next[head]){
        int x= (a[head]>=0)? a[head]:-a[head];
        if(mark[x]==1){
            if(t2==-1){
                t2= head;
                h2= t2;
            }else{
                Next[t2]= head;
                t2= head;
            }
        }else{
            mark[x]= 1;
            if(t1==-1){
                t1= head;
                h1= head;
            }else{
                Next[t1]= head;
                t1= head;
            }
        }
    }

    //
    if(t1>0){
        Next[t1]= -1;
        for(head=h1; head>=0; head= Next[head]){
            printf("%05d %d", head, a[head]);
            if(Next[head]>=0){
                printf(" %05d\n", Next[head]);
            }else{
                puts(" -1");
            }
        }
    }

    if(t2>0){
        Next[t2]= -1;
        for(head=h2; head>=0; head= Next[head]){
            printf("%05d %d", head, a[head]);
            if(Next[head]>=0){
                printf(" %05d\n", Next[head]);
            }else{
                puts(" -1");
            }
        }
    }
    return 0;
}