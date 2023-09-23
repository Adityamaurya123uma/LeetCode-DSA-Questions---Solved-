Example 1:
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


class Solution {
    static bool compare(string &s1, string &s2){
        return s1.length() < s2.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        
        int ans = 1;
        int n = words.size();
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        
        for(int i = 0 ; i < n ; i++){
            dp[words[i]] = 1;
            int maxPosSubChain = 0;
            for(int j = 0 ; j < words[i].length(); j++){
                string predecessor  = words[i].substr(0, j) + words[i].substr(j+1);
                if(dp.find(predecessor)!=dp.end()){
                    maxPosSubChain = max(maxPosSubChain, dp[predecessor]);
                }
            }
            dp[words[i]] += maxPosSubChain;
            ans = max(ans, dp[words[i]]);
        }        
        
        return ans;
        
    }
};
