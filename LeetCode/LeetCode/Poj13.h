//
//  Poj13.h
//  LeetCode
//
//  Created by Alex on 15/8/26.
//  Copyright (c) 2015年 Alex. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef LeetCode_Poj13_h
#define LeetCode_Poj13_h


#endif
int romanToInt(char* s) {
    char Roman[] = "MDCLXVI";
    int num=0;
    int count = 1000;
    int i=0;
    while (*s!='\0') {
        if (*s==Roman[i]) {
            if (i!=0&&*(s+1)==Roman[i-2]) {
                num+=9*count;
                s+=2;
                count/=10;
                i+=2;
            }
            else if(i!=0&&*(s+1)==Roman[i-1]){
                num+=4*count;
                s+=2;
                count/=10;
                i+=2;
            }
            else{
                num+=count;
                s++;
            }
        }
        else{
            if (i!=0&&*s==Roman[i-1]) {
                num+=5*count;
                s++;
                continue;
            }
            count/=10;
            i+=2;
        }
    }
    return num;
}
