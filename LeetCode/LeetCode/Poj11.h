//
//  Poj11.h
//  LeetCode
//
//  Created by Alex on 15/8/25.
//  Copyright (c) 2015年 Alex. All rights reserved.
//

#ifndef LeetCode_Poj11_h
#define LeetCode_Poj11_h


#endif
int maxArea(int* height, int heightSize) {
    int* start = height;
    int* end = height+heightSize-1;
    int length = heightSize-1;
    int max = *start<*end?(*start)*length:(*end)*length;
    while (start!=end) {
        int temp = *start<*end?*start*length:*end*length;
        if(temp>max)
            max=temp;
        if (*start<*end)
            start++;
        else
            end--;
    }
    return max;
}