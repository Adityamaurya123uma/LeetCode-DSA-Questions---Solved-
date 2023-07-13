class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        // Build the graph and calculate the incoming edges (inDegree) for each node
        for (auto& pre : prerequisites) {
            int u = pre[0], v = pre[1];
            graph[v].insert(u);
            inDegree[u]++;
        }
        
        queue<int> q;
        
        // Add nodes with zero incoming edges to the queue
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int visited = 0;  // Counter for visited nodes
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited++;
            
            // Decrease the incoming edge count for the neighbors
            for (int neighbor : graph[curr]) {
                inDegree[neighbor]--;
                
                // If a neighbor has zero incoming edges, add it to the queue
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return visited == numCourses;
    }
};
