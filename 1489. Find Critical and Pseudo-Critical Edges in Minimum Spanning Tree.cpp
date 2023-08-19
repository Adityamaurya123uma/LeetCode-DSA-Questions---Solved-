class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int p) {
        return parent[p] == p ? p : (parent[p] = findParent(parent[p]));
    }

    void unionSets(int u, int v) {
        int pu = findParent(u), pv = findParent(v);
        parent[pu] = pv;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical;
        vector<int> pseudoCritical;
        
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int mstwt = findMST(n, edges, -1, -1);

        for (int i = 0; i < edges.size(); i++) {
            if (mstwt < findMST(n, edges, i, -1))
                critical.push_back(edges[i][3]);
            else if (mstwt == findMST(n, edges, -1, i))
                pseudoCritical.push_back(edges[i][3]);
        }

        vector<vector<int>> result;
        result.push_back(critical);
        result.push_back(pseudoCritical);
        return result;
    }

    int findMST(int n, vector<vector<int>>& edges, int block, int e) {
        UnionFind uf(n);
        int weight = 0;

        if (e != -1) {
            weight += edges[e][2];
            uf.unionSets(edges[e][0], edges[e][1]);
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == block)
                continue;

            if (uf.findParent(edges[i][0]) == uf.findParent(edges[i][1]))
                continue;

            uf.unionSets(edges[i][0], edges[i][1]);
            weight += edges[i][2];
        }

        for (int i = 0; i < n; i++) {
            if (uf.findParent(i) != uf.findParent(0))
                return INT_MAX;
        }

        return weight;
    }
};
