#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// int find_num(int* arr,int size){
//     assert(arr);
//     for (int i = 0;i<size+1;i++){
//         int count = 0;
//         for(int j=0;j<size;j++){
//             if(arr[j] == i){
//                 count = 1;
//             }
//         }
//         if(count == 0){
//             return i;
//         }
//     }
//     return -1;
// }
// 时间复杂度为o(n^2);空间复杂度为0(1);
// void bubble_sort(int* arr,int size){
//     int tmp = 0;
//     for(int i = 0;i<size-1;i++){
//         int criteria = 0;
//         for(int j =i;j<size-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 tmp = arr[j+1];
//                 arr[j+1] = arr[j];
//                 arr[j] = tmp;
//                 criteria = 1;
//             }
//         }
//         if(criteria == 0){
//             return ;
//         }
//     }
// }
// //时间复杂度为o(n^2);空间复杂度为0(1);
// int find_num(int* arr,int size){
//     assert(arr);
//     bubble_sort(arr,size);
//     for(int k =0;k<size+1;k++){
//         if(k!=arr[k]){
//             return k;
//         }
//     }
//     return -1;
// }

int find_num(int* arr,int size){
    assert(arr);
    int xcor_1 = 0; int xcor_2 = 0;
    for(int i = 0;i<size+1;i++){
        xcor_1 ^= i;
    }

    for(int j = 0;j<size;j++){
        xcor_2 ^= arr[j];
    }
    return xcor_1^xcor_2;

}

// int find_num(int* arr,int size){
//     assert(arr);
//     int sum1 = 0;
//     int sum2 = 0;
//     for (size_t i = 0; i < size+1; i++)
//     {
//         sum1 += i;
//     }
//     for (size_t j = 0; j < size; j++)
//     {
//         sum2 += arr[j];
//     }
//     return sum1-sum2;
// } 

int main(){
    // int* arr = (int*)malloc(10*sizeof(int));
    // if(arr == NULL){
    //     perror("malloc");
    // }
    // for(int i = 0;i<10;i++){
    //     scanf("%d",arr+i);
    // }
    // int ret = find_num(arr,10);
    // printf("%d",ret);
    // free(arr);
    // arr = NULL;
    printf("%d",1^21);
}