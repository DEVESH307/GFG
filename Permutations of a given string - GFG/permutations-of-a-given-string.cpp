//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    void findPermutationUtil(string &str, int start, vector<string> &res){
            if(start == str.size()){
                res.push_back(str);
                return;
            }
            for(int index = start; index < str.size(); index++){
                if(index+1 < str.size() && str[index] == str[index+1]){
                    continue;
                }
                else{
                    swap(str[start], str[index]);
                    findPermutationUtil(str, start+1, res);
                    swap(str[start], str[index]);
                }
            }
	    }
        vector<string>find_permutation(string str){
            // Code here there
            sort(str.begin(), str.end());
            vector<string> res;
            findPermutationUtil(str, 0, res);
            sort(res.begin(), res.end());
            return res;
        }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends