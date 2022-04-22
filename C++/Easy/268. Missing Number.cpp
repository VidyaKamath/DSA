// O(nlogn)
class Solution1 {
public:
    int missingNumber(vector<int>& nums)
    {
        //sort the array
        int missing_number = nums.size();

        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            if(i != nums[i])
            {
                missing_number = i;
                break;
            }
        }
        return missing_number;
    }
};

/*
We are using the properties of xor to find the missing number
a^0 = a
a^a = 0
Example : for array [3,0,1]
we did xor with values [1,2,3] which we got by using i+1
This made all the numbers except the missing one to be zero
Also while doing xor, order does not matter
*/

class Solution2 {
public:
    int missingNumber(vector<int>& nums)
    {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i] ^ (i + 1);
        }
        return ans;
    }
};
