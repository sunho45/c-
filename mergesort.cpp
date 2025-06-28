#include <iostream>
# include "sort.h"
using namespace std;
void merge( int *arr,int start,int end){
int mid=start+(end-start)/2;
int n1=mid-start+1;
int n2=end-mid;
int *l=new int[n1];
int *r=new int[n2];
int i=0,j=0,k=0;


for(int i=0;i<n1;i++){

l[i]=arr[start+i];



}
for(int i=0;i<n2;i++){

r[i]=arr[mid+1+i];



}


while(i<n1&&j<n2){
if(l[i]<=r[j]){

arr[start+k++]=l[i++];
}
else{
arr[start+k++]=r[j++];
}
}
while(i<n1){
arr[start+k++]=l[i++];

}
while(j<n2){
arr[start+k++]=r[j++];

}





}
void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;



}
void quicksort(int *arr, int start ,int end){




if(start<end){
int left=start;
int right=end;
int mid=start+(end-start)/2;
int pivot=arr[mid];

while(left<=right){
    while(arr[left]<pivot){
        left++;
    }
    while(arr[right]>pivot){
        right--;
    }

   if (left <= right) {
            swap(arr + left, arr + right);
            left++;
            right--;
        }
}
quicksort(arr,start,right);
quicksort(arr,left,end);
}

}










void mergesort(int *arr, int start, int end){
if(start<end){
int mid=start+(end-start)/2;

mergesort(arr,start,mid);
mergesort(arr,mid+1,end);
merge(arr,start,end);






}










}
int main(){

int arr[5]{5,7,2,3,8};


quicksort(arr,0,4);
int t=0;
for(int i :arr){

cout<<t<<" "<< i<<endl;
t++;


}




}