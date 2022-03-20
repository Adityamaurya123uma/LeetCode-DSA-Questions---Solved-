class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
         int n=tops.size();
        int countA=0;
        int countB=0;
        for(int i=0;i<n;i++){
            if(tops[i]==tops[0] || bottoms[i]==tops[0]){
                if(tops[i]!=tops[0])
                    countA++;
                if(bottoms[i]!=tops[0])
                    countB++;
                if(i==n-1)
                    return min(countA,countB);
            }else{
                break;
            }
        }
        countA=0;
        countB=0;
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[0] || bottoms[i]==bottoms[0]){
                if(tops[i]!=bottoms[0])
                    countA++;
                if(bottoms[i]!=bottoms[0])
                    countB++;
                if(i==n-1)
                    return min(countA,countB);
            }else{
                break;
            }
        }
        return -1;
    
    }
};