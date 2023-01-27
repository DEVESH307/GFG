//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    // Using set
    int remove_duplicate(int arr[],int n){
        // code here
        set<int> set;
        for(int i = 0; i < n; i++){
            set.insert(arr[i]);
        }
        int k = 0;
        for(auto num: set){
            arr[k++] = num;
        }
        return set.size();
    }
    
    // No etra space
    // int remove_duplicate(int arr[],int n){
    //     int k = 1;
    //     for(int i = 1; i < n; i++){
    //         if(arr[i-1] != arr[i]){
    //             arr[k] = arr[i];
    //             k++;
    //         }
    //     }
    //     return k;
    // }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends