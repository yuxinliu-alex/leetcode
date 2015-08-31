//
//  main.c
//  LeetCode
//
//  Created by Alex on 15/8/24.
//  Copyright (c) 2015年 Alex. All rights reserved.
//

#include <stdio.h>
#include "Poj15.h"
int main(int argc, const char * argv[]) {
    int s[]={-1,0,1};
    int num = 0;
    int* p =&num;
    int** a;
    a = threeSum(s, 3, p);
    for (int i =0; i<num; ++i) {
        printf("%d,%d,%d\n",a[i][0],a[i][1],a[i][2]);
    }
    return 0;
    
}
