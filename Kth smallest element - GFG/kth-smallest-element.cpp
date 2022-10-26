//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    int count(int nums[], int r, int& mid){
        // function to calculate number of elements less than
        // equal to mid
        int cnt = 0;
     
        for (int i = 0; i <= r; i++)
            if (nums[i] <= mid)
                cnt++;
     
        return cnt;
    }
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        // sort(arr, arr+r+1);
        // return arr[k-1];
        int low = INT_MAX;
        int high = INT_MIN;
        // calculate minimum and maximum the array.
        for (int i = 0; i <= r; i++) {
            low = min(low, arr[i]);
            high = max(high, arr[i]);
        }
        // Our answer range lies between minimum and maximum
        // element of the array on which Binary Search is
        // Applied
        while (low < high) {
            int mid = low + (high - low) / 2;
            /*if the count of number of elements in the array
              less than equal to mid is less than k then
              increase the number. Otherwise decrement the
              number and try to find a better answer.
            */
            if (count(arr, r, mid) < k)
                low = mid + 1;
     
            else
                high = mid;
        }
     
        return low;
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