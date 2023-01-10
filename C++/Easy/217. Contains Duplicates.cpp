class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int idx=0;idx< nums.size(); idx++){
            if(s.find(nums[idx])!= s.end())
                return true;     
            s.insert(nums[idx]); 
        }
        return false;     
    }
};