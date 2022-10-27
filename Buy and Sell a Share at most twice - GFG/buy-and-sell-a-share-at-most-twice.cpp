//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int ans = 0;
    int n = price.size();
    // vector<int> dpl(n,0);
    // vector<int> dpr(n,0);
    int dpl[n];
    int dpr[n];
    for(int i = 0; i < n; i++){
        dpl[i] = 0;
        dpr[i] = 0;
    }
    int minBuy = price[0];
    int maxSell = price[n-1];
    dpl[0] = 0;
    dpr[n-1] = 0;
    for(int i = 1; i < n; i++){
        minBuy = min(minBuy, price[i]);
        dpl[i] = max(dpl[i-1], price[i]-minBuy);
    }
    for(int i = n-2; i >= 0; i--){
        maxSell = max(maxSell, price[i]);
        dpr[i] = max(dpr[i+1], maxSell-price[i]);
    }
    for(int i = 0; i < n; i++){
        ans = max(ans, dpl[i]+dpr[i]);
    }
    return ans;
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends