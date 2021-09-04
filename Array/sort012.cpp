/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
*/
#include<bits/stdc++.h>

using namespace std;

void sort012(int a[], int n)
{
    // coode here 
    int count[3]={};
    for (size_t i = 0; i < n; i++)
    {
        if(!a[i])
            count[0]++;
        else if(a[i]==1)    
            count[1]++;
        else 
            count[2]++;
    }
    for (size_t i = 0; i < n; i++)
    {
        if(count[0]>0) 
            a[i]=0 , count[0]--;
        else if(count[1]>0)
            a[i]=1 , count[1]--;
        else 
            a[i]=2 , count[2]--;
    }
}

int main()
{

    return 0;
}