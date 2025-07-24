#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            ListNode* ans = new ListNode(0);
            ListNode* p = l1, *q = l2, *curr = ans;
            int sum = 0, carry;
            while(p != NULL || q != NULL){
                int x = (p != NULL) ? p->val : 0;
                int y = (q != NULL) ? q->val : 0;
                sum = carry+x+y;
                curr->next = new ListNode(sum%10);
                curr = curr->next;
                carry = sum/10;
                if(p != NULL) p = p->next;
                if(q != NULL) q = q->next;
            }
            if(carry > 0){
               curr->next = new ListNode(carry);
            }
            return ans;
        }
};

int main(){
    Solution s;
}