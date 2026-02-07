vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dis(V,1e8);
        dis[src] = 0;
        
        for(int i=0;i<V-1;i++)
        {
            for(auto it:edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dis[u]!=1e8 and dis[u]+wt<dis[v])
                {
                    dis[v] = dis[u] + wt;
                }
            }
        }
        
        for(auto it:edges)
        {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dis[u]!=1e8 and dis[u]+wt<dis[v])
                {
                    return {-1};
                }
        }
        return dis;
        
        
    }