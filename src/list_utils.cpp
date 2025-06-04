#include "list_utils.h"
#include "list.h"
#include <stdexcept>

int length(const LinkedList& list) {
    int count = 0;
    Node* current = list.head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int sum(const LinkedList& list) {
    int total = 0;
    Node* current = list.head;
    while (current != nullptr) {
        total += current->value;
        current = current->next;
    }
    return total;
}

bool contains(const LinkedList& list, int k) {
    Node* current = list.head;
    while (current != nullptr) {
        if (current->value == k) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void reverse(LinkedList& list) {
    Node* prev = nullptr;
    Node* current = list.head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list.head = prev;
}

int nthFromEnd(const LinkedList& list, int n) {
    int len = length(list);
    if (n < 0 || n >= len) {
        throw std::out_of_range("Invalid value for n");
    }

    Node* current = list.head;
    for (int i = 0; i < len - n - 1; i++) {
        current = current->next;
    }
    return current->value;
}

