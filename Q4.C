#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int removeDuplicates(int* nums, int numsSize) {
    assert(nums);
    int i =1;int j =0;
    while (i<numsSize)
    {
        if(nums[j] != nums[i]){
            j++;
            nums[j] = nums[i];
        }
        i++;
    }
    return j+1;
}

int main(){
    int* arr = (int*) malloc(8*sizeof(int));
    if(arr == NULL){
        perror("malloc");
    }
    for (int i = 0; i <8; i++)
    {
        scanf("%d",arr+i);
    }
    int ret = removeDuplicates(arr,8);
    printf("%d",ret);
    free(arr);
    arr = NULL;
}