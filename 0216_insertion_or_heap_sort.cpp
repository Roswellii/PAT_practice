#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int inse_arr[105], heap_arr[105], res_arr[105];
int n;

int equal_arr(int *a, int *b){
    for(int i=0; i<n;i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}

void next_inse(int i){
    for(int j=i; j>0&&inse_arr[j]<inse_arr[j-1]; j--){
        swap(inse_arr[j], inse_arr[j-1]);
    }
}

void next_heap(int i){
    pop_heap(heap_arr, heap_arr+n-i+1);
    push_heap(heap_arr, heap_arr+n-i);
}

void print_arr(int *a){
    printf("%d", a[0]);
    for(int i=1;i<n; i++){
        printf(" %d", a[i]);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&inse_arr[i]);
        heap_arr[i]= inse_arr[i];
    }
    make_heap(heap_arr, heap_arr+n);
    for(int i=0; i<n; i++){
        scanf("%d", &res_arr[i]);
    }
    for(int i=1; i<n; i++){
        next_inse(i);
        if(equal_arr(inse_arr, res_arr)){
            printf("Insertion Sort\n");
            next_inse(i+1);
            print_arr(inse_arr);
            return 0;
        }
        if(equal_arr(heap_arr, res_arr)){
            printf("Heap Sort\n");
            next_inse(i+1);
            print_arr(heap_arr);
            return 0;
        }
        next_heap(i);
    }
    return 0;
}



