//
//  main.c
//  LeetCode
//
//  Created by Alex on 15/8/24.
//  Copyright (c) 2015年 Alex. All rights reserved.
////
#include <stdio.h>
#include <stdlib.h>
#include "Poj17.h"
int main(int argc, const char * argv[]) {
    char s[]="7,3";
    int* l= (int*)malloc(sizeof(int));
    //printf("%d\n",(int)(sizeof(s)/sizeof(int)));
    char ** a = letterCombinations(s, l);
    //printf("%c",**a);
    for (int i=0; i<*l; i++) {
        for (int j=0; j<strlen(a[i]); j++) {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
