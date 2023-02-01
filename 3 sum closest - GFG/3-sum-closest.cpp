//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int arr[], int n, int x){
        // code here
        int ans = INT_MIN;
        int diff = INT_MAX;
        sort(arr, arr+n);
        for(int i = 0; i < n-2; i++){
            int low = i+1;
            int high = n-1;
            while(low < high){
                int sum = arr[i]+arr[low]+arr[high];
                if(abs(sum-x) < diff){
                    // ans = max(ans, sum);
                    ans = sum;
                    diff = abs(sum-x);
                }
                if(sum < x){
                    low++;
                }
                else{
                    high--;
                }
            }
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends