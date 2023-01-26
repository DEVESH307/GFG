//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // int count(int nums[], int r, int& mid){
    //     int cnt = 0;
    //     for (int i = 0; i <= r; i++){
    //         if (nums[i] <= mid){
    //             cnt++;
    //         }
    //     }
    //     return cnt;
    // }
    // int kthSmallest(int arr[], int l, int r, int k) {
    //     //code here
    //     // sort(arr, arr+r+1);
    //     // return arr[k-1];
        
    //     // Binary Search Method
    //     int low = INT_MAX;
    //     int high = INT_MIN;
    //     for (int i = 0; i <= r; i++) {
    //         low = min(low, arr[i]);
    //         high = max(high, arr[i]);
    //     }
    //     while (low < high) {
    //         int mid = (low + high)/2;
    //         if (count(arr, r, mid) < k)
    //             low = mid + 1;
    //         else
    //             high = mid;
    //     }
    //     return low;
    // }
    
    //Quick Select Method
    // int partition (int arr[], int low, int high){
    //   // Your code here
    //   int p1 = low+1;
    //   int p2 = high;
    //   while(p1 <= p2){
    //       if(arr[p1] <= arr[low]){
    //           p1++;
    //       }
    //       else if(arr[p2] > arr[low]){
    //           p2--;
    //       }
    //       else{
    //           swap(arr[p1], arr[p2]);
    //           p1++;
    //           p2--;
    //       }
    //   }
    //   swap(arr[low], arr[p1-1]);
    //   return (p1-1);
    // }
    // int kthSmallest(int arr[], int l, int r, int k){
    //     if (k > 0 && k <= r-l+1) {
    //         int index = partition(arr, l, r);
    //         if (index-l == k-1)
    //             return arr[index];
    //         else if (index-l > k-1) 
    //             return kthSmallest(arr, l, index-1, k);
    //         else
    //             return kthSmallest(arr, index+1, r, k-index+l-1);
    //     }
    //     return INT_MAX;
    // }
    
    //Heap Method
    int kthSmallest(int arr[], int l, int r, int k){
        priority_queue<int> pq;
        for(int i = l; i <= r; i++){
            pq.push(arr[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends