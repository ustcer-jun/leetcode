#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// void find_nums(int* arr,size_t num,int* result){
//     int* tmp = result;
//     for(int i = 0;i < num;i++){
//         int count  = 0;
//         for(int j = 0;j < num;j++){
//             if(arr[i] == arr[j]){
//                 count++;
//             }
//         }
//         if(count == 1){
//             *tmp = arr[i];
//             tmp++;
//         }
//     }
// }
void find_nums(int* arr,size_t num,int* result){
    assert(arr && result);
    int xcorr =0;
    for(int i =0;i<num;i++){
         xcorr ^= arr[i];
    }
    //分组，按比特位进行分组
    int num1 =0;
    int num2 =0;
    // int diff_bit = xcorr & (-xcorr); //找到最低的不同的比特位

    int diff_bit = 0;
    for(int i =0;i<32;i++){. //利用循环找到最低的比特位
        if((xcorr>>i) & 1){
            diff_bit = 1<< i;
        }
    }
    for(int j = 0;j<num;j++){
        if(arr[j] & diff_bit){
            num1 ^= arr[j];
        }
        else{
            num2 ^= arr[j];
        }
    }
    result[1] = num1;
    result[2] = num2;
}


int main(){
    int* arr = (int*)malloc(8*sizeof(int));
    int* obj_nums = (int*)malloc(2*sizeof(int));
    if(arr == NULL || obj_nums == NULL){
        perror("malloc");
        return -1;
    }
    for(int i = 0;i<8;i++){
        scanf("%d",arr+i);
    }
    find_nums(arr,8,obj_nums);
    for(int j =0;j<2;j++){
        printf("%d ",obj_nums[j]);
    }
    free(arr);
    free(obj_nums);
    arr = NULL; obj_nums = NULL;
}