/* Code by Reyaan Jagnani (reyaan44) */
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define endl "\n"
#define precision(a) cout<<fixed<<setprecision(a)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
#include"input-file.cpp" // filename
#include"dijkstra.cpp" // adjacency, distance, path, current start node
#include"find_path.cpp" // order, path, home
#include"mst.cpp"   // adj, price, distance, path
#include"preorder.cpp" // adj, a, par, order
int main()
{
    vector<string> input = readAndPrint("map.txt");
    ll nodes = stoll(input[0]), edges = stoll(input[1]), curr = 2, home = 1;
    vector<vector<vector<ll>>> adj(nodes+1);	// adjacency list
    vector<vector<ll>> distance(nodes+1, vector<ll>(nodes+1,LLONG_MAX));
    vector<vector<string>> path(nodes+1, vector<string>(nodes+1));
    unordered_map<ll,ll> price;
    unordered_map<ll,ld> crowd;
    for(ll i=0; i<edges; i++)
    {
        ll a1 = stoll(input[curr++]);
        ll a2 = stoll(input[curr++]);
        ll dis = stoll(input[curr++]);
        adj[a1].pb({a2,dis});
        adj[a2].pb({a1,dis});
    }
    for(ll i=1; i<=nodes; i++)
    {
    	precision(2);
    	ld density = stold(input[curr++]);
    	crowd[i] = density;
    }
    cout<<"ENTER THE INDEX FOR YOUR HOME : ";
    cin>>home;
    cout<<endl;
    cout<<"ENTER THE NUMBER OF MALLS YOU WOULD LIKE TO VISIT : ";
    ll number_of_malls;
    cin>>number_of_malls;
    cout<<endl;
    for(ll i=1; i<=number_of_malls; i++)
    {
    	cout<<"ENTER THE INDEX OF THE MALL YOU WANT TO VISIT : ";
    	ll index;
    	cin>>index;
    	cout<<"ENTER THE MONEY YOU WILL SPEND IN THE MALL NUMBER "<<index<<" : ";
    	ll money;
    	cin>>money;
    	if(index==home) 
    	{
    		cout<<"INVALID INDEX. NOT A MALL. TERMINATING";
    		return 0;
    	}
    	price[index] = money;
    	cout<<endl;
    }
    cout<<endl;
    for(ll i=1; i<=nodes; i++)
    	dijkstra(adj, distance, path, i);
    bool weather = 0;
    cout<<"IS THE WEATHER OUTSIDE EXTREME ?\nPRESS 0 FOR NO | PRESS 1 FOR YES : ";
    cin>>weather;
    cout<<endl;
    if(weather)
    {
        cout<<"THE WEATHER CONDITIONS ARE SEVERE.\nWOULD YOU LIKE TO CONTINUE?\nPress 0 for No\nPress 1 for Yes\n";
        bool forward;
        cin>>forward;
        if(!forward) 
            return 0;
        cout<<"WE WILL HIGHLY RECOMMEND YOU TO ONLY VISIT TO THESE STORES DUE TO THE EXTREME WEATHER CONDITIONS.\n";
        vector<pair<ll,ll>> stores;
        for(auto itr: price)
                stores.pb({distance[home][itr.ff], itr.ff});
        sort(all(stores));
        vector<ll> temp;
        while(stores.size() && stores.size()>(price.size()+1)/2 && stores.back().ff>5)
        {
            temp.pb(stores.back().ss);
            stores.pop_back();
        }
        for(ll i=0; i<stores.size(); i++) 
            cout<<"STORE "<<stores[i].ss<<endl;
        cout<<"Press 1 to visit these stores\nPress 0 to visit all the stores\n";
        cin>>forward;
        if(forward)
        {
            for(ll i=0; i<temp.size(); i++)
                price.erase(temp[i]);
        }
    	mst(adj, price, distance, home);
        vector<ll> order;
        preorder(adj, home, -1, order);
        get_path(order, path, home);
    }
    else
    {
    	cout<<"WHAT WILL BE YOUR PREFFERED CHOICE : \n";
    	cout<<"PRESS 1 FOR COST EFFECTIVE FIRST\n";
    	cout<<"PRESS 2 FOR LESS CROWD DENSITY\n";
    	cout<<"PRESS 3 FOR LESS TRAVEL\n";
    	ll choice;
    	cin>>choice;
    	cout<<endl;
    	if(choice==1)
    	{
    		vector<pair<ll,ll>> sequence;
    		for(auto itr: price)
    			sequence.pb({itr.ss, itr.ff});
    		sort(all(sequence));
    		vector<ll> order;
    		for(ll i=0; i<sequence.size(); i++)
    			order.pb(sequence[i].ss);
    		cout<<endl;
    		get_path(order, path, home);
    	}
    	else if(choice==2)
    	{
    		vector<pair<ld,ll>> sequence;
    		for(auto itr: crowd)
    			sequence.pb({itr.ss, itr.ff});
    		sort(all(sequence));
    		cout<<endl;
    		vector<ll> order;
    		for(ll i=0; i<sequence.size(); i++)
    			order.pb(sequence[i].ss);
    		get_path(order, path, home);
    	}
    	else
    	{
            mst(adj, price, distance, home);
            vector<ll> order;
            preorder(adj, home, -1, order);
            get_path(order, path, home);
    	}
    }
    return 0;
}
/*


1. Binary Search / Binary Search on Answer
2. Bit
3. Parity (Odd / Even)
4. DP / Greedy
5. Graph / Bi-Partite
*/