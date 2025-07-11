#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// int removeElement(int* nums, int numsSize, int val) {
//     assert(nums);
//     int k = numsSize;
//     for(int i = 0;i<numsSize;i++){
//         if(nums[i] == val){
//             for(int j = i;j<numsSize-1;j++){
//                 nums[j] = nums[j+1];
//             }
//             if(nums[i] == val){
//                 i = i-1;
//             }
//             k--;
//         }
//     }
//     return k;
// }

// int removeElement(int* nums, int numsSize, int val) {
//     assert(nums);
//     int* tmp = nums;
//     int i =0;
//     int j = 0;
//     while (i<numsSize)
//     {
//         if (nums[i]!= val) {
//             nums[j++] = nums[i];
//         }
//         i++;
//     }
    
//     return j;
// }

int removeElement(int* nums, int numsSize, int val) {
    assert(nums);
    int* tmp = (int*)malloc(numsSize*sizeof(int));
    int j= 0; int i = 0;
    while (i < numsSize)
    {
        if (nums[i]!= val) {
            nums[i] = tmp[j];
            j++;
        }
        i++;
    }
    free(tmp);
    tmp = NULL;
    return j;
}

int main(){
    int* arr = (int*)malloc(8*sizeof(int));
    if(arr == NULL){
        perror("malloc");
    }
    for(int i =0;i<8;i++){
        scanf("%d",arr+i);
    }
    int val =0;
    scanf("%d",&val);
    int ret = removeElement(arr,8,val);
    printf("%d",ret);
    free(arr);
    arr = NULL;
}