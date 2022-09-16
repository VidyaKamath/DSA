class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum = 0;
        int leftsum = 0;
        int pivot = -1;
        
        //Calculate the sum of all the elements
        for(unsigned int i=0; i<nums.size(); i++)
        {
            sum = sum + nums[i];
        }
        
        // find the pivot
        for(unsigned int i=0; i<nums.size(); i++)
        {
            if(leftsum == sum-leftsum-nums[i])
            {
                return i;
            }
            else
            {
                leftsum = leftsum + nums[i];  
            }
        }
        return pivot;
        
    }
};
