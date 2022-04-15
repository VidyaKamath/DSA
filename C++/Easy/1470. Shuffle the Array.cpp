class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> result;
        for(unsigned int i = 0; i < n; i++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[n + i]);
        }
        return result;
    }
};
