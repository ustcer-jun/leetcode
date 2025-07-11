#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    assert(nums1 &&nums2);
    int count = nums1Size-1;
    int i = m-1;
    int j = n-1;
    while (i>=0&&j>=0)
    {
        if(nums1[i]>nums2[j]){
            nums1[count--] = nums1[i--];
        }
        else{
            nums1[count--] = nums2[j--];
        }
    }
    while (j>=0)
    {
        nums1[count--] = nums2[j--];

    }
}


int main(){
    int* arr1 = (int*)malloc(10*sizeof(int));
    int* arr2 = (int*)malloc(5*sizeof(int));
    if(arr1 == NULL ||arr2 == NULL){
        perror("malloc");
    }
    for(int i = 0;i<10;i++){
        scanf("%d",arr1+i);
    }

    for(int j = 0;j<5;j++){
        scanf("%d",arr2+j);
    }
    merge(arr1,10,5,arr2,5,5);
    for(int i = 0;i<10;i++){
        printf("%d ",arr1[i]);
    }
}