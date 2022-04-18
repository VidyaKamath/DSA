class Solution1 {
public:
    void reverseString(vector<char>& s)
    {
        int n = s.size();
        char temp;

        for( int i = 0; i < n / 2; i++)
        {
            //swap(s[i], s[n - i - 1]);
            temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
    }
};

// Two pointer approach
class Solution2 {
public:
    void reverseString(vector<char>& s)
    {
        int start = 0;
        int last = s.size() - 1;

        while( start <= last)
        {
            swap(s[start], s[last]);
            start++;
            last--;
        }
    }
};


