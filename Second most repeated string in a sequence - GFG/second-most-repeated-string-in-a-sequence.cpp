//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n){
        //code here.
        pair<string, int> mx = {"", INT_MIN};
        pair<string, int> second_mx = {"", INT_MIN};
        unordered_map<string, int> map;
        for(int i = 0; i < n; i++){
            map[arr[i]]++;
        }
        for(auto itr: map){
            if(itr.second > mx.second){
                second_mx.first = mx.first;
                second_mx.second = mx.second;
                mx.first = itr.first;
                mx.second = itr.second;
            }
            else if (itr.second > second_mx.second){
                second_mx.first = itr.first;
                second_mx.second = itr.second;
            }
        }
        return second_mx.first;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends