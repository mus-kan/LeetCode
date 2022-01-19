class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) 
    {
        if(nums.size()< 3)  //EDGE CASE
            return  0;
        
        sort(nums.begin(),nums.end());
        int res= nums[0]+ nums[1]+nums[2];
        
        int n= nums.size();
        
        for(int i=0; i< n-2; i++)
        {
            int j=i+1;
            int k=n-1;
            
            while(j<k)
            {
                int total = nums[i]+nums[j]+nums[k];
                if(total==target)
                    return total;
                if(abs(target-total) < abs(target-res)) //Difference is minimum
                {
                res = total;
                }
                if(total < target)
                {
                    res = max(res, nums[i]+nums[j]+nums[k]);
                    j++;
                }
                else
                {
                    k--;
                }
            }
            
        }
        return res;
        
    }

};