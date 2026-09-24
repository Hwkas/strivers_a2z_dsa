#include <iostream>

class Node
{
public:
    int key;
    int val;
    int frequency;
    Node *previous;
    Node *next;

    Node(int key, int val, int frequency = 1, Node *previous = nullptr, Node *next = nullptr)
        : key(key), val(val), frequency(frequency), previous(previous), next(next) {}
};

void unLinkNode(Node *node_to_unlink)
{
    Node *left = node_to_unlink->previous;
    Node *right = node_to_unlink->next;

    left->next = right;
    right->previous = left;

    node_to_unlink->previous = nullptr;
    node_to_unlink->next = nullptr;
}

Node *insertAfterHead(Node *head, Node *new_node)
{
    if (new_node->previous != nullptr)
    {
        unLinkNode(new_node);
    }

    new_node->previous = head;
    new_node->next = head->next;
    head->next->previous = new_node;
    head->next = new_node;

    return new_node;
}

void deleteNode(Node *node_to_delete)
{
    unLinkNode(node_to_delete);

    delete node_to_delete;
}

class FreqList
{
public:
    Node *head;
    Node *tail;

    FreqList()
    {
        head = new Node(-1, -1, 0);
        tail = new Node(-1, -1, 0, head);
        head->next = tail;
    }

    bool empty() const
    {
        return head->next == tail;
    }
};

class LFUCache
{
public:
    int capacity;
    int min_freq;
    std::unordered_map<int, FreqList> freq_list;
    std::unordered_map<int, Node *> key_node;

    LFUCache(int capacity) : capacity(capacity), min_freq(0) {}

    // Owns raw pointers, so forbid accidental shallow copies.
    LFUCache(const LFUCache &) = delete;
    LFUCache &operator=(const LFUCache &) = delete;

    ~LFUCache()
    {
        for (auto &entry : freq_list)
        {
            Node *curr = entry.second.head; // walk head -> ... -> tail, freeing everything
            while (curr != nullptr)
            {
                Node *nxt = curr->next;
                delete curr;
                curr = nxt;
            }
        }
    }

    void addFreq(int freq)
    {
        if (freq_list.find(freq) == freq_list.end())
        {
            freq_list.emplace(freq, FreqList());
        }
    }

    void removeFreq(int freq)
    {
        delete freq_list[freq].head;
        delete freq_list[freq].tail;
        freq_list.erase(freq);
    }

    void touch(Node *node)
    {
        int old_freq = node->frequency;

        unLinkNode(node);

        if (freq_list[old_freq].empty())
        {
            removeFreq(old_freq);
            if (min_freq == old_freq)
            {
                min_freq++; // the node is about to land in old_freq + 1
            }
        }

        node->frequency++;
        addFreq(node->frequency);
        insertAfterHead(freq_list[node->frequency].head, node);
    }

    // Evicts the least recently used node among the least frequently used.
    void evict()
    {
        Node *victim = freq_list[min_freq].tail->previous;

        key_node.erase(victim->key);
        deleteNode(victim);

        if (freq_list[min_freq].empty())
        {
            removeFreq(min_freq);
        }
    }

    int get(int key)
    {
        auto it = key_node.find(key);
        if (it == key_node.end())
        {
            return -1;
        }

        Node *current_node = it->second;
        touch(current_node);

        return current_node->val;
    }

    void put(int key, int value)
    {
        if (capacity <= 0)
        {
            return;
        }

        auto it = key_node.find(key);
        if (it != key_node.end())
        {
            it->second->val = value;
            touch(it->second); // an update counts as a use
            return;
        }

        if (static_cast<int>(key_node.size()) == capacity)
        {
            evict();
        }

        Node *new_node = new Node(key, value, 1);
        addFreq(1);
        insertAfterHead(freq_list[1].head, new_node);
        key_node[key] = new_node;
        min_freq = 1;
    }
};

int main()
{
    return 0;
}

// https://leetcode.com/problems/lfu-cache/description/