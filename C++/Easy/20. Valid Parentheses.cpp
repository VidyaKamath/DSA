class Solution1 {
public:
    bool isValid(string s)
    {
        stack<char> open;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '{' || ch == '(' || ch == '[')
            {
                open.push(ch);
            }
            else
            {
                if (open.size() == 0)
                {
                    return false;
                }
                char top = open.top();
                if ((top == '{' && ch == '}') || 
                    (top == '(' && ch == ')') || 
                    (top == '[' && ch == ']'))
                {
                    open.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (open.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Reference: https://neetcode.io/practice
class Solution2 {
public:
    bool isValid(string s) {
        stack<char> open;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (open.empty()) {
                    return false;
                }
                if (s[i] == ')' && open.top() != '(') {
                    return false;
                }
                if (s[i] == '}' && open.top() != '{') {
                    return false;
                }
                if (s[i] == ']' && open.top() != '[') {
                    return false;
                }
                open.pop();
            } else {
                open.push(s[i]);
            }
        }
        
        if (!open.empty()) {
            return false;
        }
        return true;
    }
};

































