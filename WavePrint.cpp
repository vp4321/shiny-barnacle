#include<bits/stdc++.h>
using namespace std;
vector<int> wavePrint(vector<vector<int>>arr,int nRows,int mCols)
{
    vector<int>ans;
    for(int j = 0;j<mCols;j++ )
    {
        
            if(j%2==0)
            {
                for(int i=0;i<nRows;i++)
                {
                    ans.push_back(arr[i][j]);
                }
            }
            else
            {
                for(int i=nRows-1;i>=0;i--)
                {
                    ans.push_back(arr[i][j]);
                }
            }
    }
   return ans;
}
int main()
{
    vector<vector<int>>arr;
    int row,col;
    cin>>row>>col;
    int i,j,k;
    for(i=0;i<row;i++)
    {
        vector<int>v;
        for(j=0;j<col;j++)
        {
            cin>>k;
            v.push_back(k);
        }
        arr.push_back(v);
    }
    vector<int>vect = wavePrint(arr,row,col);
    for(i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<" ";
    }
    
}