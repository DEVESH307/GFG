//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    public:
    int select(int arr[], int i){
        // code here such that selectionSort() sorts arr[]
        return arr[i];
    }
     
    void selectionSort(int arr[], int n){
        // //code here
        // for(int i = 0; i < n-1; i++){
        //   int minIdx = i;
        //     for(int j = i+1; j < n; j++){
        //         if(arr[j] < arr[minIdx]){
        //             minIdx = j;
        //         }
        //     }
        //   swap(arr[i],arr[minIdx]);
        // }
    
        // Not a stable sort
        // for(int i = 0; i < n; i++){
        //       int minIdx = -1;
        //       int min = INT_MAX;
        //         for(int j = i; j < n; j++){
        //             if(arr[j] < min){
        //                 min = arr[j];
        //                 minIdx = j;
        //             }
        //         }
        //       swap(arr[i],arr[minIdx]);
        //     }
        // }
    
        // Stable sort
        // insert all the element which is less than arr[minIdx] put at last
        for(int i = 0; i < n-1; i++){
          int minIdx = i;
            for(int j = i+1; j < n; j++){
                if(arr[j] < arr[minIdx]){
                    minIdx = j;
                }
            }
            int key = arr[minIdx];
            while(minIdx > i){
                arr[minIdx] = arr[minIdx-1];
                minIdx--;
            }
            arr[i] = key;
        }
    }
    
    
    
};

//{ Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends