//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n){
        // your code here
        int count_ME = 0;
        int ME = arr[0];
        int meCnt = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] == ME){
                meCnt++;
            }
            else{
                meCnt--;
                if(meCnt == 0){
                    ME = arr[i];
                    meCnt = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == ME){
                count_ME++;
            }
        }
        return count_ME > n/2 ? ME : -1;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends