#include<iostream>
#include<cstdio>
#include<cstdio>
#include<algorithm>
using namespace std;
int inse_arr[105],heap_arr[105],res_arr[105];
int n;
int equal_arr(int *a,int *b)//判断两个数组是否相等 
{
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            return 0;
    return 1;
}
void next_inse(int i)//下一个插排序列 
{
    for(int j=i;j>0&&inse_arr[j]<inse_arr[j-1];j--)
        swap(inse_arr[j],inse_arr[j-1]);
}
void next_heap(int i)//下一个堆排序列 
{
    pop_heap(heap_arr,heap_arr+n-i+1);//最值移动到范围最后
    push_heap(heap_arr,heap_arr+n-i);//后界限向前移动，范围内重新建堆
}
void print_arr(int *a)//打印数组 
{
    printf("%d",a[0]);
    for(int i=1;i<n;i++)
        printf(" %d",a[i]);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inse_arr[i]);//输入插排和堆排 
        heap_arr[i]=inse_arr[i];
    }
    make_heap(heap_arr,heap_arr+n);//建堆 
    for(int i=0;i<n;i++)
        scanf("%d",&res_arr[i]);
    for(int i=1;i<n;i++)
    {
        next_inse(i);
        if(equal_arr(inse_arr,res_arr))//判断下一个插排序列是否相等 
        {
            printf("Insertion Sort\n");
            next_inse(i+1);
            print_arr(inse_arr);
            return 0;
        }
        if(equal_arr(heap_arr,res_arr))//判断下一个堆排序列是否相等，放在这是不知道建堆算不算第一步 
        {
            printf("Heap Sort\n");
            next_heap(i);
            print_arr(heap_arr);
            return 0;
        }
        next_heap(i);
    }
    return 0;
}