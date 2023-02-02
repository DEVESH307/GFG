//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
//Using Recursion
class Solution {
  public:
    int binarySearchHelper(int arr[], int low, int high, int k) {
        // code here
        if(low > high) return -1;
        
        int mid = (low+high)/2;
        
        if(arr[mid] == k) 
            return mid;
        else if(arr[mid] < k)
            return binarySearchHelper(arr, mid+1, high, k);
        else
            return binarySearchHelper(arr, low, mid-1, k);
        
    }
    int binarysearch(int arr[], int n, int k) {
        // code here
        return binarySearchHelper(arr, 0, n-1, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends