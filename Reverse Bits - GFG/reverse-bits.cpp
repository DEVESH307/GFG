//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long num) {
        // code here
        long long ans = 0L;
        int bitPos = 1;
        if(num&1 == 1) {
            ans = INT_MAX;
            ans += 1;
        }
        num >>= 1;
        while(num){
            if((num & 1) == 1)
                ans |= 1 << 31-bitPos;
            num >>= 1;
            
            bitPos++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends