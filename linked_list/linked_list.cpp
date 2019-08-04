#include<iostream>
using namespace std;

struct Node {
	struct Node* prev; //pointer to previous node
	struct Node* next; //pointer to next node
	int value;
};

class LinkedList {
	struct Node* head;
	struct Node* curr;

	public:	
	LinkedList() {
		head = NULL;
	}

	LinkedList(int arr[], int len) {
		head = NULL;
		if(len) {
			this->_populateList(arr, len);
		}
	}

	struct Node* getHead() {
		return head;
	}
	
	void insert(int element) {
		struct Node* node = new struct Node;
		node->value = element;
		node->next = NULL;
		if(head == NULL) {
			head = node;
			curr = head;
			node->prev = head;
		} else {
			curr->next = node;
			node->prev = curr;
			curr = node;
		}
	}


	void print() {
		struct Node* printer = head;
		while(1) {
			printf("%d\n",printer->value);
			if(printer->next != NULL) {
				printer = printer->next;
			} else { break; }
		}
	}

	private:
	void _populateList(int arr[], int len) {
		for(int i=0; i<len; i++) {
			this->insert(arr[i]);
		}
	}	
};