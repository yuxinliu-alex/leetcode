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


void threeSum(int* nums, int numsSize, int* returnSize) {
    int p_count = 0;
    int n_count = 0;
    bool nozero = false;
    quickSort(nums,0,numsSize);
    for (int i=0; i<numsSize; ++i) {
        if (n_count==0&&nums[i]>=0)
            n_count=i;
        if (p_count==0&&nums[i]>0) {
            p_count=i;
        }
    }
    if (n_count==p_count)
        nozero=true;
    if (n_count==0||p_count==0) {
        return ;
    }
    p_count=numsSize-p_count;
    int negtive_nums[n_count];
    int positive_nums[p_count];
    for (int i = 0; i<n_count; ++i ) {
        negtive_nums[i] = nums[i];
        printf("%d   ",negtive_nums[i]);
    }
    for (int i=numsSize-p_count; i<numsSize; ++i)
        positive_nums[i] = nums[i];
    //free(nums);
    free(returnSize);
    //return &nums;
}