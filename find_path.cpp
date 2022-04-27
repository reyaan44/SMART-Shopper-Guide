void get_path(vector<ll> &vect, vector<vector<string>> &path, ll &home)
{
	cout<<endl;
	cout<<"PATH = ";
	vect.pb(home);
	cout<<path[home][vect[0]];
	ll prev = vect[0];
	for(ll i=1; i<vect.size(); i++)
	{
		string s = path[vect[i-1]][vect[i]];
		ll j = 0;
		while(j<s.length() && s[j]!='-') j++;
		while(j<s.length())
			cout<<s[j++];
	}
	cout<<endl;
}