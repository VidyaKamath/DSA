class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mid;
        char res = letters[0];
        int start = 0;
        int end = letters.size()-1;

        while(start<=end){
            mid = start + (end-start)/2;
            if(letters[mid]==target){
                start = mid+1;
            }
            else if(letters[mid] > target){
                res = letters[mid];
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return res; 
    }
};
