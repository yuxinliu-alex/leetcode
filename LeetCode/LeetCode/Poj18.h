/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 100
void quickSort(int* s,int start,int end){
    int i=start;
    int j=end;
    if(start<end){
        int x=s[i];
        while(i<j){
            while(i<j&&s[j]>x)j--;
            if(i<j)
                s[i++]=s[j];
            while(i<j&&s[i]<x)i++;
            if(i<j)
                s[j--]=s[i];
        }
        s[i]=x;
        quickSort(s,start,i-1);
        quickSort(s,i+1,end);
    }
}

void insert(int* ans,int** sums,int* returnSize){
    int i = 0;
    while (i<*returnSize) {
        if (sums[i][0]==ans[0]&&sums[i][1]==ans[1]&&sums[i][2]==ans[2]&&sums[i][3]==ans[3])
            return;
        else
            i++;
    }
    sums[i]=ans;
    *returnSize=*returnSize+1;
    return;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    quickSort(nums,0,numsSize-1);
    int** Sums = (int**)calloc(MAX,sizeof(int*));
    int length = numsSize;
    *returnSize = 0;
    for (int i = 0; i<length; i++) {
        for (int j = i+1; j<length; ++j) {
            int k = j+1;
            int n = length-1;
            while (k<n) {
                int sumThree = nums[i]+nums[j]+nums[k];
                if (sumThree+nums[n]<target)
                    k++;
                else if (sumThree+nums[n]>target)
                    n--;
                else{
                    int* ans = (int*)malloc(4*sizeof(int));
                    ans[0]=nums[i];
                    ans[1]=nums[j];
                    ans[2]=nums[k];
                    ans[3]=nums[n];
                    insert(ans,Sums,returnSize);
                    k++;
                    n--;
                }
            }
        }
    }
    return Sums;
}

