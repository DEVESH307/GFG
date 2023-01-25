//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    // bool isPalindromeUtil(string str, int start, int end) {
    //     if(start >= end) return true;
        
    //     if(str[start] == str[end])
    //         return isPalindromeUtil(str, start+1, end-1);
    //     else
    //         return false;
    // }
	int isPalindrome(string str){
        // Your code goes here
        // Iterative Solution
        int low = 0;
        int high = str.size()-1;
        while(low <= high){
            if(str[low] != str[high]){
                return 0;
            }
            else{
                low++;
                high--;
            }
        }
        return 1;
        
        //Recursive Solution
        // return isPalindromeUtil(str, 0, str.size()-1);

	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends