//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int *findTwoElement(int *arr, int n){
        int XOR = 0;
        int set_bit_no;
        int i;
        int x = 0;
        int y = 0;
        int* res = new int[2];
    
        for (i = 0; i < n; i++)
            XOR = XOR ^ arr[i];
    
        for (i = 1; i <= n; i++)
            XOR = XOR ^ i;
    
        set_bit_no = XOR & ~(XOR - 1);
    
        for (i = 0; i < n; i++) {
            if (arr[i] & set_bit_no)
                x = x ^ arr[i];
            else
                y = y ^ arr[i];
        }
    
        for (i = 1; i <= n; i++) {
            if (i & set_bit_no)
                x = x ^ i;
            else
                y = y ^ i;
        }
        int count_x = 0;
        for(i = 0; i < n; i++){
            if(arr[i] == x)
                count_x++;
        }
        res[0] = count_x == 2 ? x : y;
        res[1] = count_x == 0 ? x : y;
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends