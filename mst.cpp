#include"dsu.cpp"
void mst(vector<vector<vector<ll>>> &adj, unordered_map<ll,ll> &mall, vector<vector<ll>> &distance, ll home)
{
	ll n = adj.size();
	n--;
	vector<vector<ll>> edges;
	vector<vector<vector<ll>>> temp(n+1);
	for(ll i=1; i<=n; i++)
	{
		for(ll j=1; j<=n; j++)
		{
			if(i==j) continue;
			if((mall.find(i)!=mall.end() || home==i) && (mall.find(j)!=mall.end() || home==j))
				edges.pb({distance[i][j],i,j});
		}
	}
	sort(all(edges));
	Union u1;
	u1.initialize(n);
	for(ll i=0; i<edges.size(); i++)
	{
		ll a1 = u1.find(edges[i][1]), a2 = u1.find(edges[i][2]);
		if(a1==a2) continue;
		u1.merge(a1,a2);
		temp[edges[i][1]].pb({edges[i][2], edges[i][0]});
		temp[edges[i][2]].pb({edges[i][1], edges[i][0]});
	}
	swap(adj, temp);
}