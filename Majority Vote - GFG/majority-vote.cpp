//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        vector<int> res;
        int required_count = n/3;
        unordered_map<int, int> mp;
        for(auto num: nums){
            mp[num]++;
        }
        for(auto itr: mp){
            if(itr.second > required_count){
                res.push_back(itr.first);
            }
        }
        sort(res.begin(), res.end());
        if(res.size() == 0){
            return {-1};
        }
        else{
            return res;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends