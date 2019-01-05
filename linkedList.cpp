// Project1.cpp : Defines the entry point for the console application.
#include "stdafx.h"

#include <stddef.h>
#include <iostream>
#include <cstdlib>

typedef struct Node {
	int val;
	Node* next;
	Node* prev;
}Node;

class MyLinkedList {
public:
	/** Initialize your data structure here. */
	Node* head;

	MyLinkedList() {
		head = NULL;
	}

	void printList();

	Node* getNewNode(int val) {
		Node *newNode = new Node;
		newNode->val = val;
		newNode->prev = NULL;
		newNode->next = NULL;
		return newNode;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {

		if (head == NULL) {
			return -1;
		}
		Node *cur = head;
		if (index == 0) {
			return cur->val;
		}

		int i = 1;
		while (i < index && cur != NULL) {
			cur = cur->next;
			i++;
		}

		if (cur == NULL || cur->next == NULL) {
			return -1;
		}
		else {
			return cur->next->val;
		}
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node *newNode = getNewNode(val);

		if (head == NULL) {
			head = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		Node *tail = getNewNode(val);
		Node *cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = tail;
		tail->prev = cur;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {

		if (index == 0) {
			addAtHead(val);
			return;
		}
		if (head == NULL) return;

		Node *newNode = getNewNode(val);
		Node *cur = head;
		int i = 0;
		while (i < index) {
			cur = cur->next;
			if (cur == NULL) {
				addAtTail(val);
				return;
			}
			i++;
		}
		newNode->next = cur;
		newNode->prev = cur->prev;
		cur->prev->next = newNode;
		cur->prev = newNode;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (head == NULL) {
			return;
		}
		if (index == 0) {
			head = head->next;
			delete head->prev;
			return;
		}

		Node *cur = head;
		for (int i = 1; i < index; i++) {
			cur = cur->next;
			if (cur->next == NULL) {
				return;
			}
		}

		Node *del = cur->next;
		if (del == NULL) return;
		del->prev->next = del->next; // cur->next->next;
		if (del->next != NULL) {
			del->next->prev = del->prev;
		}
		delete del;
		del = NULL;
	}
};

void MyLinkedList::printList() {
	Node* head = this->head;
	int i = 1;
	while (head) {
		std::cout << i << ": " << head->val << std::endl;
		head = head->next;
		i++;
	}
}

int main()
{
	MyLinkedList* obj = new MyLinkedList();
	obj->addAtHead(0);
	obj->addAtTail(3);
	obj->addAtIndex(1, 1);
	obj->addAtIndex(2, 2);
	obj->deleteAtIndex(0);
	obj->printList();
	std::cin.get();

    return 0;
}

