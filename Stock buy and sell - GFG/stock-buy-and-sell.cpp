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
// void stockBuySell(int price[], int n) {
//     int i = 0;
//     if(n ==  1)
//         return;
//     while(i < n-1){
//         while ((i < n - 1) && (price[i + 1] <= price[i]))
//             i++;
//         if(i == n-1)
//             break;
//         int buy = i++;
        
//         while ((i < n) && (price[i] >= price[i - 1]))
//             i++;
//         int sell = i - 1;
//         cout<<"("<<buy<<" "<<sell<<") ";
//     }
// }

void stockBuySell(int price[], int n) {
    vector<vector<int>> ans;
    for (int i = 1; i < n; i++){
        vector<int> temp;
        if (price[i] > price[i-1]){
            temp.push_back(i-1);
            i++;
            while (i < n){
                if (price[i] >= price[i-1]){
                    i++;
                }
                else break;
            }
            temp.push_back(i-1);
            ans.push_back(temp);
        }
    }
    if(ans.empty()){
        cout << "No Profit" << endl;
        return;
    }
    for (auto i : ans){
        cout<<"("<<i[0]<<" "<<i[1]<<") ";
    }
    cout << endl;
}