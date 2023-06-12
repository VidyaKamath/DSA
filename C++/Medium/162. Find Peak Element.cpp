class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;

        //base case
        if(high == 0){
            return 0;
        }

        while(low<=high){
            mid = low + (high-low)/2;
            if(mid>0 && mid<nums.size()-1)
            {
                if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                    return mid;
                }
                else if(nums[mid+1]>nums[mid]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }

            if(mid==0){
                if(nums[mid] > nums[mid+1])
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            if(mid==nums.size()-1){
                if(nums[mid] > nums[mid-1])
                {
                    return nums.size()-1;
                }
                else
                {
                    return nums.size()-2;
                }
            }
           
        }
        return 0; 
    }
};
