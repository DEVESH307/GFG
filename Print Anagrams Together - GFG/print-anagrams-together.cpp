//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string, vector<string>> mp;
        
        for(int i = 0; i < string_list.size(); i++){
            string sorted_str = string_list[i];
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(string_list[i]);
        }
        
        // vector<vector<string>> res(mp.size());
        vector<vector<string>> res;
        // int idx = 0;
        for(auto itr: mp){
            vector<string> temp;
            auto vec = itr.second;
            for(auto v: vec){
                temp.push_back(v);
            }
            res.push_back(temp);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends