class Solution {
public:
    int findMinPosition(vector<int>& nums){
        int mid;
        int next;
        int prev;
        int start = 0;
        int length = nums.size();
        int end = length-1;

        while(start<=end){
            // if array is sorted then just return the first element
            if(nums[start]<nums[end]) {
                 return start;
            }
            mid = start + (end-start)/2;
            next = (mid+1)%length;
            prev = (mid+length-1)%length;
            // in a rotated sorted array only the min element will be 
            // less than it's next and previous element
            if((nums[mid]<=nums[prev]) && (nums[mid]<=nums[next])){
                return mid;
            }
            // min element will always be in the unsorted part of the array
            // left is sorted so continue the search on the right side 
            else if(nums[mid]>=nums[start]){
                start = mid+1;
            }
            //right is sorted so continue the search on the left side
            else if(nums[mid]<=nums[end]){
                end = mid-1;
            }
        }
    return 0;
    }        
    int binarySearch(vector<int>& nums, int target, int start, int end){
        int mid;
        while(start<=end){
            mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int min_ele_idx = findMinPosition(nums);
        int res1 = binarySearch(nums, target, 0, min_ele_idx-1);
        if(res1 == -1){
            res1 = binarySearch(nums, target, min_ele_idx, nums.size()-1);
        }
        return res1;
    }
};
