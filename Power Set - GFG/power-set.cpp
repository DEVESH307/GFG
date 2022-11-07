//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void AllPossibleStringsUtil(string &str, int index, string &curr, vector<string> &res){
		    if(index == str.size()){
		        res.push_back(curr);
		        return;
		    }
		    curr.push_back(str[index]);
		    AllPossibleStringsUtil(str, index+1, curr, res);
		    curr.pop_back();
		    AllPossibleStringsUtil(str, index+1, curr, res);
		    
		}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    //  sort(s.begin(), s.end());
		    vector<string> res;
		    string curr;
		    AllPossibleStringsUtil(s, 0, curr, res);
		    sort(res.begin(), res.end());
		    res.erase(res.begin());
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends