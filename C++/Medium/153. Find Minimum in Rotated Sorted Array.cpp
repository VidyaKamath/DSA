class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid;
        int next;
        int prev;
        int start = 0;
        int length = nums.size();
        int end = length-1;

        while(start<=end){
            // if array is sorted then just return the first element
            if(nums[start]<nums[end]) {
                 return nums[start];
            }
            mid = start + (end-start)/2;
            next = (mid+1)%length;
            prev = (mid+length-1)%length;
            // in a rotated sorted array only the min element will be 
            // less than it's next and previous element
            if((nums[mid]<=nums[prev]) && (nums[mid]<=nums[next])){
                return nums[mid];
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
    return -1;
    }     
};
