//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    // int searchInSorted(int arr[], int N, int K) { 
    //   // Your code here
    //   // Liner search;
    //   int ans = -1;
    //   for(int i = 0; i < N; i++){
    //       if(arr[i] == K) ans = 1;
    //   }
    //   return ans;
    // }
    
    int searchInSorted(int arr[], int N, int K) { 
      // Your code here
      // Binary search;
      int ans = -1;
      int low = 0;
      int high = N-1;
      while(low <= high){
          int mid = (low+high)/2;
          if(arr[mid] == K){
              ans = 1;
              break;
          }
          else if(arr[mid] < K){
              low = mid+1;
          }
          else{
              high = mid-1;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends