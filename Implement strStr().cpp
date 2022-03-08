class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;
        int n = haystack.length();
        int m = needle.length();
        if( m > n) return -1;
        string val = "";
        for(int i = 0; i < m; i++){
            val += haystack[i];
        }
        int i;
        for(i = m; i < n; i++){
            if(val == needle){
                return i-m;
            }
            val.erase(0,1);
            val += haystack[i];
        }
        if(val == needle) return i-m;
        return -1;
        
    }
};