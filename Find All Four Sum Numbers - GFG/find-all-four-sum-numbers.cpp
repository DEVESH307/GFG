//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> res;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                int left_ptr = j+1;
                int right_ptr = n-1;
                while(left_ptr < right_ptr){
                    long long curr_sum = 1LL*arr[i] + 1LL*arr[j] + 1LL*arr[left_ptr] + 1LL*arr[right_ptr]; 
                    if(curr_sum > k)
                        --right_ptr;
                    else if(curr_sum < k)
                        ++left_ptr;
                    else{
                        res.push_back({arr[i], arr[j], arr[left_ptr], arr[right_ptr]});
                        ++left_ptr;
                        --right_ptr;
                        while (left_ptr < right_ptr && arr[left_ptr] == arr[left_ptr-1]) ++left_ptr;
                        while (left_ptr < right_ptr && arr[right_ptr] == arr[right_ptr+1]) --right_ptr;
                    }
                }
                while(j + 1 < n && arr[j] == arr[j+1]) ++j;
            }
            while(i + 1 < n && arr[i] == arr[i+1]) ++i;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends