#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&num,int l,int r)
{
    int pivot = num[l];
    int i=l+1,j=r;
    while(i<j)
    {
        while(num[i]<=pivot)
        {
            i++;
        }
        while(num[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(num[i],num[j]);
            i++;
            j--;
        }
        
    }
    swap(num[l],num[j]);
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    return j;

}
void QuickSort(vector<int>&num,int l,int r)
{
    if(l>=r)
    return;
    int p = partition(num,l,r);
    QuickSort(num,l,p-1);
    QuickSort(num,p+1,r);

}
int main()
{
    int n,k;
    cin>>n;
    vector<int>num;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        num.push_back(k);
    }
    QuickSort(num,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }

}