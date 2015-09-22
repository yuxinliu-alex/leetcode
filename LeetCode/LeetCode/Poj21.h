//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};
typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    ListNode* merge;
    ListNode* go;
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if (l1->val>l2->val){
        merge = l2;
        l2=l2->next;
    }
    else{
        merge = l1;
        l1=l1->next;
    }
    go=merge;
    while (l1!=NULL&&l2!=NULL) {
        if (l1->val>l2->val) {
            go->next=l2;
            go=l2;
            l2=l2->next;
        }
        else{
            go->next=l1;
            go=l1;
            l1=l1->next;
        }
    }
    if (l1==NULL)
        go->next=l2;
    else
        go->next=l1;
    return merge;
}