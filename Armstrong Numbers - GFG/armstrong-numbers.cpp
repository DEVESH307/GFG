//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int ans = 0;
        int num_of_digits = 0;
        int temp = n;
        while(temp){
            temp /= 10;
            num_of_digits++;
        }
        temp = n;
        while(temp){
            ans += pow(temp%10, num_of_digits);
            temp /= 10;
        }
        if(ans == n) return "Yes";
        else return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends