//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
        
    // inversion count using bubble sort
    // long long int inversionCount(long long int arr[], long long int n){
    //     int inv_cnt = 0;
        
    //     for(int i = 0; i < n; i++){
    //         int no_of_swap = 0;
    //         for(int j = 0; j < n-i-1; j++){
    //             if(arr[j] > arr[j+1]){
    //                 swap(arr[j], arr[j+1]);
    //                 no_of_swap++;
    //             }
    //         }
    //         inv_cnt += no_of_swap;
    //     }
    //     return inv_cnt;
    // }
    
    // inversion count using merge sort
    long long int mergeCount(long long int arr[], long long int low,  long long int mid2, long long int high){
        long long int a = low;
        long long int b = mid2;
        long long int c = 0;
        long long int count = 0;
        long long int temp[high-low+1];
        while(a < mid2 && b <= high){
            if(arr[a] <= arr[b]){
                temp[c] = arr[a];
                c++;
                a++;
            }
            else{
                temp[c] = arr[b];
                c++;
                b++;
                count += (mid2-a);
            }
        }
        while(a < mid2){
            temp[c] = arr[a];
            c++;
            a++;
        }
        while(b <= high){
            temp[c] = arr[b];
            c++;
            b++;
        }
        for(int i = low; i <= high; i++)
            arr[i] = temp[i-low];
        return count;
    }
    long long int inversionCountHelper(long long int arr[], long long int low,  long long int high){
        if(low == high){
            return 0;
        }
        long long int mid = (high+low)/2;
        long long int x = inversionCountHelper(arr, low, mid);
        long long int y = inversionCountHelper(arr, mid+1, high);
        long long int z = mergeCount(arr, low, mid+1, high);
        return x+y+z;
    }
    long long int inversionCount(long long int arr[], long long int N){
        // Your Code Here
        return inversionCountHelper(arr, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends