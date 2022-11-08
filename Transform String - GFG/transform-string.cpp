//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B){
        //code here.
        int res_cnt = 0;
        int len_A = A.size();
        int len_B = B.size();
        if(len_A != len_B) return -1;
        
        // int asci_sum_A = 0;
        // int asci_sum_B = 0;
        // for(auto ch: A){
        //     asci_sum_A += ch;
        // }
        // for(auto ch: B){
        //     asci_sum_B += ch;
        // }
        // if(asci_sum_A != asci_sum_B) return -1;
        
        int map_A[256] = {0};
        int map_B[256] = {0};
        for(int i = 0; i < len_A; i++){
            map_A[A[i]]++;
            map_B[B[i]]++;
        }
        for(int i = 0; i < 256; i++){
            if(map_A[i] != map_B[i]){
                return -1;
            }
        }
        
        int p1 = len_A-1;
        int p2 = len_B-1;
        
        while(p1 >= 0){
            if(A[p1] == B[p2]){
                p1--;
                p2--;
            }
            else{
                res_cnt++;
                p1--;
            }
        }
        return res_cnt;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends