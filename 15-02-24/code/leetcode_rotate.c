/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* last, *slast;
    while(head==NULL || k==0)
        return head;
    last = head;
    int length = 1;
    while(last->next){
        last = last->next;
        length++;
    }
    k = k % length;
    slast = head;
    for(int i=0; i<length-k-1; i++)
        slast = slast->next;
    last->next = head;
    head = slast->next;
    slast->next = NULL;
    return head;
}
