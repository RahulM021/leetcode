/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* cur=head;
        ListNode* pre=NULL;
        ListNode *temp;
        while(cur!=NULL){
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode *p=rev(head);
        ListNode *root=p;
        int carry=0;
        ListNode* q;
        while(p!=NULL){
            int val=p->val;
            val=val*2;
            int rem=val%10;
            p->val=rem+carry;
            carry=val/10;
            q=p;
            p=p->next;
        }
        if(carry!=0){
            ListNode* head1=new ListNode(carry);
            q->next=head1;
        }
        head=rev(root);
        return head;
    }
};