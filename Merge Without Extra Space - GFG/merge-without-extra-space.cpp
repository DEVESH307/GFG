//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) {
            // code here 
            int gap = ceil((float)(n + m) / 2);
            while (gap > 0) {
                int p1 = 0;
                int p2 = gap;
                while (p2 < (n + m)) {
                    if (p2 < n && arr1[p1] > arr1[p2]) {
                        swap(arr1[p1], arr1[p2]);
                    } 
                    else if (p1 < n && p2 >= n && arr1[p1] > arr2[p2 - n]) {
                        swap(arr1[p1], arr2[p2 - n]);
                    } 
                    else if (p1 >= n && p2 >= n && arr2[p1 - n] > arr2[p2 - n]) {
                        swap(arr2[p1 - n], arr2[p2 - n]);
                    }
                    p1++;
                    p2++;
                }
                gap = gap == 1 ? 0 : ceil((float) gap / 2);
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends