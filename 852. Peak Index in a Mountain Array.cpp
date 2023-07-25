class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int index = 0;
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max = arr[i];
                index = i;
            }
        }
        return index;
    }
};
