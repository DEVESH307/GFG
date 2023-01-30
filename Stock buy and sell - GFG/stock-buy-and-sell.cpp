//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    vector<vector<int>> res;
    int mxProfit = 0;
    for(int i = 1; i < n; i++){
        int start = i-1;
        while(i < n && price[i-1] < price[i]){
            i++;
        }
        if(start != i-1) res.push_back({start, i-1});
    }
    if(res.empty()){
        cout << "No Profit" << endl;
        return;
    }
    for (auto itr : res){
        cout<<"("<<itr[0]<<" "<<itr[1]<<") ";
    }
    cout << endl;
}