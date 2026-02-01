class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(V,1e9);
        pq.push({0,src});
        dis[src] = 0;
        
        vector<pair<int,int>>adj[V];
    
        for(int i=0;i<edges.size();i++)
            {
                int p = edges[i][0];
                int q = edges[i][1];
                adj[p].push_back({edges[i][1],edges[i][2]});
                adj[q].push_back({edges[i][0],edges[i][2]});
            }
        
        while(!pq.empty())
        {
            int preDis = pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                int edgeDis = it.second;
                if(preDis + edgeDis < dis[adjNode])
                {
                    dis[adjNode] = preDis + edgeDis;
                    pq.push({dis[adjNode],adjNode});
                }
            }
            
            
        }
        return dis;
        
 }
};
