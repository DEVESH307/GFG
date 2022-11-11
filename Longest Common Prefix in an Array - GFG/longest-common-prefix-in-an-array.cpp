//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n){
        // your code here
        sort(arr, arr+n);
        string ans;
        for(int i = 0; i < arr[0].size(); i++){
            string first = arr[0];
            string last = arr[n-1];
            if(first[i] == last[i]){
                ans.push_back(first[i]);
            }
            else{
                break;
            }
        }
        return ans.size() ? ans : "-1";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends