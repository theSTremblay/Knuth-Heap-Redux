// //  main.cpp //  Assignment 8 // //  Created by Elie Antoun on 4/7/16. //  Copyright © 2016 Elie Antoun. All rights reserved. //

#include <stdio.h>
#include <stdlib.h>
//#include "linkedlist.h"
#include <cassert>


class LinkedList {
public:
	typedef struct node {
		int value;
		struct node *next;
	}node1;



	//void addToListAtPosition(int position, int value);
	//void addToHead(int value);
	//void appendToList(int value);
	//void removeFromListAtPosition(int position);
	//void removeFromHead();
	//void removeFromEnd();
	//bool find(int value);
	//void reverseList();
	//int getListLength();
	void addToHead(int value) {
		if (list_length == 0) {
			main_node = new node1();
			main_node->value = value;
			main_node->next = 0;
			list_length += 1;
		}
		else {
			node1 *temp;
			//check this code its my first time using c++
			temp = new node1();
			//beacuse I might edit, know that this is supposed to just give the the location of the new node
			//as well as create a new node

			//this part just has the adress of node put into the temp and switches address of main_node to temp
			temp->value = value;
			temp->next = main_node;
			main_node = temp;

			list_length += 1;

		}

	}

	void addToListAtPosition(int position, int value) {
		node1 *temp;
		if (position > list_length) {
			return;
		}
		else {
			//So in this we need two pointers one to the list we add
			//And one to the list previous to the list

			if (position == 0) {
				addToHead(value);
			}
			else {
				//First establish the new node

				//check this code its my first time using c++
				temp = new node1();
				//beacuse I might edit, know that this is supposed to just give the the location of the new node
				//as well as create a new node
				temp->value = value;

				node1 *previous_node;
				previous_node = main_node;
				//We check to make sure that we are not in the base case where there is no previous node
				//start at 2 because we are already working at the second node - 1 to get previous
				for (int i = 1; i < position; i++) {
					previous_node = previous_node->next;
				}
				temp->next = previous_node->next;
				previous_node->next = temp;
				list_length += 1;

			}
		}

	}
	void appendToList(int value) {
		if (list_length == 0) {
			main_node = new node1();
			main_node->value = value;
			main_node->next = 0;
			list_length += 1;
		}

		else {
			node1 *temp;
			temp = new node1();
			//beacuse I might edit, know that this is supposed to just give the the location of the new node
			//as well as create a new node
			temp->value = value;

			node1 *previous_node;
			previous_node = main_node;
			//We check to make sure that we are not in the base case where there is no previous node
			//start at 1 because we are already working at the first node - 1 to get previous
			for (int i = 1; i < list_length; i++) {
				previous_node = previous_node->next;
			}
			temp->next = 0;
			previous_node->next = temp;
			list_length += 1;
		}


	}

	void removeFromHead() {
		if (list_length == 0) {
			return;
		}
		else {
			//node1 *temp;
			////check this code its my first time using c++
			//temp = new node1[];
			////beacuse I might edit, know that this is supposed to just give the the location of the new node
			////as well as create a new node

			////this part just has the adress of node put into the temp and switches address of main_node to temp
			//temp->data = value;
			//temp->next = main_node;
			if (main_node->next != 0) {
				main_node = main_node->next;
			}
			else {
				main_node->value = 0;
				main_node->next = 0;
			}

			list_length -= 1;

		}

	}
	void removeFromListAtPosition(int position) {
		node1 *temp;
		temp = main_node;
		if (position > list_length) {
			return;
		}
		else {
			//So in this we need two pointers one to the list we add
			//And one to the list previous to the list

			if (position == 0) {
				removeFromHead();
			}
			else {
				//First establish the new node

				//check this code its my first time using c++
				//temp = new node1[];
				//beacuse I might edit, know that this is supposed to just give the the location of the new node
				//as well as create a new node
				//temp->data = value;

				node1 *previous_node;
				previous_node = main_node;
				//We check to make sure that we are not in the base case where there is no previous node
				//start at 2 because we are already working at the second node - 1 to get previous
				for (int i = 1; i < (position - 1); i++) {
					if (previous_node->next != 0) {
						previous_node = previous_node->next;
					}
				/*	if (previous_node->next != 0) {
						temp = previous_node->next;
					}*/
				}
				if (previous_node->next != 0) {
					temp = previous_node->next;
				}
				else {
					temp = previous_node;
					printf("Things have gone horribly wrong");
				}
				previous_node->next = temp->next;
				//previous_node->next = temp->next;
				list_length -= 1;

			}
		}


	}

	void removeFromEnd() {
		if (list_length == 0) {
			return;
		}

		else {
			//node1 *temp;
			//temp = new node1[];
			//beacuse I might edit, know that this is supposed to just give the the location of the new node
			//as well as create a new node

			node1 *previous_node;
			previous_node = main_node;
			//We check to make sure that we are not in the base case where there is no previous node
			//start at 1 because we are already working at the first node - 1 to get previous
			for (int i = 1; i < (list_length - 1); i++) {
				previous_node = previous_node->next;
			}
			//temp->next = 0;
			// we should probably try TO FIN A FREE TO GET RID OF THIS STUFF
			previous_node->next = 0;
			list_length -= 1;
		}
	}

	bool find(int value) {
		node1 *temp;
		bool flag = false;
		//temp = new node1[];
		for (temp = main_node; temp != NULL; temp = temp->next) {
			if (temp->value == value) {
				/** FOUND **/
				flag = true;
			}
		}
		return flag;
	}
	/*We will reverse by making a pointer to the end value add the back functions to it decrementting a count each time*/
	void reverseList() {
		node1 *temp;
		temp = main_node;
		//beacuse I might edit, know that this is supposed to just give the the location of the new node
		//as well as create a new node
		node1 *temp_copy;
		temp_copy = temp;

		node1 *new_base;
		new_base = temp;

		node1 *previous_node;
		previous_node = main_node;
		//We check to make sure that we are not in the base case where there is no previous node
		//start at 2 because we are already working at the second node - 1 to get previous
		for (int j = 1; j < list_length; j++) {
			for (int i = 0; i < (list_length - j); i++) {
				temp_copy = previous_node;
				previous_node = previous_node->next;
				//A check for the end character
				if (previous_node->next == 0) {
					temp = previous_node;
					new_base = temp;
					//temp_copy = temp;
				}

			
			}


			//Yes while you arent creating new linked lists, this one should just overwrite things we've already been to
			//and thus wont touch again with previous node
			temp->next = temp_copy;
			temp = temp->next;
			previous_node = main_node;
			//temp_copy = temp_copy->next;

			//should make the rignial first spot point  to null

			if (j == (list_length - 1)) {
				temp->next = 0;
			}
		}
		main_node = new_base;

	}

	int getListLength() {
		return (list_length);
	}
	node1 *getHead() {
		return (main_node);
	}

private:
	int list_length = 0;

	node1 *main_node;







};


void test1() { 
	int value = 1;   
	int postion = 0;  
	LinkedList l;    
	l.addToListAtPosition(postion, value);   
	assert(l.getListLength() == 1);   
	printf("Test1 Passed!\n"); }
void test2() { 
	int value = 1; 
	int postion = 0;  
	LinkedList l;     
	
	l.addToListAtPosition(postion, value);    
	assert(l.getListLength() == 1);   
	assert(l.getHead()->value == 1); 
	printf("Test2 Passed!\n"); }
void test3() {
	int value = 2;   
	LinkedList l;    
	l.addToHead(value);   
	assert(l.getListLength() == 1);  
	assert(l.getHead()->value == 2);  
	printf("Test3 Passed!\n");
}
void test4() { 
	LinkedList l;  
l.addToHead(1);   
l.appendToList(2);
l.appendToList(3);

assert(l.getListLength() == 3);  
assert(l.getHead()->value == 1);  
assert(l.getHead()->next->value == 2);  
printf("Test4 Passed!\n");
}
void test5() { 
	LinkedList l;  
l.addToListAtPosition(0, 1);   
l.addToListAtPosition(1, 2); 
assert(l.getListLength() == 2); 
assert(l.getHead()->value == 1);   
assert(l.getHead()->next->value == 2);    
printf("Test5 Passed!\n"); 
}
void test6() {
	LinkedList l;   
	l.addToListAtPosition(0, 1);
l.addToListAtPosition(1, 2);    
assert(l.find(1) == true);   
assert(l.find(2) == true);   
printf("Test6 Passed!\n");
}
void test7() {
	LinkedList l;   

	l.addToListAtPosition(0, 1);  
	l.addToListAtPosition(1, 3);   
	l.addToListAtPosition(2, 5);
	l.addToListAtPosition(3, 6);
	l.addToListAtPosition(4, 7);
	l.removeFromListAtPosition(3);   
	assert(l.getHead()->value == 1); 
	assert(l.getHead()->next->value == 3);  
	assert(l.getHead()->next->next->value == 6);
	assert(l.getHead()->next->next->next->value == 7);
	printf("Test7 Passed!\n");
}
void test8() {
	LinkedList l;   
	l.addToListAtPosition(0, 1);  
	l.addToListAtPosition(1, 2);   
	l.removeFromListAtPosition(0);   
	assert(l.getHead()->value == 2);
	assert(l.getHead()->next == 0);  
	printf("Test8 Passed!\n");
}
void test9() {
	LinkedList l;    
	l.addToListAtPosition(0, 1);  
	l.addToListAtPosition(1, 2);   
	l.addToListAtPosition(1, 2);
	l.removeFromHead();  
	assert(l.getHead()->value == 2);    
	assert(l.getHead()->next->value == 2);  
	printf("Test9 Passed!\n");
}
void test10() {
	LinkedList l;  
	l.addToListAtPosition(0, 1);   
	l.addToListAtPosition(1, 2);  
	l.addToListAtPosition(1, 2);
	l.removeFromEnd();  
	assert(l.getHead()->value == 1);  
	assert(l.getHead()->next->value == 2);   
	printf("Test10 Passed!\n");
}
void test11() {
	LinkedList l;  
	l.addToListAtPosition(0, 1);  
	l.addToListAtPosition(1, 2);   
	l.addToListAtPosition(2, 3);
	l.addToListAtPosition(3, 4);
	l.reverseList();  
	assert(l.getHead()->value == 4);  
	assert(l.getHead()->next->value == 3); 
	printf("Test11 Passed!\n");
}

int main() { 
	test1();  
	test2();  
	test3();   
	test4();   
	//1 through 4 work so far the only issue we could run into is that i could have written without taking into consideration
	//consideration that we operate at a 0 node for a given period in time
	test5();   
	//works
	test6();   
	test7();   
	test8();   
	test9();   
	test10();   
	test11(); }

