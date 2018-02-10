// Sorting an array using heap sort

#include<stdio.h>

void heapsort(int[],int);
void heapify(int[],int);
void shift(int[],int,int);
void swap(int[],int,int);
void display(int[],int);

int main()
{
    int t,n,i,a[1000000];
    
    scanf("%d",&t); //number of test cases
    
    while(t>0)
    {
        scanf("%d",&n); // array length
        for(i=0;i<n;++i)
        scanf("%d",&a[i]);
        heapsort(a,n);
        display(a,n);
        t--;
    }
    return 0;
}

void heapsort(int a[1000000],int n)
{
    int i;
    
    heapify(a,n);
    
    i=n-1;
    while(i>0)
    {
        swap(a,i,0);
        i--;
        shift(a,0,i);
    }
}

void heapify(int a[1000000],int n)
{
    int start;
    
    start=(n-2)/2;
    
    while(start>=0)
    {
        shift(a,start,n-1);
        start--;
    }
}

void shift(int a[1000000],int start,int n)
{
    int root,node,temp;
    
    root=start;
    
    while(root*2+1<=n)
    {
        node=root*2+1;
        temp=root;
        
        if(a[temp]<a[node])
        temp=node;
        
        if(node+1<=n && a[temp]<a[node+1])
        temp=node+1;
        
        if(temp==root)
        return;
        
        else
        {
            swap(a,root,temp);
            root=temp;
        }
    }
}

void swap(int a[1000000],int x,int y)
{
    int t;
    
    t=a[x];
    a[x]=a[y];
    a[y]=t;
}

void display(int array[1000000],int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d\n",array[i]);
}

