//O(nlogn) - TC and O(n) - SC
class Solution1 {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());
        // As the majority element appears at least n/2 times,
        // after sorting, it will be available at n/2 position.
        return nums[n/2];
    }
};

//O(nlogn) - TC and O(n) - SC
class Solution2 {
public:
    int majorityElement(vector<int>& nums)
     {
        int count = 0;
        int majority_element;

        // Boyer-Moore Voting Algorithm
        for(auto num : nums)
        {
            if(count == 0)
            {
                majority_element = num;
                count++;
            }
            else if(num == majority_element)
            {
               count++;
            }
            else
            {
               count--;
            }
        }
        return majority_element;
    }
};
