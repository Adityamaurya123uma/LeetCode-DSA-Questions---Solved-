class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> m;

        for(auto& ticket: tickets) m[ticket[0]].push_back(ticket[1]);

        for(auto& [_, it] : m) sort(it.rbegin(), it.rend());

        stack<string> st;
        st.push("JFK");

        vector<string> ans;

        while(!st.empty()){
            string s = st.top();

            if(m.find(s) != m.end() && !m[s].empty()) {
                st.push(m[s].back());
                m[s].pop_back();
            } else {
                ans.push_back(st.top());
                st.pop();
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
