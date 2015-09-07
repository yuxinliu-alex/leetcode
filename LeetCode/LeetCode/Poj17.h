//
//  Poj17.h
//  LeetCode
//
//  Created by Alex on 15/9/6.
//  Copyright (c) 2015年 Alex. All rights reserved.
//

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>
char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL) {
        return NULL;
    }
    int length=(int)strlen(digits);
    if (length == 0) {
        return NULL;
    }
    int out_nums =1;
    for (int i = 0 ; i<length; i++) {
        if (digits[i]=='1'||digits[i]=='0')
            continue;
        else if (digits[i]=='7'||digits[i]=='9')
            out_nums*=4;
        else
            out_nums*=3;
    }
    *returnSize = out_nums;
    char** comb = (char**)malloc(out_nums*sizeof(char*));
    for (int i=0; i<out_nums; ++i) {
        comb[i] = (char*)malloc((length+1)*sizeof(char));
    }
    int i =0;
    int step=out_nums;
    int jump;
    int fourOrthree=3;
    char insert='-';
    while (digits[i]!='\0') {
        switch (digits[i]) {
            case '0':
                insert = '0';
                fourOrthree = 1;
                break;
            case '1':
                insert = '1';
                fourOrthree = 1;
                break;
            case '2':
                insert = 'a';
                break;
            case '3':
                insert = 'd';
                break;
            case '4':
                insert = 'g';
                break;
            case '5':
                insert = 'j';
                break;
            case '6':
                insert = 'm';
                break;
            case '8':
                insert = 't';
                break;
            case '7':
                insert = 'p';
                fourOrthree = 4;
                break;
            case '9':
                insert = 'w';
                fourOrthree = 4;
                break;
            default:
                break;
        }
        step=step/fourOrthree;
        for (int j=0; j<out_nums; j++) {
            if (fourOrthree == 1)
                comb[j][i]=insert;
            else{
                jump=j/step;
                jump=jump%fourOrthree;
                comb[j][i]=insert+jump;
            }
        }
        fourOrthree =3;
        i++;
    }
    if (digits[i]=='\0') {
        for (int j=0; j<out_nums; j++) {
            comb[j][i]='\0';
        }
    }
    return comb;
}
