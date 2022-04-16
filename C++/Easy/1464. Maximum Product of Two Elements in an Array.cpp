// O(nlogn) (sorting time dominates)
class Solution1 {
public:
    int maxProduct(vector<int>& nums)
    {
        int max_product;
        int first_max, second_max;
        unsigned int size n = nums.size();

        //sort the array in ascending order
        std::sort(nums.begin(), nums.end());
        first_max = nums[n - 1];
        second_max = nums[n - 2];
        max_product = (first_max - 1) * (second_max - 1);

        return max_product;
    }
};

// O(n)
class Solution2 {
public:
    int maxProduct(vector<int>& nums)
    {
        int first_max, second_max, max_product;

        // find the first two maximum numbers
        if(nums[0] >= nums[1])
        {
            first_max = nums[0];
            second_max = nums[1];
        }
        else
        {
            first_max = nums[1];
            second_max = nums[0];
        }

        for(unsigned int i = 2; i < nums.size(); i++)
        {
            if(nums[i] > first_max)
            {
                second_max = first_max;
                first_max = nums[i];
            }
            else if(nums[i] > second_max)
            {
                second_max = nums[i];
            }
        }
        max_product = (first_max - 1) * (second_max - 1);

        return max_product;
    }
};

