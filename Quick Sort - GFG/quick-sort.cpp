//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    int partition (int arr[], int low, int high){
       // Your code here
       int p1 = low+1;
       int p2 = high;
       while(p1 <= p2){
           if(arr[p1] <= arr[low]){
               p1++;
           }
           else if(arr[p2] > arr[low]){
               p2--;
           }
           else{
               swap(arr[p1], arr[p2]);
               p1++;
               p2--;
           }
       }
       swap(arr[low], arr[p1-1]);
       return (p1-1);
    }
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high){
        // code here
        if(low >= high) return;
        
        int idx = partition(arr, low, high);
        quickSort(arr, low, idx-1);
        quickSort(arr, idx+1, high);
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends