//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X){
        //Your Code Here
        sort(arr, arr+n);
        for(int i = 0; i < n; i++){
            int find = X-arr[i];
            int p1 = i+1;
            int p2 = n-1;
            while(p1 < p2){
                if(arr[p1] + arr[p2] ==  find){
                    return true;
                }
                else if(arr[p1] + arr[p2] < find){
                    p1++;
                }
                else{
                    p2--;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends