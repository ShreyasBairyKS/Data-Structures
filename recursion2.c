#include <stdio.h>
int binary(int a[],int low,int high,int key){
    if(low>high){
        return -1;
    }
    int mid=(low+high)/2;
    if(a[mid]==key){
        return a[mid];
    }
    else if(a[mid]<key){
        return binary(a,mid+1,high,key);
    }
    else{
        return binary(a,low,mid,key);
    }
}
int findmin(int a[],int start,int end){
    if(end==start){
        return a[start];
    }
    int mid=(start+end)/2;
    int x=findmin(a,start,mid);
    int y =findmin(a,mid+1,end);
    if(x<=y){
        return x;
    }
    else{
        return y;
    }
}
int main(){
    int a[5]={1,2,3,4,5};
    int key = 3;
    int r=binary(a,0,4,3);
    if(!r){
        printf("key not found");
    }else{
        printf("key found");
    }
    int n=findmin(a,0,4);
    printf("Min value is %d",n);
}