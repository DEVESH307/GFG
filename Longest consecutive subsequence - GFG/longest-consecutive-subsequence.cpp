//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N){
      //Your code here
      int maxLen = 0;
      unordered_set<int> set;
      for(int i = 0; i < N; i++){
          set.insert(arr[i]);
      }
      for(int i = 0; i < N; i++){
          if(set.find(arr[i]-1) == set.end()){
              int ans = 0;
              int curr = arr[i];
              while(set.find(curr) != set.end()){
                  ans++;
                  curr++;
              }
              maxLen = max(maxLen, ans);
          }
      }
      return maxLen;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends