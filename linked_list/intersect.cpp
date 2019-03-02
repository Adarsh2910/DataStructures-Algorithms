#include<iostream>
#include<iterator>
#include<map>
#include"./linked_list.cpp"

using namespace std;

// void intersectList(LinkedList l1, LinkedList l2) { //O(n^2)
// 	LinkedList l3;
// 	struct Node* l1Head = l1.getHead();
// 	struct Node* l2Head = l2.getHead();
// 	while(l1Head != NULL) {
// 		while(l2Head != NULL) {
// 			if(l1Head->value == l2Head->value)
// 			{
// 				l3.insert(l1Head->value);
// 			}
// 			l2Head = l2Head->next;
// 		}
// 		l2Head = l2.getHead();
// 		l1Head = l1Head->next;
// 	}		
// 	l3.print();
// }


void intersectList(LinkedList l1, LinkedList l2) { //O(n)
	LinkedList l3;
	int i=0;
	struct Node* l1Head = l1.getHead();
	struct Node* l2Head = l2.getHead();

	map<int, int> hm;
	while(l1Head != NULL) {
		hm.insert(pair<int, int>(l1Head->value, i));
		i++;
		l1Head = l1Head->next;
	}

	while(l2Head != NULL) {
		if(hm.find(l2Head->value) != hm.end())
			l3.insert(l2Head->value);
		else
			break;

		l2Head = l2Head->next;
	}

	l3.print();
}

int main() {
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {1,2,5,6,7};

	LinkedList l1(arr1, 5);
	LinkedList l2(arr2, 5);
	
	intersectList(l1, l2);

	return 0;
}
