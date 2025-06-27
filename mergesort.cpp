#include <iostream>

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


mergesort(arr,0,4);
for(int i :arr){

cout<< i<<endl;



}




}