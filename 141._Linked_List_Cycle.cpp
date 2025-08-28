
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* back = head;
        ListNode* front = head;
        while(front != nullptr && front->next != nullptr){
            front = front -> next ->next;
            back = back->next;
            if(front == back){
                return true; 
            }
        }
        return false;
    }
};