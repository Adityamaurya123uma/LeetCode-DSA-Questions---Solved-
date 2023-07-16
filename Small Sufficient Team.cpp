class Solution {
public:

vector<int>res;

void helper(int i,vector<int>&people_skill,int m,int mask,vector<int>&ans,vector<vector<int>>&dp)
{
  if(i == people_skill.size()) //Base Case
  {
    if(mask == ((1<<m)-1)) //Check for all req_skills included
    {
      if(res.size() == 0 || (ans.size() < res.size())) res = ans; //better ans then update
    }
    return;
  }

  if(dp[i][mask] != -1) //Memoization Part
  {
    if(dp[i][mask] <= ans.size()) return;
  }

  helper(i+1,people_skill,m,mask,ans,dp); //Non-Pick / Ignore Case

  ans.push_back(i); // Pick Case

  helper(i+1,people_skill,m,(mask|people_skill[i]),ans,dp); //Next Call

  ans.pop_back(); //Undo the change in Pick

  if(ans.size() > 0) dp[i][mask] = ans.size(); //if found and answer then update DP
}


 vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {

        int n = people.size();
        int m = req_skills.size();

        unordered_map<string,int>mpp; //for hashing skill v/s bit

        for(int i = 0;i<m;++i) mpp[req_skills[i]] = (1<<i); //setting ith bit, for req_skill[i] skill

        vector<int>people_skill; //vector of mask for peoples

        for(auto it : people) 
        {
          int mask = 0;
          for(int j = 0; j < it.size(); ++j)
          {
            if(mpp.count(it[j])) mask |= mpp[it[j]]; //if it[j] is a required skill then set that bit for that people's mask
          }
          people_skill.push_back(mask); //store the mask 
        }

        vector<vector<int>> dp(n, vector<int>((1<<m),-1)); //n=number of people, and (1<<m) to express all value mask of size m can take
        vector<int>ans;

        helper(0,people_skill,m,0,ans,dp);
        return res;
    }
};
