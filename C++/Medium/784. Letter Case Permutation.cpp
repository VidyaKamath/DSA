class Solution {
public:
    void solve(string s, string op, vector<string>& res)
    {
        // Ip-op method by Aditya Verma
        string op1 = op;
        string op2 = op;

        if (s.length() == 0)
        {
            res.push_back(op);
        } 
        
        if(isalpha(s[0]))
        {
            // choice1: include the character without case change
            op1.push_back(s[0]);
            
            // choice2: include the character with case change
            if (islower(s[0])){
                op2.push_back(toupper(s[0]));
            }
            if (isupper(s[0])){
                op2.push_back(tolower(s[0]));
            }

        // remove the processed character to reduce the input size    
        s.erase(s.begin() + 0);
        
        // process the input string recursively
        solve(s, op1, res);
        solve(s, op2, res);

        }
        else if (isdigit(s[0]))
        {
            op1.push_back(s[0]);
            s.erase(s.begin() + 0);
            solve(s, op1, res);
        }  
    }

    vector<string> letterCasePermutation(string s) {
        string op;
        vector<string> res;
        solve(s, op, res);
        return res;       
    }
};
