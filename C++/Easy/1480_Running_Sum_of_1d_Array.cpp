class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

    unsigned int length = nums.size();
    vector<int> sum(length, 0);

    sum[0] = nums[0];
    for(unsigned int idx=1; idx<length; idx++)
    {
        sum[idx] = sum[idx-1] + nums[idx];
    }

     return sum;
    }
};
