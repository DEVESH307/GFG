//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        //Write your code here
        //TC: O(N*N);
        // int res = 0;
        // int i = 0;
        // int j = str.size()-1;
        // int end = j;
        // while(i < j){
        //     if(str[i] == str[j]){
        //         i++;
        //         j--;
        //     }
        //     else{
        //         res++;
        //         i = 0;
        //         j = --end;
        //     }
        // }
        // return res;
        
        //TC: O(N)
        int res = 0;
        int i = 0;
        int j = str.size()-1;
        int end = str.size();
        while(i < j){
            if(str[i] == str[j]){
                i++;
                j--;
            }
            else{
                res = end-j;
                i = 0;
                while(str[i] == str[j]){
                    res--;
                    i++;
                }
                j--;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends