class Solution {
public:
    void helper(vector<char> &vowels, vector<char> &tmp, vector<vector<char>> &ans, int n, int start)
    {
        // if our tmp.size(), in which we are storing our combination reaches to the n then push that combination into our ans
        if(n==tmp.size())
        {
            ans.push_back(tmp);
            return;
        }
        
        // start viisitng all the remaining vowels with the current vowel 
		// beacuse it can make combination with itself and all the right vowels also
        // each time push current vowel to our temp and call the same function for current i
        for(int i=start;i<vowels.size();i++)
        {
            tmp.push_back(vowels[i]);
            helper(vowels,tmp,ans,n,i);
            tmp.pop_back();                  // backtracking
        }
        return;
    }
    
    int countVowelStrings(int n) 
    {
        // it is the vector by which we need to create all possible combination of strings
        vector<char> vowels = {'a','e','i','o','u'};
        
        // it will store the current string each time
        vector<char> tmp;
        
        // it will store all the possible combination
        vector<vector<char>> ans;
        
        // call the helper function
        helper(vowels,tmp,ans,n,0);
        
        return ans.size();
    }
};