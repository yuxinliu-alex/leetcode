//
//  Poj10.h
//  LeetCode
//  '.' Matches any single character.
//  '*' Matches zero or more of the preceding element.
//
//  The matching should cover the entire input string (not partial).
//
//  The function prototype should be:
//  bool isMatch(const char *s, const char *p)
//
//  Created by Alex on 15/8/24.
//  Copyright (c) 2015年 Alex. All rights reserved.
//  Hint: If you are stuck, recursion is your friend.
#include <string.h>
typedef enum {true,false}bool;

bool isMatch(char* s, char* p) {
    long s_l = strlen(s)-1;
    long p_l = strlen(p)-1;
    while (s_l>=0&&p_l>=0) {
        if (*(s+s_l)=='*'||*(p+p_l)=='*')
            return true;
        if (*(s+s_l)=='.'||*(p+p_l)=='.'||*(s+s_l)==*(p+p_l)){
            s_l--,p_l--;
            continue;
        }
        else
            return false;
    }
    while (s_l>=0) {
        if(*(s+s_l)=='*')
            s_l--;
        else
            return false;
    }
    while (p_l>=0) {
        if (*(p+p_l)=='*') {
            p_l--;
        }
        else
            return false;
    }
    return true;
}