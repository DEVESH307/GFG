//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution {
//   public:
//     vector<int> Solve(int n, vector<int>& nums) {
//         // Code here
//         vector<int> res;
//         int required_count = n/3;
//         unordered_map<int, int> mp;
//         for(auto num: nums){
//             mp[num]++;
//         }
//         for(auto itr: mp){
//             if(itr.second > required_count){
//                 res.push_back(itr.first);
//             }
//         }
//         sort(res.begin(), res.end());
//         if(res.size() == 0){
//             return {-1};
//         }
//         else{
//             return res;
//         }
//     }
// };

class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        vector<int> res;
        int majorityElem1 = -1;
        int majorityElem2 = -1;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == majorityElem1){
                count1++;
            }
            else if(nums[i] == majorityElem2){
                count2++;
            }
            else if(count1 == 0){
                count1++;
                majorityElem1 = nums[i];
            }
            else if(count2 == 0){
                count2++;
                majorityElem2 = nums[i];
            }
            
            else{
                count1--;
                count2--;
            }
        }
        int countMajorityElem1 = 0;
        int countMajorityElem2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == majorityElem1){
                countMajorityElem1++;
            }
            else if(nums[i] == majorityElem2){
                countMajorityElem2++;
            }
        }
        if(countMajorityElem1 > n/3) res.push_back(majorityElem1);
        if(countMajorityElem2 > n/3) res.push_back(majorityElem2);
        
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