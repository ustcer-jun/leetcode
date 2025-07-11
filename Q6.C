#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
// int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//     assert(num&&returnSize);
//     long sum=0;
//     for(int i =0;i<numSize;i++){
//         sum *= 10;
//         sum += num[i];
//     }
//     sum = sum + k;
//     if(sum == 0){
//         int* res = (int*)malloc(sizeof(int));
//         res[0] = 0;
//         *returnSize = 1;
//         return res;
//     }

//     int* res = (int*)malloc(10000*sizeof(int));
//     int count = 0;
//     while (sum>0)
//     {
//         res[count] = sum%10;
//         sum/=10;
//         count++;
//     }
//     *returnSize = count;
//     //这里我们存入的数据是倒着存的这里需要翻转一下
//     int i =0;int index = count-1;
//     while (i< index)
//     {
//         int tmp =0;
//         tmp = res[i];
//         res[i] = res[index];
//         res[index] = tmp;
//         i++;
//         index--;
//     }
//     return res;
// }

int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
    assert(num && returnSize);
    *returnSize = 0;
    int i =numSize-1;
    int* res = (int*)malloc(fmax(10,numSize+1)*sizeof(int));
    if(k == 0){
        *returnSize = numSize;
        return num;
    }
    while (k>0 || i>=0)
    {   
        if(i>=0){
            k += num[i];
            i--;
        }
        res[(*returnSize)++] = k%10;
        k/=10;
    }
    // int count = 
    //翻转
    for(int m = 0;m<(*returnSize)/2;m++){
        int tmp = res[m];
        res[m] = res[(*returnSize)-1-m];
        res[(*returnSize)-1-m] = tmp;
    }
    
    return res;
}

// int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//     int* res = (int*) malloc(sizeof(int) * fmax(10, numSize + 1));
//     *returnSize = 0;
//     for (int i = numSize - 1; i >= 0 || k > 0; --i, k /= 10) {
//         if (i >= 0) {
//             k += num[i];
//         }
//         res[(*returnSize)++] = k % 10;
//     }

//     for (int i = 0; i < (*returnSize) / 2; i++) {
//         int tmp = res[i];
//         res[i] = res[(*returnSize) - 1 - i];
//         res[(*returnSize) - 1 - i] = tmp;
//     }
//     return res;
// }

int main(){
    int arr[] = {2,7,4};
    // int* ret = (int*)malloc(4*sizeof(int));
    int ret = 0;
    int k=0;
    scanf("%d",&k);
    int*arr1 = addToArrayForm(arr,3,k,&ret);
    printf("%d\n",ret);
    for(int i =0;i<ret;i++){
        printf("%d ",arr1[i]);
    }
}