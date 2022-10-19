#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long int>a;
    long long int n,m,k,i,j,diff;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>k;
        a.push_back(k);
    }
    sort(a.begin(),a.end());
    j=0,k=m-1;
    diff = a[k]-a[j];
    while(k<n)
    {
        diff= min(diff,(a[k]-a[j]));
        j++;
        k++;
    }
    cout<<diff<<endl;
}