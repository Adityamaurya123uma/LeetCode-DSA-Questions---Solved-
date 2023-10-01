Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:
Input: s = "God Ding"
Output: "doG gniD"

class Solution {
public:
    string reverseWords(string s) {
        
        int l=0,r=0;
        
        while(l < s.size()){
            while(r < s.size() && s[r] != ' '){
                r++;
            }
            reverse(s.begin()+l,s.begin()+r);
            l=r+1;
            r=l;
        }
        return s;
    }
};
