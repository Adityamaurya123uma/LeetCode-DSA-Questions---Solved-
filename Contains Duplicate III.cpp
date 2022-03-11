class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k==0){
            return false;
        }
        else{
            
            vector<pair <long long int,int>> vec;
            
            for(int i=0;i<nums.size();i++){
                vec.push_back(make_pair(nums[i],i));
            }
            
            sort(vec.begin(),vec.end());
               
            for(int i=0;i<nums.size()-1;i++){
                
                for(int j=i+1;j<nums.size();j++){
                
                if(abs(vec[i].first-vec[j].first)<=t)
                {
                    if(abs(vec[i].second-vec[j].second)<=k)return true;
                }
                else
                {
                    break;
                }
                
                }
               
                
            }
            
            return false;
        }
            
    }
};