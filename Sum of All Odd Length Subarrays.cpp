class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& a) {
        int n=a.size();
        int sum=0;
        
        for(int i=0;i<n;i+=2){
            for(int j=0;j<n;j++){
                if(j+i<n){
                    for(int k=0;k<=i;k++){
                        sum+=a[j+k];
                    }
                }
            }
        }
        
        return sum;
    }
};