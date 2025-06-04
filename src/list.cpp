#include "list.h"
#include <stdexcept>

// === LinkedList core ===
LinkedList::LinkedList() = default;

LinkedList::LinkedList(const LinkedList& other) {
    head = deepCopy(other.head);
}

LinkedList& LinkedList::operator=(LinkedList rhs) {
    std::swap(head, rhs.head);
    return *this;
}

LinkedList::~LinkedList() { freeChain(head); }

void LinkedList::prepend(int value) {
    head = new Node{value, head};
}

void LinkedList::append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

int LinkedList::removeFront() {
    if (isEmpty()) throw std::runtime_error("removeFront on empty list");
    int value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return value;
}

bool LinkedList::isEmpty() const { return head == nullptr; }

void LinkedList::print(ostream& out) const {
    out << '[';
    for (Node* cur = head; cur; cur = cur->next) {
        out << cur->data;
        if (cur->next) out << " → ";
    }
    out << ']';
}

LinkedList::Node* LinkedList::deepCopy(Node* src) {
    if (!src) return nullptr; // Handles empty source list
    Node* newNode = new Node{src->data, deepCopy(src->next)};
    return newNode;
}
void LinkedList::freeChain(Node* n) {
    while (n) {
        Node* next = n->next;
        delete n;
        n = next;
    }
}
