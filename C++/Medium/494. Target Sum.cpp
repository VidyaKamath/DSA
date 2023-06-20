class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        int subset_sum;
        int res;

        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        // derived from the eqns a - b = target and a + b = arr_sum
        if((target > sum) || (target + sum)%2!=0)
            return 0;
        else
            subset_sum = (target + sum)/2;
            if(subset_sum < 0)
                return 0;
            res = countSubsetSum(nums, subset_sum);
            return res;
    }

    int countSubsetSum(vector<int>& nums, int subset_sum){
        int n = nums.size();
        int t[n+1][subset_sum+1];
        
        // intialisation
        for(int i=0;i<n+1;i++){
            for(int j=0;j<subset_sum+1;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }

        // DP
        for(int i=1;i<n+1;i++){
            for(int j=0;j<subset_sum+1;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[nums.size()][subset_sum];
    }
};
