class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.length();
        string t = "";
        for(int i = 0; i<n; i++){
            if(isalpha(s[i]) || isdigit(s[i])) t += toupper(s[i]);
        }
        int i = 0, j = t.length()-1;
        while(i <= j) {
            if(t[i++] != t[j--]) return false;
        }
        return true;
    }
};