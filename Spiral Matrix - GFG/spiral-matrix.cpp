//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int n, int m, int k){
        // Your code goes here
        vector<int> res;
        int row = n;
        int col = m;
        int top = 0;
        int bottom = row-1;
        int left = 0;
        int right = col-1;
        int count = 0;
        int ans;
        while(top <= bottom && left <= right && res.size() < row*col ){
            for(int i = left; i <= right && res.size() < row*col; i++){
                res.push_back(matrix[top][i]);
                count++;
                if(count == k) return res.back();
            }
            top++;
            for(int i = top; i <= bottom && res.size() < row*col; i++){
                res.push_back(matrix[i][right]);
                count++;
                if(count == k) return res.back();
            }
            right--;
            for(int i = right; i >= left && res.size() < row*col; i--){
                res.push_back(matrix[bottom][i]);
                count++;
                if(count == k) return res.back();
            }
            bottom--;
            for(int i = bottom; i >= top && res.size() < row*col; i--){
                res.push_back(matrix[i][left]);
                count++;
                if(count == k) return res.back();
            }
            left++;
        }
        // return res;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends