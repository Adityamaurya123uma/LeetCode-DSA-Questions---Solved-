class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word2.size(),n=word1.size();
        vector<int>pre(m+1),cur(m+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word1[i]==word2[j]){
                    cur[j+1]=pre[j]+1;
                }
                else{
                    cur[j+1]=max(pre[j+1],cur[j]);
                }
            }
            pre=cur;
        }
        return m+n-2*cur[m];
    }
};

 