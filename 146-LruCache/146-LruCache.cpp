// Last updated: 6/10/2026, 7:26:25 PM
class LRUCache {
public:
    struct Node {
        int key , value;
        Node *prev , *next;
        Node(int k , int v): key(k) , value(v) , prev(nullptr) , next(nullptr) {} 
    };
    int cap;
    unordered_map<int , Node*> mp;
    Node *head = new Node(-1 , -1) , *tail = new Node(-1 ,-1);
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    void addFront(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode; 
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        int res = node->value;
        mp.erase(key);
        remove(node);
        addFront(node);
        mp[key] = head->next;
        return res;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            mp.erase(key);
            remove(node);
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            remove(tail->prev);
        }
        addFront(new Node(key , value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */