class Solution {
public:
    bool isValid(vector<int>& nums, int k, int lim){
        int student = 1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            if(sum > lim){
                student ++;
                sum = nums[i];
            }
            if(student>k){
                return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {  
        int mid;
        int start = *max_element (nums.begin(), nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);
        int res = -1;

        if(nums.size()<k){
            return -1;
        }

        while(start<=end){
            mid = start + (end-start)/2;
            if(isValid(nums, k, mid) == true){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return res; 
    }
};
