//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int mergeCount(long long int arr[], long long int left,  long long int mid2, long long int right){
        long long int a = left;
        long long int b = mid2;
        long long int c = 0;
        long long int count = 0;
        long long int temp[right-left+1];
        while(a < mid2 && b <= right){
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
        while(b <= right){
            temp[c] = arr[b];
            c++;
            b++;
        }
        int idx = 0;
        for(int i = left; i <= right; i++)
            arr[i] = temp[idx++];
        return count;
    }
    long long int inversionCountHelper(long long int arr[], long long int left,  long long int right){
        if(left == right){
            return 0;
        }
        long long int mid = (right+left)/2;
        long long int x = inversionCountHelper(arr, left, mid);
        long long int y = inversionCountHelper(arr, mid+1, right);
        long long int z = mergeCount(arr, left, mid+1, right);
        return x+y+z;
    }
    long long int inversionCount(long long int arr[], long long int N){
        // Your Code Here
        // long long int temp[N];
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