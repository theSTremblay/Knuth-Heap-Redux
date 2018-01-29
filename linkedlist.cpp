//#include <string.h>
//#include <stdlib.h>
//#include "linkedlist.h"
//
//
//class LinkedList { 
//public :
//	typedef struct node {
//		int value;   
//		struct node *next;
//	}node1;
//
//
//
//	void addToListAtPosition(int position, int value);
//	void addToHead(int value);
//	void appendToList(int value);
//	void removeFromListAtPosition(int position);
//	void removeFromHead();
//	void removeFromEnd();
//	bool find(int value);
//	void reverseList();
//	int getListLength();
//
//	node1 *getHead() {
//		return (main_node);
//	}
//
//private :
//	int list_length = 0;
//
//	node1 *main_node;
//
//
//
//	
//
//
//
//};
//
//
//void LinkedList::addToHead(int value) {
//	if (list_length == 0) {
//		main_node = new node1();
//		main_node->value = value;
//		main_node->next = 0;
//		list_length += 1;
//	}
//	else {
//		node1 *temp;
//		//check this code its my first time using c++
//		temp = new node1();
//		//beacuse I might edit, know that this is supposed to just give the the location of the new node
//		//as well as create a new node
//
//		//this part just has the adress of node put into the temp and switches address of main_node to temp
//		temp->value = value;
//		temp->next = main_node;
//		main_node = temp;
//
//		list_length += 1;
//
//	}
//	
//}
//
//void LinkedList::addToListAtPosition(int position , int value){
//	node1 *temp;
//	if (position > list_length) {
//		return;
//	}
//	else {
//		//So in this we need two pointers one to the list we add
//		//And one to the list previous to the list
//
//		if (position == 0) {
//			addToHead(value);
//		}
//		else {
//			//First establish the new node
//
//			//check this code its my first time using c++
//			temp = new node1();
//			//beacuse I might edit, know that this is supposed to just give the the location of the new node
//			//as well as create a new node
//			temp->value = value;
//
//			node1 *previous_node;
//			previous_node = main_node;
//			//We check to make sure that we are not in the base case where there is no previous node
//			//start at 2 because we are already working at the second node - 1 to get previous
//			for (int i = 1; i < position; i++) {
//				previous_node = previous_node->next;
//			}
//			temp->next = previous_node->next;
//			previous_node->next = temp;
//			list_length += 1;
//
//		}
//	}
//
//}
//void LinkedList :: appendToList(int value) {
//	if (list_length == 0) {
//		main_node = new node1();
//		main_node->value = value;
//		main_node->next = 0;
//		list_length += 1;
//	}
//
//	else {
//		node1 *temp;
//		temp = new node1();
//		//beacuse I might edit, know that this is supposed to just give the the location of the new node
//		//as well as create a new node
//		temp->value = value;
//
//		node1 *previous_node;
//		previous_node = main_node;
//		//We check to make sure that we are not in the base case where there is no previous node
//		//start at 1 because we are already working at the first node - 1 to get previous
//		for (int i = 1; i < list_length; i++) {
//			previous_node = previous_node->next;
//		}
//		temp->next = 0;
//		previous_node->next = temp->next;
//		list_length += 1;
//	}
//
//
//}
//
//void LinkedList::removeFromHead() {
//	if (list_length == 0) {
//		return;
//	}
//	else {
//		//node1 *temp;
//		////check this code its my first time using c++
//		//temp = new node1[];
//		////beacuse I might edit, know that this is supposed to just give the the location of the new node
//		////as well as create a new node
//
//		////this part just has the adress of node put into the temp and switches address of main_node to temp
//		//temp->data = value;
//		//temp->next = main_node;
//		if (main_node->next != 0) {
//			main_node = main_node->next;
//		}
//		else {
//			main_node->value = 0;
//			main_node->next = 0;
//		}
//
//		list_length -= 1;
//
//	}
//
//}
//void LinkedList::removeFromListAtPosition(int position) {
//	node1 *temp;
//	temp = main_node;
//	if (position > list_length) {
//		return;
//	}
//	else {
//		//So in this we need two pointers one to the list we add
//		//And one to the list previous to the list
//
//		if (position == 0) {
//			removeFromHead();
//		}
//		else {
//			//First establish the new node
//
//			//check this code its my first time using c++
//			//temp = new node1[];
//			//beacuse I might edit, know that this is supposed to just give the the location of the new node
//			//as well as create a new node
//			//temp->data = value;
//
//			node1 *previous_node;
//			previous_node = main_node;
//			//We check to make sure that we are not in the base case where there is no previous node
//			//start at 2 because we are already working at the second node - 1 to get previous
//			for (int i = 1; i < position; i++) {
//				previous_node = previous_node->next;
//				if (previous_node->next != 0) {
//					temp = previous_node;
//				}
//			}
//			previous_node->next = temp->next;
//			//previous_node->next = temp->next;
//			list_length -= 1;
//
//		}
//	}
//
//
//}
//
//void LinkedList::removeFromEnd(){
//	if (list_length == 0) {
//		return;
//	}
//
//	else {
//		//node1 *temp;
//		//temp = new node1[];
//		//beacuse I might edit, know that this is supposed to just give the the location of the new node
//		//as well as create a new node
//
//		node1 *previous_node;
//		previous_node = main_node;
//		//We check to make sure that we are not in the base case where there is no previous node
//		//start at 1 because we are already working at the first node - 1 to get previous
//		for (int i = 1; i < list_length; i++) {
//			previous_node = previous_node->next;
//		}
//		//temp->next = 0;
//		// we should probably try TO FIN A FREE TO GET RID OF THIS STUFF
//		previous_node->next = 0;
//		list_length -= 1;
//	}
//}
//
//bool LinkedList::find(int value) {
//	node1 *temp;
//	bool flag = false;
//	//temp = new node1[];
//	for (temp = main_node; temp != NULL; temp = temp->next) {
//		if (temp->value = value) {   
//			/** FOUND **/  
//			flag = true;
//		}
//	}
//	return flag;
//}
///*We will reverse by making a pointer to the end value add the back functions to it decrementting a count each time*/
//void LinkedList::reverseList(){
//	node1 *temp;
//	temp = main_node;
//	//beacuse I might edit, know that this is supposed to just give the the location of the new node
//	//as well as create a new node
//	node1 *temp_copy;
//	temp_copy = temp;
//
//	node1 *previous_node;
//	previous_node = main_node;
//	//We check to make sure that we are not in the base case where there is no previous node
//	//start at 2 because we are already working at the second node - 1 to get previous
//	for (int j = 0; j < list_length; j++) {
//		for (int i = 0; i < (list_length-j); i++) {
//			previous_node = previous_node->next;
//			//A check for the end character
//			if (previous_node->next == 0) {
//				temp = previous_node;
//				temp_copy = temp;
//			}
//
//		}
//		//Yes while you arent creating new linked lists, this one should just overwrite things we've already been to
//		//and thus wont touch again with previous node
//		temp_copy->next = previous_node;
//		temp_copy = temp_copy->next;
//
//		//should make the rignial first spot point  to null
//
//		if (j == (list_length - 1)) {
//			temp_copy->next = 0;
//		}
//	}
//	main_node = temp;
//
//}
//
//int LinkedList::getListLength() {
//	return (list_length);
//}