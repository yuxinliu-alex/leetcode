//
//  Poj14.h
//  LeetCode
//
//  Created by Alex on 15/8/26.
//  Copyright (c) 2015年 Alex. All rights reserved.
//
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000
char* longestCommonPrefix(char** strs, int strsSize) {
    char* longest = malloc(sizeof(char)*MAX);
    bool nolongest =false;
    *longest = '\0';
    if (strsSize==1) {
        return *strs;
    }
    for (int i = 1; i<strsSize; i++) {
        if (strlen(strs[i])>=strlen(longest)) {
            for (int j = 0; j < i ; j++) {
                int k = 0;
                while (strs[j]!=NULL&&strs[i][k]==strs[j][k]&&strs[i][k]!='\0') {
                    k++;
                }
                if (k>strlen(longest)) {
                    for (int t_k=0; t_k<k; t_k++) {
                        *(longest+t_k)=strs[i][t_k];
                    }
                    *(longest+k)='\0';
                    nolongest = false;
                }
                else if(k==strlen(longest)){
                    if(strncmp(longest,strs[i],k)!=0)
                        nolongest = true;
                }
                else if(k==0&&strlen(longest)==1&&strs[i][k]!='\0')
                    nolongest = true;
            }
        }
        else
            strs[i]=NULL;
    }
    if(nolongest)
        return "";
    return longest;
}