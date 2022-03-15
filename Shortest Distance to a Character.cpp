class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=(int)s.size();
        vector<int>ans(n,INT_MAX);
        int pos=-1;
         for(int i=0;i<n;i++){
            if(s[i]==c){
                pos=i;
            }
            if(pos!=-1){
                ans[i]=(i-pos);
            }
        }    
        
        pos=-1;
        
        for(int i=n-1;i>=0;i--){
            if(s[i]==c){
                pos=i;
            }
            if(pos!=-1){
                ans[i]=min(ans[i],(pos-i));
            }
        }    
        return ans;
    }
};