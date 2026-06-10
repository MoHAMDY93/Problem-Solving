// Last updated: 6/10/2026, 7:23:49 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // make a recursive function to get the child_list of some pregnant node in a flattened form
        function<Node*(Node*)> getChild = [&](Node* node) {
            Node* curr = node; 
            Node* last = node;
            while(curr) {
                Node* nxt = curr->next;
                if(curr->child) {
                    Node* childHead = curr->child;
                    Node* childTail = getChild(childHead);
                    
                    // connect curr to childHead
                    curr->next = childHead;
                    childHead->prev = curr;
                    
                    // connect childTail to nxt
                    if(nxt) {
                        childTail->next = nxt;
                        nxt->prev = childTail;
                    }
                    
                    // remove child pointer
                    curr->child = nullptr;
                    
                    // go forward
                    last = childTail;
                    curr = nxt;
                } else {
                    last = curr;
                    curr = nxt;
                }
            }
            return last;
        };
        if(!head) return head;
        getChild(head);
        return head;
    }
};