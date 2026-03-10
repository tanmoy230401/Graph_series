#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;


class DisjointSet
{
	vector<int>rank,parent,size;
	
	public:
	DisjointSet(int n)
	{
		rank.resize(n+1,0);
		parent.resize(n+1,0);
		
		for(int i=0;i<=n;i++)
		{
			parent[i] =i;
		}	
	}
	
	int FindUlparent(int node)
	{
		if(node == parent[node]) return node;
		
		return parent[node] = FindUlparent(parent[node]);
		
	}
	
	void UnionByRank(int u,int v)
	{
		int ul_pu = FindUlparent(u);
		int ul_pv = FindUlparent(v);
		
		if(ul_pu == ul_pv) return;
		
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
			parent[ul_pv] = ul_pu;
			rank[ul_pu]++;
			
		}
	}
	
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
    
    
  DisjointSet ds(7);
  
     ds.UnionByRank(1,2);
     ds.UnionByRank(2,3);
     ds.UnionByRank(4,5);
     ds.UnionByRank(6,7);
     ds.UnionByRank(5,6);
     
     if(ds.FindUlparent(3) == ds.FindUlparent(7))
     {
     	cout<<"Same \n";
     }
     else
     {
     	cout<<"Not Same \n";
     }
     ds.UnionByRank(3,7);
        if(ds.FindUlparent(3) == ds.FindUlparent(7))
     {
     	cout<<"Same \n";
     }
     else
     {
     	cout<<"Not Same \n";
     }
           
  
}
