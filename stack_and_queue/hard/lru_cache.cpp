#include <iostream>

class Node
{
public:
    int key;
    int val;
    Node *previous;
    Node *next;

    Node(int key, int val, Node *previous = nullptr, Node *next = nullptr)
        : key(key), val(val), previous(previous), next(next) {}
};

Node *insertAfterHead(Node *head, Node *new_node)
{
    if (new_node->previous != nullptr)
    {
        Node *left = new_node->previous;
        Node *right = new_node->next;
        left->next = right;
        right->previous = left;
    }

    new_node->previous = head;
    new_node->next = head->next;
    head->next->previous = new_node;
    head->next = new_node;

    return new_node;
}

void deleteNode(Node *node_to_delete)
{
    Node *left = node_to_delete->previous;
    Node *right = node_to_delete->next;

    left->next = right;
    right->previous = left;

    delete node_to_delete;
}

class LRUCache
{
public:
    int capacity;
    Node *head;
    Node *tail;
    std::unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1, head);
        head->next = tail;
    }

    ~LRUCache()
    {
        Node *cur = head;
        while (cur)
        {
            Node *nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    LRUCache(const LRUCache &) = delete;
    LRUCache &operator=(const LRUCache &) = delete;

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            insertAfterHead(head, mp[key]);
            return mp[key]->val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (this->get(key) != -1)
        {
            mp[key]->val = value;
            return;
        }

        if (mp.size() == capacity)
        {
            mp.erase(tail->previous->key);
            deleteNode(tail->previous);
        }

        Node *new_node = new Node(key, value);
        mp[key] = new_node;

        insertAfterHead(head, new_node);
    }
};

int main()
{
    return 0;
}

// https://leetcode.com/problems/lru-cache/submissions/2151104076/