//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        // vector<int> vec = {A, B, C};
        // sort(vec.begin(), vec.end());
        // return vec[1];
        // int mod=pow(10,9)+7;
        // long long a=A-B,b=B-C,c=C-A;
        // if((a*b)%mod>0){
        //     return B;
        // }
        // if((b*c)%mod>0){
        //     return C;
        // }
        // else{
        //     return A;
        // }
        int mx = max({A, B, C});
        int mn = min({A, B, C});
        
        return (A+B+C)-(mx+mn);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}
// } Driver Code Ends