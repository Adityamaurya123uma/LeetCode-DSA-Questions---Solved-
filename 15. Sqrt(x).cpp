// Binary Search O(logn)
class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int ans = 1;
        if(x==0) return 0;
        while (low <= high){
            long long mid = low + (high-low)/2;
            long long val = mid*mid;
            if(val > x){
                high = mid-1;
            } else {
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};

// Naive Approach
// class Solution {
// public:
//     int mySqrt(int x) {
//         int ans = 1;
//         if(x==0)return 0;
//         for(long i=1;i<x;i++){
//             if(i*i <= x){
//                 ans=i;
//             }else{
//                 break;
//             }
//         }
//         return ans;
//     }
// };
