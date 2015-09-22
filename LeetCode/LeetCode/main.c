//
//  main.c
//  LeetCode
//
//  Created by Alex on 15/8/24.
//  Copyright (c) 2015年 Alex. All rights reserved.
////
#include <stdio.h>
#include <stdlib.h>
#include "Poj21.h"
int main(int argc, const char * argv[]) {
    ListNode l1={2,NULL};
    ListNode l2={1,NULL};
    //l1->val=2;
    //l2->val=1;
    ListNode* t1=&l1;
    ListNode* t2=&l2;
    ListNode* merger = mergeTwoLists(t1,t2);
    while (merger!=NULL) {
        printf("%d",merger->val);
        merger=merger->next;
    }
    return 0;
}
