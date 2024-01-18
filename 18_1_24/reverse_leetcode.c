/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head,int len){
    if(len == 1){
        return head;
    }

    int count = 0;
    struct ListNode* p = head;
    while(count < len-1){
        p = p->next;
        count++;
    }
    struct ListNode* pEnd = p->next;

    struct ListNode* pPre = head;
    p = head->next;
    struct ListNode* pNext;

    count = 0;
    while(count < len-1){
        pNext = p->next;
        p->next = pPre;
        pPre = p;
        p = pNext;
        count++;
    }
    head->next = pEnd;

    return pPre;
}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* p = head;struct ListNode* pPre = NULL;
    int count = 1;
    while(count < left){
        pPre = p;
        p = p->next;
        count++;
    }
    if(pPre){
        pPre->next = reverse(p,right-left+1);
    }
    else{
        head = reverse(p,right-left+1);
    }

    return head;
}
