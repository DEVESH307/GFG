//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// class Solution {
//   public:
//     int countRevPairs(int n, vector<int> arr) {
//         // Code here
//         int Pairs = 0;
//         for (int i = 0; i < arr.size(); i++) {
//             for (int j = i + 1; j < arr.size(); j++) {
//                 if (arr[i] > 2 * arr[j]){
//                     Pairs++;
//                 }
//             }
//         }
//         return Pairs;
//     }
// };


class Solution {
  public:
    int Merge(vector <int> &arr, int low, int mid, int high) {
        int total = 0;
        int j = mid+1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && arr[i] > 2LL*arr[j]) {
                j++;
            }
            total += (j-(mid+1));
        }
        
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            } 
            else{
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }
        while (right <= high) {
            temp.push_back(arr[right++]);
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i-low];
        }
        return total;
    }
    int MergeSort(vector<int> & arr, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high)/2;
        int x = MergeSort(arr, low, mid);
        int y = MergeSort(arr, mid+1, high);
        int z = Merge(arr, low, mid, high);
        return x+y+z;
    }
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        return MergeSort(arr, 0, arr.size() - 1);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends