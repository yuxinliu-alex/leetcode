//
//  Poj12.h
//  LeetCode
//
//  Created by Alex on 15/8/25.
//  Copyright (c) 2015年 Alex. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 13

char* intToRoman(int num) {
    char Symbol_l[] = "IVXLCDM";
    char* roman = malloc(sizeof(char)*MAX);
    int i=0;
    *(roman+MAX-1)='\0';
    roman+=MAX-2;
    while (num!=0) {
        switch (num%10) {
            case 1:
                *roman=Symbol_l[i];
                roman--;
                break;
            case 2:
                *roman=Symbol_l[i];
                roman--;
                *roman=Symbol_l[i];
                roman--;
                break;
            case 3:
                *roman=Symbol_l[i];
                roman--;
                *roman=Symbol_l[i];
                roman--;
                *roman=Symbol_l[i];
                roman--;
                break;
            case 4:
                *roman=Symbol_l[i+1];
                roman--;
                *roman=Symbol_l[i];
                roman--;
                break;
            case 5:
                *roman=Symbol_l[i+1];
                roman--;
                break;
            case 6:
                *roman=Symbol_l[i];
                roman--;
                *roman=Symbol_l[i+1];
                roman--;
                break;
            case 7:
                *roman=Symbol_l[i];
                roman--;
                *roman=Symbol_l[i];
                roman--;
                *roman=Symbol_l[i+1];
                roman--;
                break;
            case 8:
                *roman=Symbol_l[i];
                roman--;
                *roman=Symbol_l[i];
                roman--;
                *roman=Symbol_l[i];
                roman--;
                *roman=Symbol_l[i+1];
                roman--;
                break;
            case 9:
                *roman=Symbol_l[i+2];
                roman--;
                *roman=Symbol_l[i];
                roman--;
                break;
            default:
                break;
        }
        i+=2;
        num/=10;
    }
    roman++;
    return roman;
}