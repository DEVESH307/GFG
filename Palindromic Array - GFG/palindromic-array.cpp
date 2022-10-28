//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool isPalindrome(int num){
        string str = to_string(num);
        int low = 0;
        int high = str.size()-1;
        while(low <= high){
            if(str[low] != str[high]){
                return false;
            }
            else{
                low++;
                high--;
            }
            return true;
        }
    }
    int PalinArray(int a[], int n){
    	// code here
    	for(int i = 0; i < n; i++){
    	    if(!isPalindrome(a[i])){
    	        return 0;
    	    }
    	}
    	return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends