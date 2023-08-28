#include<iostream>
using namespace std;
void display(int arr[],int n)
{  
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int partition(int arr[], int start, int end){ 

    int pivotIndex=start;
    int i = start+1, j =
	 end;

    do{
        while(arr[i]<=arr[pivotIndex]){
            i++;
        }
        while(arr[j]>arr[pivotIndex]){
            j--;
        }
        if(i<j){
            
            swap(arr[i],arr[j]);
        }
    }
	while(j>i);
    swap(arr[pivotIndex],arr[j]);
    pivotIndex=j;
    return pivotIndex;
}

void quickSort(int arr[],int left, int right){ 
     if(left>=right){
        return;
     }
     int p=partition(arr,left,right);
     quickSort(arr,left,p-1);
     quickSort(arr,p+1,right);
}

int main(){
    int arr[]={40,20,10,80,60,50,7,30,100};
    int n=9;
    cout<<"Original Array: ";
    display(arr,n);

    quickSort(arr,0,n-1);
    cout<<endl<<"Sorted Array: ";
    display(arr,n);
    return 0;

}
