/* Name: Hassona hasan balla
 * Class: 2nd class
 * Department: computer engineering
*/
/*iostream stands for standard input-output stream this header file
 *  contains definitions to objects like cin, cout, cerr etc ...*/
#include <iostream>
using namespace std;
/*it is short for charachter which is a data type that holds one
 *charachter, and the number is its maximum allowed length*/
struct Node {
	int data;
	struct Node *next;
};
/*A node is a struct with at least a data field and a reference to a node
 *of the same type*/
struct Node* top = NULL;
void push(int val) {
/* is a pointer variable of node datatype*/
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->next = top;
	top = newnode;
}
struct node {
	int info;
	struct node *next;
	}*start;
/*creating class here*/
	class list {
		public:
/*puplic is for be available at any function*/
			node* create_node(int);
			void insert_begin();
			void insert_pos();
			void insert_last(); 
			void delete_pos();
			void search();
			void displayo();
			list() {
				start = NULL;
			}
	};
//done making class
node *list::create_node(int value)
		{
		struct node *temp;
		temp = new(struct node);
		if (temp == NULL){
			cout<<"\nError"<<endl;
			exit(1);
		}
/*creat list with only integer*/
		else {
			temp->info = value;
			temp->next = NULL;     
			return temp;
		}
		}
void list::insert_begin()
		{
			int value;
			cout<<"\nEnter the value to be add: ";
			cin>>value;
			struct node *temp, *p;
			temp = create_node(value);
/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
			if (start == NULL) {
				start = temp;
				start->next = NULL;
			}
			else
			{
				p = start;
				start = temp;
				start->next = p;
			}
			cout<<"\nElement Inserted at beginning"<<endl;
		}
void list::insert_last()
/*this is code to insert value in ending*/
		{
			int value;
			cout<<"\nEnter the value to be inserted: ";
			cin>>value;
			struct node *temp, *s;
			temp = create_node(value);
			s = start;
			while (s->next != NULL)
			{
				s = s->next;
			}
			temp->next = NULL;
			s->next = temp;
			cout << "\nElement Inserted at end" << endl;  
		}
void list::insert_pos()
//this is line to insert values in position
		{
			int value, pos, counter = 0; 
			cout << "\nEnter the value to be inserted: ";
			cin >> value;
			struct node *temp, *s, *ptr;
			temp = create_node(value);
			cout << "\nEnter the postion: ";
			cin >> pos;
			int i;
			s = start;
			while (s != NULL)
/*	 while loop statement repeatedly executes a target statement as
 *  long as a given condition is true*/
			{
				s = s->next;
				counter++;
			}
/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
			if (pos == 1) {
				if (start == NULL) {
					start = temp;
					start->next = NULL;
				}
				else {
					ptr = start;
					start = temp;
					start->next = ptr;
				}
			}
/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
			else if (pos > 1  && pos <= counter) {
				s = start;
				for (i = 1; i < pos; i++) {
					ptr = s;
					s = s->next;
				}
				ptr->next = temp;
				temp->next = s;
			}
			else {
				cout<<"\nPositon not found"<<endl;
			}
		}
//element delete functions
void list::delete_pos() {
			int pos, i, counter = 0;
			if (start == NULL) {
				cout<<"\nList is empty"<<endl;
				return;
			}
			cout<<"\nEnter the position: ";
			cin>>pos;
			struct node *s, *ptr;
			s = start;
			if (pos == 1) {
/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
				start = s->next;
			}
			else {
				while (s != NULL) {
					s = s->next;
					counter++;  
				}
				if (pos > 0 && pos <= counter) {
					s = start;
					for (i = 1;i < pos;i++) {
						ptr = s;
						s = s->next;
					}
					ptr->next = s->next;
				}
				else {
					cout<<"\nPosition not found"<<endl;
				}
				free(s);
				cout<<"\nElement deleted"<<endl;
			}
		}
void list::search() {/* Flag variable is used as a signal in programming to let the
	 *program know that a certain condition has met*/
	int value, pos = 0;
	bool flag = false;
	if (start == NULL) {
		cout<<"\nList is empty"<<endl;
		return;
	}
	cout<<"\nEnter the value: ";
	cin>>value;
	struct node *s;
	s = start;
	while (s != NULL) {
/*	 while loop statement repeatedly executes a target statement as
 *  long as a given condition is true*/
		pos++;
		if (s->info == value) {
			flag = true;
			cout<<"\nElement"<<value<<"is found at position "<<pos<<endl;
		}
		s = s->next;
	}
/*flag variable is used as a signal in programming to let the
*program know that a certain condition has met*/
	if (!flag)
	cout<<"\nElement"<<value<<"not found"<<endl;
}
void list::displayo() {
	struct node *temp;
	if (start == NULL) {
/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
		cout<<"\nThe list is empty"<<endl;
		return;
	}
	temp = start;
		cout << "\nElements: " << endl;
		while (temp != NULL) {
			cout << temp->info << "  >>>  ";
			temp = temp->next;
		}
	cout<<"nothing"<<endl;
}
//pop means deleting
void pop() {
	if (top == NULL){
		cout << "\nStack underflow" << endl;
	}
	else {
		cout << "\nThe popped element: " << top->data << endl;
		top = top->next;
	}
}
//this is to show elements in stack
void display() {
	struct Node* ptr;
	if(top == NULL)
	cout << "\nStack is empty";
	else {
		ptr = top;
		cout << "Stack elements: ";
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	cout << endl;
}
int queue[50], n = 50, front = - 1, rear = - 1;
/*element adding function*/
void Insert() {
	int val;
	if (rear == n - 1)
	cout << "\nQueu overflow" << endl;
	else {
		if (front == - 1)
		front = 0;
		cout << "\nInsert the element: ";
		cin >> val;
		rear++;
		queue[rear] = val;
	}
}
//and this is for element delete porposes
void Delete() {
	if (front == - 1 || front > rear) {
		cout << "\nQueue underflow" << endl;
		return ;
	} else {
		cout << "\nElement deleted from queue is: " << queue[front] << endl;
		front++;;
	}
}
//function to delete elements
void Display() {
	if (front == - 1)
	cout << "\nQueue is empty" << endl;
	else {
	cout << "\nQueue elements are: ";
	for (int i = front; i <= rear; i++)
	cout << queue[i]<<" ";
		cout << endl;
}
}
int A;
int main(){
	cout<<"use 1 and 2 and 3"<<endl;
	cout << "\n\nWhat do you want: ";
	cin>>A;
	if (A == 1){
/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
		int ch;
		cout << "1) add to Queue" << endl;
		cout << "2) delete from Queue" << endl;
		cout << "3) Display all the elements of Queue" << endl;
		cout << "4) Exit" << endl;
		do {
/*run code continuosly until it is breaked*/
			cout << "\nEnter your choice : ";
			cin >> ch;
			switch (ch) {
/*switch for options when press keys*/
				case 1: Insert();
					break;
				case 2: Delete();
					break;
				case 3: Display();
					break;
				case 4:
// termninating case to escpae from while
					exit(1);
				default:
					cout<<"\nInvalid choice"<<endl;
					break;
			}
	} while(ch!=4);
	}
	else if (A == 2){
		int ch, val;
		cout << "(1) Push in Stack" << endl;
		cout << "(2) Pop from Stack" << endl;
		cout << "(3) Display Stack" << endl;
		cout << "(4) Exit" << endl;
/*this is for listing the options*/
		do {
/*run code continuosly until it is breaked*/
			cout << "\n\nEnter your choice: ";
			cin >> ch;
			switch(ch) {
/*switch for options when press keys*/
				case 1: {
					cout << "\nEnter a value to be pushed: ";
					cin >> val;
					push(val);
					break;
				}
				case 2: {
					pop();
					break;
				}
				case 3: {
					display();
					break;
				}
				case 4: {
					exit(1);
// termninating case to escpae from while
				}
				default: {
					cout << "\nInvalid Choice" << endl;
					break;
				}
			}
		} while(ch!=4);
	}
	else if (A == 3) {
		int choice;
		list sl;
			start = NULL;
			while (1)
//infinite loop til we meet condition
			{
				cout<<"1- add at beginning"<<endl;
				cout<<"2- add at last"<<endl;
				cout<<"3- add at position"<<endl;
				cout<<"4- Delete"<<endl;
				cout<<"5- Search"<<endl;
				cout<<"6- Display"<<endl;
				cout<<"7- Exit"<<endl;
				cout<<"\nEnter your choice: ";
				cin >> choice;
				switch(choice){
/*switch for options when press keys*/
				case 1:
					sl.insert_begin();
					cout<<endl;
					break;
				case 2:
					sl.insert_last();
					cout<<endl;
					break;
				case 3:
					sl.insert_pos();
					cout<<endl;
					break;
				case 4:
					sl.delete_pos();
					break;
				case 5:
					sl.search();
					cout<<endl;
					break;
				case 6:
					sl.displayo();
					cout<<endl;
					break;
				case 7:
					exit(1);
// termninating case to escpae from while
				default:
					cout<<"\nWrong"<<endl;
					break;
				}
			}
	}
	else if (A == 4) {
		return 0;
//exit program when enter 4
	}
	else {
		cout << "\nWrong\n" << endl;
		exit(1);
//exit when press anything else
	}
	return 0;
/*returning value to the main and 0 is success to state that the
 *program is working fine*/
}
