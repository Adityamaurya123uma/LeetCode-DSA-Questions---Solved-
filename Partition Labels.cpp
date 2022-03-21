class Solution {
public:
    int last(string s, char ch, int start, int n)       
    {
        int pos = start;
        for(int i=start;i<n;i++){
            if(s[i]==ch){
                pos = i;
            }
        }
        return pos;             
    }
    vector<int> partitionLabels(string s) 
    {
        vector<int> res;
        int n = s.length();
        int i=0;
        while(i<n){
            char ch = s[i];
            int l = last(s,ch,i,n);
            if(i==l){
                res.push_back(1);
                ++i;
            }else{
                int k =i+1;
                while(k<=l){
                    int nl = last(s, s[k], k, n);
                    if(nl>l){
                        l = nl;         
                    }
                    ++k;
                }  
                res.push_back(l-i+1);      
                i = l+1;                    
            }
        }
        return res;       
    }
};