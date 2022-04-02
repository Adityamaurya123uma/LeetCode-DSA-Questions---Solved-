class Solution {
public:
    void reverseString(vector<char>& s) {
        
       int n=s.size();
        int l=0;
        int h=n-1;
        
        while(l<h){
            swap(s[l],s[h]);
            l++;
            h--;
        }

    }
};