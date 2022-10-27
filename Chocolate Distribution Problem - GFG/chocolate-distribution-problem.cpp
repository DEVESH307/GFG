//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> arr, long long n, long long m){
    //code
        // long long minDiff = a[n-1]-a[0];
        // sort(a.begin(), a.end());
        // for(int i = 0; i <= n-m; i++){
        //     minDiff = min(minDiff, a[i+m-1]-a[i]);
        // }
        // return minDiff;
        if (m == 0 || n == 0)
        return 0;
 
        // Sort the given packets
        sort(arr.begin(), arr.end());
     
        // Number of students cannot be more than
        // number of packets
        if (n < m)
            return -1;
     
        // Largest number of chocolates
        long long min_diff = INT_MAX;
     
        // Find the subarray of size m such that
        // difference between last (maximum in case
        // of sorted) and first (minimum in case of
        // sorted) elements of subarray is minimum.
     
        for (int i = 0; i + m - 1 < n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            if (diff < min_diff)
                min_diff = diff;
        }
        return min_diff;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends