#include<bits/stdc++.h>
using namespace std;

void displayVector (vector<int> v){
   for(int i=0; i<v.size(); i++){
      cout<<v[i]<<" ";
   }
}
int kthsmallest (int arr[], int n, int k){
   
   priority_queue<int> maxh;
   for(int i=0; i<n; i++){
      maxh.push(arr[i]);
      if(maxh.size()>k){
         maxh.pop();
      }
   }
   return maxh.top();
}

vector<int> ksorted (int arr[], int n, int k){
   priority_queue<int, vector<int>, greater<int>> minh;
   vector<int> sorted;
   for(int i=0; i<n; i++){
      minh.push(arr[i]);
      if(minh.size()>k){
         sorted.push_back(minh.top());
         minh.pop();
      }
   }
   while(!minh.empty()){
      sorted.push_back(minh.top());
      minh.pop();
   }
   return sorted;
}

vector<int> kClosest (int arr[], int n, int x, int k){
   priority_queue<pair<int, int>> maxh;
   vector<int> closest;
   for(int i=0; i<n; i++){
      maxh.push({abs(arr[i]-x), arr[i]});
      if(maxh.size()>k){
         maxh.pop();
      }
   }
   while(!maxh.empty()){
      closest.push_back(maxh.top().second);
      maxh.pop();
   }
   return closest;
}

int main()
{
    
   

}