//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long ans = 0;
        int leftMax[n];
        int rightMax[n];
        leftMax[0] = 0;
        rightMax[n-1] = 0;
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], arr[i-1]);
            rightMax[n-i-1] = max(rightMax[n-i], arr[n-i]);
        }
        for(int i = 0; i < n; i++){
            if(min(leftMax[i], rightMax[i])-arr[i] >= 0){
                ans += min(leftMax[i], rightMax[i])-arr[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends