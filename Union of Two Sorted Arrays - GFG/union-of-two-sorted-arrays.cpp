//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
        //Your code here
        //return vector with correct order of elements
        vector<int> res;
        int a = 0;
        int b = 0;
        while(a < n && b < m){
            int x = arr1[a];
            int y = arr2[b];
            if(arr1[a] == arr2[b]){
                res.push_back(x);
                while(a < n && arr1[a] == x) a++;
                while(b < m && arr2[b] == y) b++;
            }
            else if(x < y){
                res.push_back(x);
                while(a < n && arr1[a] == x) a++;
            }
            else{
                res.push_back(y);
                while(b < m && arr2[b] == y) b++;
            }
        }
        while(a < n){
            int x = arr1[a];
            res.push_back(arr1[a]);
            while(a < n && arr1[a] == x) a++;
        }
        while(b < m){
            int y = arr2[b];
            res.push_back(arr2[b]);
            while(b < m && arr2[b] == y) b++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends