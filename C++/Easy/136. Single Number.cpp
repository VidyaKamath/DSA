class Solution {
public:
    int singleNumber(vector<int>& nums)
    {

        int single_number = 0;
        // Bit manipulation using the properties of xor;
        // a^a is 0 and a ^ 0 = a. So the element that appears only once
        // will be left out and the xor of all other pairs give zero.
        for(auto num : nums)
        {
            single_number = single_number ^ num;
        }
        return single_number;
    }
};
