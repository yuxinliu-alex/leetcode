//
//  main.c
//  LeetCode
//
//  Created by Alex on 15/8/24.
//  Copyright (c) 2015年 Alex. All rights reserved.
//

#include <stdio.h>
#include "Poj10.h"
int main(int argc, const char * argv[]) {
    if(isMatch("aab", "c*a*b")==true)
        printf("true");
    else
        printf("false");
    return 0;
}
