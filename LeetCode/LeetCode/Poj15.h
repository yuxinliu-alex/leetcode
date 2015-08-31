//
//  Poj15.h
//  LeetCode
//
//  Created by Alex on 15/8/27.
//  Copyright (c) 2015年 Alex. All rights reserved.
//
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 2048
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quickSort(int* s,int l,int r){
    int i=l,j=r;
    if(l<r){
        int x=s[i];
        while (i<j) {
            while (i<j&&s[j]>x)
                j--;
            if (i<j)
                s[i++]=s[j];
            while (i<j&&s[i]<x)
                i++;
            if (i<j)
                s[j--]=s[i];
        }
        s[i]=x;
        quickSort(s,l,i-1);
        quickSort(s,i+1,r);
    }
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int p_count = 0;
    int n_count = 0;
    bool nozero = false;
    int** sum = (int**)calloc(MAX, sizeof(int*));
    int size = 0;
    quickSort(nums,0,numsSize-1);
    for (int i=0; i<numsSize; ++i) {
        if(nums[i]<0)
            n_count++;
        if (nums[i]>0) {
            p_count++;
        }
    }
    if (n_count+p_count==numsSize)
        nozero=true;
    if (numsSize-(n_count+p_count)>2) {
        sum[size] = (int*)malloc(3*sizeof(int));
        sum[size][0] = 0;
        sum[size][1] =  0;
        sum[size++][2] = 0;
    }
    if (n_count==0||p_count==0){
        if (size==0)
            return NULL;
        else{
            *returnSize=size;
            return sum;}
    }
    int negtive_nums[n_count];
    int positive_nums[p_count];
    for (int i = 0; i<n_count; ++i )
        negtive_nums[n_count-i-1] = -nums[i];
    for (int i=numsSize-p_count,k=0; i<numsSize; ++i,++k)
        positive_nums[k] = nums[i];
    int i = 0;
    int j = 0;
    while (i<n_count) {
        if (i>0) {
            if (negtive_nums[i]==negtive_nums[i-1]) {
                ++i;
                continue;
            }
        }
        for (int k=0; k<p_count; ++k) {
            if (positive_nums[k]<negtive_nums[i]) {
                for (int t=k+1; t<p_count; ++t) {
                    if(positive_nums[t]+positive_nums[k]>negtive_nums[i])
                        break;
                    else if(positive_nums[t]+positive_nums[k]==negtive_nums[i]){
                        sum[size] = (int*)malloc(3*sizeof(int));
                        sum[size][0] = -negtive_nums[i];
                        sum[size][1] =  positive_nums[k];
                        sum[size++][2] = positive_nums[t];
                        break;
                    }
                }
                while (k<p_count&&positive_nums[k+1]==positive_nums[k]) k++;
            }
            else if (!nozero&&positive_nums[k]==negtive_nums[i]){
                sum[size] = (int*)malloc(3*sizeof(int));
                sum[size][0] = -negtive_nums[i];
                sum[size][1] =  0;
                sum[size++][2] = positive_nums[k];
                break;
            }
            else
                break;
        }
        ++i;
    }
    while (j<p_count) {
        if (j>0)
            if (positive_nums[j]==positive_nums[j-1]) {
                j++;
                continue;
            }
        for (int k = 0; k<n_count; ++k) {
            if (negtive_nums[k]<positive_nums[j]) {
                for (int t=k+1; t<n_count; ++t) {
                    if(negtive_nums[t]+negtive_nums[k]>positive_nums[j])
                        break;
                    else if (negtive_nums[t]+negtive_nums[k]==positive_nums[j]){
                        sum[size] = (int*)malloc(3*sizeof(int));
                        sum[size][0] = -negtive_nums[t];
                        sum[size][1] = -negtive_nums[k];
                        sum[size++][2] = positive_nums[j];
                        break;
                    }
                }
                while (k<n_count&&negtive_nums[k+1]==negtive_nums[k]) k++;
            }
            else
                break;
            
        }
        ++j;
    }
    *returnSize = size;
    return sum;
}