//
//  Poj16.h
//  LeetCode
//
//  Created by Alex on 15/9/1.
//  Copyright (c) 2015年 Alex. All rights reserved.
//
#include <stdbool.h>
void quickSort(int* nums,int start,int end){
    int i=start,j=end;
    if (start<end) {
        int x=nums[i];
        while (i<j){
            while (i<j&&nums[j]>x) j--;
            if (i<j)
                nums[i++]=nums[j];
            while (i<j&&nums[i]<x) i++;
            if (i<j)
                nums[j--]=nums[i];
        }
        nums[i] = x;
        quickSort(nums,start,i-1);
        quickSort(nums,i+1,end);
    }
    
}

int threeSumClosest(int* nums, int numsSize, int target) {
    quickSort(nums,0,numsSize-1);
    int closest,sum;
    closest = sum = nums[0]+nums[1]+nums[2];
    int temp;
    bool goNofurther = false;
    bool stepOver = false;
    if (target>sum) {
        temp=target-sum;
    }
    else if (target<sum){
        temp=sum-target;
    }
    else
        return target;
    for (int i = 0; i<numsSize-2; ++i) {
        if (goNofurther)
            break;
        for (int j=i+1; j<numsSize-1; ++j) {
            if (stepOver) {
                stepOver=false;
                break;
            }
            for (int k=j+1; k<numsSize; ++k) {
                sum = nums[i]+nums[j]+nums[k];
                printf("%d,%d,%d,%d\n",i,j,k,sum);
                if (target>sum){
                    if(target-sum<temp){
                        temp=target-sum;
                        closest=sum;
                    }
                }
                else if(target<sum){
                    if(sum-target<temp){
                        temp=sum-target;
                        closest=sum;
                    }
                    if (j==k-1)
                        stepOver=true;
                    if (j==k-1&&i==j-1)
                        goNofurther=true;
                    break;
                }
                else
                    return target;
            }
        }
    }
    return closest;
}
