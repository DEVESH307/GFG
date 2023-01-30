//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int numRows) {
        // code here
        vector<ll> res;
        for (int i = 0; i < numRows; i++) {
            vector<ll> curr;
            for (int j = 0; j <= i; j++) {
                if(j == 0 || j == i){
                    curr.push_back(1);
                }
                else{
                    ll val = (res[j-1]%1000000007 + res[j]%1000000007)%1000000007;
                    curr.push_back(val);
                }
            }
            res = curr;
        }
        return res;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends