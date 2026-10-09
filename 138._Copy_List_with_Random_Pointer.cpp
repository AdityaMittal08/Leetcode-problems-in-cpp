// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* dummy = new Node(0);
        Node* copyTail = dummy;
        curr = head;

        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next; 
            
            copyTail->next = copy;
            copyTail = copy;

            curr = curr->next;
        }

        Node* clonedHead = dummy->next;
        delete dummy;
        return clonedHead;
    }
};


// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> cloneMap;

//         Node* curr = head;

//         while(curr != nullptr){
//             cloneMap[curr] = new Node(curr->val);
//             curr = curr -> next;
//         }

//         curr = head;

//         while(curr){
//             cloneMap[curr]->next = cloneMap[curr->next];
//             cloneMap[curr]->random = cloneMap[curr->random];
//             curr = curr->next;
//         }

//         return cloneMap[head];
//     }
// };
