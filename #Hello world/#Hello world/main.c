//
//  main.c
//  #Hello world
//
//  Created by wan on 2017. 8. 9..
//  Copyright © 2017년 wan. All rights reserved.
//
#include <stdio.h>


int test();

int basearch(int arr[],int left,int right,int target){
    
    int mid;
    mid =  (left + right)/2 ;
    if(left > right){
        return -1;
    }
    
    if(arr[mid] == target){
        return mid;
    }else if(target<arr[mid]){
        return basearch(arr,left,mid-1,target);
    }else{
       return basearch(arr,mid+1,right,target);
    }
}

int main(int argc, const char * argv[]) {
    test();
    // insert code here...
    printf("Hello, World!\n");
    int ar[] = {1,3,5,7,9,10,13,16,18,25,33,34};
    int test = sizeof(ar)/sizeof(int)-1;
    printf("%d zxcv",test);
    int s = basearch(ar,0, sizeof(ar)/sizeof(int)-1,18);
    if(s == -1){
        printf("인자없음\n");
    }else{
        printf("%d <<이게인자\n",s);
    }
    return 0;
}


