
typedef  pair<double,int> pdi;
class Solution
{
    public:
    
    static bool comp(pdi &a,pdi &b)
    {
        return a.first>b.first;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double val=0;
        vector<pdi>rate;
        for(int i=0;i<n;i++)
        {
            rate.push_back({arr[i].value*1.0/arr[i].weight*1.0,i});
        }
        sort(rate.begin(),rate.end(),comp);
        for(int i=0;i<n;i++)
        {
            int idx = rate[i].second;
            if(W>=arr[idx].weight)
            {
                val+=arr[idx].value;
                W-= arr[idx].weight;
            }
            else
            {
                val+=rate[i].first*W;
                break;
            }
        }
        return val;
    }
        
};
