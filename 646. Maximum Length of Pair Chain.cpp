class Solution {
public:
 static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
         sort(pairs.begin(),pairs.end(),compare);
        int prev=0;
        int res=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[prev][1]<pairs[i][0]){
                prev=i;
                res++;
            }
        }
        return res;
    }
};
