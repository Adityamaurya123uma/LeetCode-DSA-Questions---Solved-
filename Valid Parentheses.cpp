class Solution {
public:
    
    bool isValid(string s) {
        
        unordered_map<char, char> m = {{')','('},
                                       {']','['},
                                       {'}','{'}
                                      };
        stack<int> stk;
        int n = s.size();
        for(auto x : s)
        {
            if(x == '(' || x == '[' || x == '{')
            {
                stk.push(x);
            }
            else{
                if(stk.empty()) // if we have string like this "})}[]" then at this point stack must be empty i.e string start from close bracket.
                    return false;
                char ch = stk.top();
                stk.pop();
                if(ch != m[x])
                    return false;
            }
        }
        return stk.empty();
    }
};