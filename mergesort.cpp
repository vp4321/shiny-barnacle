#include<bits/stdc++.h>
using namespace std;
 void mergeArray(vector<int>&v,int l,int h)
{
    vector<int>ans;
    cout<<"Merge function called"<<endl;
    int mid = (l+h)/2;
    vector<int>num1,num2;
    for(int i=l;i<=mid;i++)
    {
        num1.push_back(v[i]);
    }
    for(int i=mid+1;i<=h;i++)
    {
        num2.push_back(v[i]);
    }
    int i = 0,j = 0,k=l;

    while(i<num1.size()&&j<num2.size())
    {
        if(num1[i]<num2[j])
        {
            v[k++] = num1[i++];
        }
        else
        {
            v[k++] = num2[j++];
        }
    }
    while(i<num1.size())
    {
        v[k++] = num1[i++];
    }
    while(j<num2.size())
    {
        v[k++] = num2[j++];
    }


}
void mergeSort(vector<int>&v,int l,int h)
{
    cout<<"Sort function called"<<endl;
    if(l>=h)
    return;
   int mid = (l+h)/2;
   //left part sorting
   mergeSort(v,l,mid);
   //right part sorting
   mergeSort(v,mid+1,h);
   mergeArray(v,l,h);
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
    mergeSort(num,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
}