//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int ans = 0;
        int left = 0;
        int right = 0;
        while(right < n-1){
            int farthest = 0;
            for(int i = left; i <= right; i++){
                farthest = max(farthest, i+arr[i]);
            }
            if(farthest == 0)
                return -1;
            left = right+1;
            right = farthest;
            ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends