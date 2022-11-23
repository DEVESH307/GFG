//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x ){
    // code here
    //TC: O(N)
    // vector<int> res;
    // int i;
    // int first_index = -1, last_index = -1;
    // for(i = 0; i < n; i++){
    //     if(arr[i] == x){
    //         first_index = i;
    //         last_index = i;
    //         break;
    //     }
    // }
    // while(i < n && arr[i] == arr[i+1]){
    //     last_index = i+1;
    //     i++;
    // }
    // res.push_back(first_index);
    // res.push_back(last_index);
    // return res;
    
    //TC: O(logn)
    vector<int> res;
    int first_index = -1;
    int last_index = -1;
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            first_index = mid;
            high = mid-1;
        }
        else if(arr[mid] > x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    low = 0;
    high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            last_index = mid;
            low = mid+1;
        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    // first_index = arr[first_index] == x ? first_index : -1;
    // last_index = arr[last_index] == x ? last_index : -1;
    
    return {first_index, last_index};
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends