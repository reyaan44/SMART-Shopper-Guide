vector<string> readAndPrint(const char *filename) 
{
    vector<string> vect;
    ifstream file(filename);
    if(file.is_open()) 
    {
        string line;
        while(getline(file, line))
        {
            string s = line.c_str();
            string s1 = "";
            for(ll i=0; i<s.length(); i++)
            {
                if(s[i]==' ')
                {
                    if(s1.size()>0) vect.pb(s1);
                    s1 = "";
                }
                else s1.pb(s[i]);
            }
            if(s1.size()>0) vect.pb(s1);
        }
        file.close();
    }
    return vect;
}