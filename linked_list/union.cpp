#include<iostream>
#include<iterator>
#include<map>
#include"./linked_list.cpp"

using namespace std;

void unionList(LinkedList l1, LinkedList l2) {
	LinkedList l3;
	int i=0;
	struct Node* l1Head = l1.getHead();
	struct Node* l2Head = l2.getHead();

	map<int, int> hm;
	while(l1Head != NULL) {
		hm.insert(pair<int, int>(l1Head->value, i));
		i++;
		l3.insert(l1Head->value);
		l1Head = l1Head->next;
	}

	while(l2Head != NULL) {
		if(hm.find(l2Head->value) == hm.end()) {
			hm.insert(pair<int, int>(l2Head->value, i));
			i++;
			l3.insert(l2Head->value);
		}

		l2Head = l2Head->next;
	}

	l3.print();
}


int main() {
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {1,2,5,6,7};

	LinkedList l1(arr1, 5);
	LinkedList l2(arr2, 5);
	
	unionList(l1, l2);

	return 0;
}