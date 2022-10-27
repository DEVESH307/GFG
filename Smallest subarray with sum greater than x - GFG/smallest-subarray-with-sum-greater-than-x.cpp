//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x){
        // Your code goes here   
        long long curr_sum = 0;
        int curr_len = 0;
        int min_len = INT_MAX;
        int start = 0;
        int end = 0;
        while(end < n){
            while(curr_sum <= x && end < n){
                curr_sum += arr[end++];
            }
            while(curr_sum > x && start < n){
                curr_len = end-start;
                min_len = min(min_len, curr_len);
                curr_sum -= arr[start++];
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends