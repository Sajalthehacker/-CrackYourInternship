// { Driver Code Starts
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
    void quickSort(int arr[], int low, int high)
   {
       // code here
       if(low<high){
       int p=partition(arr,low,high);
       quickSort(arr,low,p);
       quickSort(arr,p+1,high);
           
       }
   }
   
   
   int partition (int arr[], int low, int high)
   {
       int pivot=arr[low];
       int i=low-1;
       int j=high+1;
       while(true){
           do{
               i++;
           }while(arr[i]<pivot);
           do{
               j--;
           }while(arr[j]>pivot);
           if(i>=j){
               return j;
           }
           int temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
       }
   }
};


// { Driver Code Starts.
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
}  // } Driver Code Ends