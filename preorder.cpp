void preorder(vector<vector<vector<ll>>> &adj, ll a, ll par, vector<ll> &order)
{
	order.pb(a);
	for(ll i=0; i<adj[a].size(); i++)
	{
		ll child = adj[a][i][0];
		if(child==par) continue;
		preorder(adj, child, a, order);
	}
}