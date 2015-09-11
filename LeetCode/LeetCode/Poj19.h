//
//  Poj19.h
//  LeetCode
//
//  Created by Alex on 15/9/8.
//  Copyright (c) 2015年 Alex. All rights reserved.
//
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* go = head;
    struct ListNode* tail = head;
    for(int i =0;i<n;i++)
        go = go->next;
    if(go==NULL&&n==1)
        return NULL;
    if(go==NULL)
        return head->next;
    while(go->next!=NULL){
        tail = tail->next;
        go = go->next;
    }
    tail->next = tail->next->next;
    return head;
    
}