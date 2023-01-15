class Solution {
public:
    bool issubsetSum(vector<int>& nums, int sum){

        int n = nums.size();
        bool t[n+1][sum+1];

        //initialisation
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                // array with size 0
                if(i==0){
                    t[i][j] = false;
                }
                // subset sum of 0 with array size i
                if(j==0){
                    t[i][j] = true;
                }
            }
        }

        //DP
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }   
        return t[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        // Calculate the sum of elements of the vector
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
        }

        // equipartition is possible only if the sum of elements of the 
        // vectors is even
        if(sum % 2 == 0){
             return issubsetSum(nums, sum/2);
        }
        
        return false;
    }
};