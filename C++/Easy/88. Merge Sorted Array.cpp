class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        // start parsing from the end of the array as nums1
        // should contain the final result.
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else if(nums1[i] <= nums2[j])
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        // when nums1 is empty and nums2 is not empty.
        while(j >= 0)
        {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};
