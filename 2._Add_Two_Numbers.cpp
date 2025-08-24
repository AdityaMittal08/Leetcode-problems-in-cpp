// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        int carry = 0;
        int val1;
        int val2;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int val1 = (l1 != nullptr)? l1->val: 0;
            int val2 = (l2 != nullptr)? l2->val : 0;

            int sum = val1+val2+carry;
            carry = sum/10;

            int newNodeVal = sum%10;
            current ->next = new ListNode(newNodeVal);

            current = current->next;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* resultHead = dummyHead -> next;
        delete dummyHead;
        return resultHead;
    }
};