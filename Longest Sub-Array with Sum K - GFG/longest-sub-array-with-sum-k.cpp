//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) { 
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        //add this to write extra line of code
        mp[0] = 0;
        for(int i  = 1; i <= N; i++){
            sum += A[i-1];
            int find = sum-K;
            // if(sum == K){
            //     ans = max(ans, i+1);
            // }
            if(mp.find(find) != mp.end()){
                ans = max(ans, i-mp[find]);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends