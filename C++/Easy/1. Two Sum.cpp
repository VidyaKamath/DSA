// O(n2) solution
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> result {-1, -1};

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i != j){

                    if(nums[i] + nums[j] == target)
                    {
                        result[0] = i;
                        result[1] = j;
                        return result;
                    }
                }

            }
        }
        return result;
    }
};

// O(nlogn) solution using sorting
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> result {-1, -1};

        vector <pair<int, int>> nums_sort;
        pair<int, int> temp;

        //O(n)
        for(int i = 0; i < nums.size(); i++)
        {
            // store the actual index of the number before sorting
            temp.first = nums[i];
            temp.second = i;
            nums_sort.push_back(temp);
        }

        //sort : O(nlogn)
        std::sort(nums_sort.begin(), nums_sort.end());

        int first_idx = 0;
        int last_idx = nums_sort.size() - 1;

        //o(n)
        while(first_idx < last_idx)
        {
            if(nums_sort[first_idx].first + nums_sort[last_idx].first == target)
            {
                result[0] = nums_sort[first_idx].second;
                result[1] = nums_sort[last_idx].second;
                return result;
            }
            else if(nums_sort[first_idx].first + nums_sort[last_idx].first > target)
            {
                last_idx--;
            }
            else
            {
                first_idx++;
            }
        }
       return result;
    }
};


// O(n) solution using unordered map
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> operand_map;

        for(int idx = 0; idx < nums.size(); idx++)
        {
            //target = op1 + op2 --> op2 = target-op1
            int op2 = target - nums[idx];

            if(operand_map.count(op2))
            {
                result.push_back(idx);
                result.push_back(operand_map.at(op2));
                break;
            }
            else
            {
                operand_map[nums[idx]] = idx;
            }
        }
        return result;
    }
};
