//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	    const int mod = 1e9+7;
		int NthTerm(int n){
		    // Code  here
		    int ans = 2;
		    if(n == 1) return ans;
		    
		    for(int i = 2; i <= n; i++){
		        ans = (ans*1LL*i + 1)%mod;
		    }
		    return ans%mod;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends