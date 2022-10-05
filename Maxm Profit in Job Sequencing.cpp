/*
https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

- UNIFORMITY - as no overlapping
- sort the arr wrt the profit
- schedule the job to last date/ the date nearest to deadline available
We are scheduling
*/

class Solution
{
    public:
    bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, comparison);
        int maxi = arr[0].dead;
          for (int i = 1; i < n; i++) {
             maxi = max(maxi, arr[i].dead);
          }
        int slot[maxi + 1];
        for (int i = 0; i <= maxi; i++)
         slot[i] = -1;



         int profit=0;int jobs=0;
         for(int i=0;i<n;i++)
         {
             int dead = arr[i].dead;
             while(dead)  // - schedule the job to last date/ the date nearest to deadline available
             {
                 if(slot[dead]==-1)
                 {
                     slot[dead]=i;
                     jobs++;
                     profit+=arr[i].profit;
                     break;
                 }
                 dead--;
             }
         }
         return {jobs,profit};
    }
}
