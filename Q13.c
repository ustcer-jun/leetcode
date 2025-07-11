#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int singleNumber(int* nums, int numsSize) {
    assert(nums);
    int ret = 0;
    for(int i = 0;i<32;i++){
        int bit_counts = 0;
        for(int j = 0;j<numsSize;j++){
            if((nums[j]>>i)&1){
                bit_counts++;
            }
        }
        if (bit_counts%3)
        {
            ret |= (1<<i);
        }
            
    }
    return ret;
}

int main(){
    int* arr = (int *)malloc(4*sizeof(int));
    if(arr == NULL){
        perror("malloc");
    }
    for(int i = 0;i<4;i++){
        scanf("%d",arr+i);
    }
    int ret = singleNumber(arr, 4);
    printf("%d\n",ret);
    free(arr);
    arr = NULL;
}
// int main(){
//     printf("%d\n",1<<32);
// }