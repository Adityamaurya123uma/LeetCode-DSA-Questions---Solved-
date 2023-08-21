class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = s; 

        for(int i=0; i<s.size()-1; i++){ 
            char c = str[0];  
            str.erase(0,1); 
            str.push_back(c); 
            if(str==s) { 
                return true; 
            }
        }
        return false;
    }
};
