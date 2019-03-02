#include<iostream>
#include"./linked_list.cpp"

using namespace std;

void intersectList(LinkedList l1, LinkedList l2) {
	LinkedList l3;
	struct Node* l1Head = l1.getHead();
	struct Node* l2Head = l2.getHead();
	while(l1Head != NULL) {
		while(l2Head != NULL) {
			if(l1Head->value == l2Head->value)
			{
				l3.insert(l1Head->value);
			}
			l2Head = l2Head->next;
		}
		l2Head = l2.getHead();
		l1Head = l1Head->next;
	}		
	l3.print();
}

int main() {
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {1,2,5,6,7};

	LinkedList l1(arr1, 5);
	LinkedList l2(arr2, 5);
	
	intersectList(l1, l2);

//	l1.print();
//	l2.print();

	return 0;
}
