class Solution {
public:
    bool isSubsequence(string s, string t) {

        int sub_seq_len = s.length();
        int str_len = t.length();
        int sub_seq_idx = 0;
        int str_idx = 0;

        while(sub_seq_idx < sub_seq_len && str_idx < str_len)
        {
            if(s[sub_seq_idx] == t[str_idx])
            {
                sub_seq_idx++;
            }
            str_idx++;
        }
        return sub_seq_idx == sub_seq_len;     
    }
};
