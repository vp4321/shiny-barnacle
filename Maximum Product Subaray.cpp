/*
AP1 :O(N^2)

take subarray products , keep updating max
*/

class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int pdt;
        int maxm=INT_MIN;
        for(int i=0;i<n;i++)
        {
            pdt=1;
            for(int j=i;j<n;j++)
            {
                pdt*=nums[j];
                maxm = max(maxm,pdt);
            }
        }
        return maxm;
    }
};

/*
AP2:O(N)

Similar to kadane algo

curmax  - stores max pdt till now
curmin  - to handle -ves,
        - stores min pdt till now

res - stores max of curmax till now

curmax=max(nums[i],max(nums[i]*curmin,curmax*nums[i]));
        why nums[i] ?  [-1,8] in this case curmax should be 8
        nums[i]*curmin? in case of both -ve , could result in a biggest no.

curmin=min(nums[i],min(nums[i]*curmin,temp*nums[i]));
        keep track of it for -ve no.s as -ve * -ve = +ve and this may 
        become the max of all times



*/

int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int curmax=1;
        int curmin=1;
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {     
            int temp=curmax;
            curmax=max(nums[i],max(nums[i]*curmin,curmax*nums[i]));
            curmin=min(nums[i],min(nums[i]*curmin,temp*nums[i]));
            res=max(res,curmax);
        }
        return res;
    }

/*
[-1,-2,-3]
if no curmin , ans would be -6. as curmax = 1-> -1 -> 2 -> -6

 */
