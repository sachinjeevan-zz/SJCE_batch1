#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    scanf("%d",&key);
    int start=0,end=n-1,flag=0,index;
    int mid=(start+end)/2;
    if(arr[start]==key){
        flag=1;
        index=start;
    }
    else if(arr[end]==key){
        flag=1;
        index=end;
    }
    while(flag==0 &&(mid!=start && mid!=end)){
        if(arr[mid]==key){
            flag=1;
            index=mid;
        }
        else if(key >arr[mid]){
            start=mid;
            mid=(start+end)/2;
        }
        else{
            end=mid;
            mid=(start+end)/2;
        }
    }
    if(flag==0){
        printf("Element is not found");
    }
    else{
        printf("%d is found at index %d",key,index);
    }
}