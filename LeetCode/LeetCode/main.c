//
//  main.c
//  LeetCode
//
//  Created by Alex on 15/8/24.
//  Copyright (c) 2015年 Alex. All rights reserved.
////
#include <stdio.h>
#include <stdlib.h>
#include "Poj18.h"
int main(int argc, const char * argv[]) {
    int s[]={1,0,-1,0,-2,2};
    int* l= (int*)malloc(sizeof(int));
    //printf("%d\n",(int)(sizeof(s)/sizeof(int)));
    int** a = fourSum(s, 6, 0, l);
    //printf("%c",**a);
    printf("%d\n",*l);
    for (int i=0; i<*l; i++) {
        for (int j=0; j<4; j++) {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
