//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long maxProduct = *max_element(arr.begin(), arr.end());
	    long long currMax = 1;
	    long long currMin = 1;
	    for(auto a: arr){
	        if(a == 0){
	            currMax = 1;
    	        currMin = 1;
	        }
	        else{
	            long long currMaxTemp = currMax;
	            long long currMinTemp = currMin;
	            currMax = max({a*currMaxTemp, a*currMinTemp, (long long)a});
	            currMin = min({a*currMaxTemp, a*currMinTemp, (long long)a});
	            maxProduct = max(maxProduct, currMax);
	        }
	    }
	    return maxProduct;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends