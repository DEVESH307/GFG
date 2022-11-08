//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    void sentencesUtil(vector<vector<string>> &list, int row, vector<string> &curr, vector<vector<string>> &res){
        if(row == list.size()){
            res.push_back(curr);
            return;
        }
        for(int col = 0; col < list[0].size(); col++){
            if(list[row][col] != ""){
                curr.push_back(list[row][col]);
                sentencesUtil(list, row+1, curr, res);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> sentences(vector<vector<string>>&list){
        //Write your code here
        vector<vector<string>> res;
        vector<string> curr;
        sentencesUtil(list, 0, curr, res);
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// } Driver Code Ends