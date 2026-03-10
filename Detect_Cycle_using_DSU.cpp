class Solution {
  public:
  
  int FindParent(int u,vector<int>&parent)
  {
      if(parent[u] == u) return u;
      
      return parent[u] = FindParent(parent[u], parent);
  }
  
  void Union(int u,int v,vector<int>&parent,vector<int>&rank)
  {
      int ul_pu = FindParent(u,parent);
      int ul_pv = FindParent(v,parent);
      
      if(rank[ul_pu] < rank[ul_pv]) 
      {
          parent[ul_pu] = ul_pv;
      }
       else if(rank[ul_pu] > rank[ul_pv]) 
      {
          parent[ul_pv] = ul_pu;
      }
        else
      {
          parent[ul_pu] = ul_pv;
          rank[ul_pv]++;
      }
  }
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>parent(V,0);
        vector<int>rank(V,0);
        for(int i=0;i<V;i++) parent[i] = i;
        
        for(int u=0;u<V;u++)
        {
            for(auto v:adj[u])
            {
                if(u<v)
                {
                    if(FindParent(u,parent) == FindParent(v,parent))
                    {
                        return 1;
                    }
                    else
                    {
                        Union(u,v,parent,rank);
                    }
                }
            }
        }
        return 0;
    }
};