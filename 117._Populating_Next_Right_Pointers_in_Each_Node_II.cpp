class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* current = root;

        while (current != nullptr) {
            Node dummy;
            Node* tail = &dummy; 
            
            Node* iter = current;
            while (iter != nullptr) {
            
                if (iter->left != nullptr) {
                    tail->next = iter->left;
                    tail = tail->next;
                }

                if (iter->right != nullptr) {
                    tail->next = iter->right;
                    tail = tail->next;
                }

                iter = iter->next;
            }

            current = dummy.next;
        }

        return root;
    }
};