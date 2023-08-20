class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupId = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = groupId++;
            }
        }
        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i) {
            itemGraph[i] = vector<int>();
        }
        
        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(groupId, 0);
        for (int i = 0; i < groupId; ++i) {
            groupGraph[i] = vector<int>();
        }
        
        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;
                if (group[i] != group[prev]) {
                    groupGraph[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }
        vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);
        
        if (itemOrder.empty() || groupOrder.empty()) {
            return vector<int>();
        }
        unordered_map<int, vector<int>> orderedGroups;
        for (int item : itemOrder) {
            orderedGroups[group[item]].push_back(item);
        }
        
        vector<int> answerList;
        for (int groupIndex : groupOrder) {
            answerList.insert(answerList.end(), orderedGroups[groupIndex].begin(), orderedGroups[groupIndex].end());
        }
        
        return answerList;
    }
    
    vector<int> topologicalSort(unordered_map<int, vector<int>>& graph, vector<int>& indegree) {
        vector<int> visited;
        stack<int> stk;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                stk.push(i);
            }
        }
        
        while (!stk.empty()) {
            int curr = stk.top();
            stk.pop();
            visited.push_back(curr);
            
            for (int n : graph[curr]) {
                indegree[n]--;
                if (indegree[n] == 0) {
                    stk.push(n);
                }
            }
        }

        return visited.size() == graph.size() ? visited : vector<int>();
    }
};
