/*
 Permutations of a string in lexicographic order
 
 Question : You are given a b-digits-long whole number in base b where all the digits are distinct.
 If all such all-distinct-b-digits-long whole numbers in  base b are listed in lexicographic order,
 what would be the position of the given number?
 */

#include<stdio.h>
#include<string.h>

int permute(char[],char[],int);
void swap(char[],char,char);
void reverse(char[],int,int);
void sort(char[],int);


int main()
{
    char a[11],b[11];
    int n,t,pos;
    
    scanf("%d",&t); //number of test cases
    
    while(t>0)
    {
        scanf("%s",a);
        strcpy(b,a);
        n=strlen(a);
        sort(a,n);
        pos=permute(a,b,n);
        printf("%d",pos);
        printf("\n");
        t--;
    }
    
    
    return 0;
}

int permute(char a[11],char b[11],int n)
{
    int k,l,i,j,last,pos,count;
    last=0;
    count=1;
    pos=1;
    
    while(!last && pos==1)
    {
        k=-1;
        
        for(i=0;i<n;i++)
        {
            if(a[i]<a[i+1])
            {
                k=i;
            }
        }
        
        if(k == -1)
        {
            last=1;
        }
        
        if(!last)
        {
            for(j=k+1;j<n;j++)
            {
                if(a[j]>a[k])
                {
                    l=j;
                }
            }
            
            swap(a,l,k);
            reverse(a,(k+1),n);
            count++;
            if(strcmp(a,b)==0)
            pos=count;
            
        }
    }
    
    return pos;
}

void swap(char a[11],char x,char y)
{
    int t;
    
    t=a[x];
    a[x]=a[y];
    a[y]=t;
}

void reverse(char a[11],int l,int n)
{
    int i,j;
    char temp;
    
    i=l;
    j=n-1;
    
    while(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}

void sort(char a[11],int n)
{
    int i,j;
    char t;
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
