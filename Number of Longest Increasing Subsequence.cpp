class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> lengths(n, 1); 
        vector<int> counts(n, 1); 
        vector<int> bit(n + 1, 0); 

        int max_length = 1; 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (lengths[j] + 1 > lengths[i]) {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    } else if (lengths[j] + 1 == lengths[i]) {
                        counts[i] += counts[j];
                    }
                }
            }
            max_length = max(max_length, lengths[i]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (lengths[i] == max_length) {
                result += counts[i];
            }
        }

        return result;
    }
};
