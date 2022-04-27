void dijkstra(vector<vector<vector<ll>>> &adj, vector<vector<ll>> &dis, vector<vector<string>> &path, ll curr)
{
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q1;
    q1.push({0,curr,-1});
    while(!q1.empty())
    {
        ll node = q1.top()[1];
        ll par = q1.top()[2];
        ll distance = q1.top()[0];
        q1.pop();
        if(dis[curr][node]!=LLONG_MAX) continue;
        if(par==-1) path[curr][curr] = to_string(curr);
        else path[curr][node] = path[curr][par] + "->" + to_string(node);
        dis[curr][node] = distance;
        for(ll i=0; i<adj[node].size(); i++)
        {
            ll child = adj[node][i][0];
            ll edge = adj[node][i][1];
            if(dis[curr][child]!=LLONG_MAX) continue;
            q1.push({distance + edge, child, node});
        }
    }
}