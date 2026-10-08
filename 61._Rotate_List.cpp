
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }
        ListNode* lastNode = head;
        int length = 1;
        while(lastNode->next != nullptr){
            length++;
            lastNode = lastNode -> next;
        }

        k = k % length;

        lastNode->next = head;
        ListNode* ahead = head;
        for(int i = 0; i < length - k - 1; i++){
            ahead = ahead -> next;
        }

        ListNode* res = ahead->next;

        ahead->next = nullptr;

        return res;
    }
};