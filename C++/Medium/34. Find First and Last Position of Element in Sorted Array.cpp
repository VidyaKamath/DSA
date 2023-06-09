class Solution {
public:
    int searchFirst(vector<int>&nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int mid;
        int res = -1;
        while(start<=end){
            mid = start + (end-start)/2;
            if (nums[mid] == target){
                res = mid;
                //continue the search on the left side for first occurrence
                end = mid-1;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return res;
    }
    int searchLast(vector<int>&nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int mid;
        int res = -1;
        while(start<=end){
            mid = start + (end-start)/2;
            if (nums[mid] == target){
                res = mid;
                //continue the search on the right side for last occurrence
                start = mid+1;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = searchFirst(nums, target);
        int last = searchLast(nums, target);
        vector<int> res;
        res.push_back(first);
        res.push_back(last);
        return res;
    }
};
