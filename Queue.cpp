#include <iostream>
#include <conio.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head; struct Node* tail;

void enqueue(int data){
	struct Node* newNode = new Node();
	newNode->data = data;
	if(head==NULL && tail == NULL){
		newNode->next = NULL;
		head = tail = newNode;
		return;
	}
	tail->next = newNode;
	tail = newNode;
}
void dequeue(struct Node* temp){
	head = temp->next;
	delete(temp);
}
void print_queue(struct Node* temp){
	if(temp == NULL)return;
	std::cout << temp->data << "  ";
	print_queue(temp->next);
}
int main(){
	head = NULL, tail = NULL;
	int n, inp1, inp2;
	std::cout << "Enter the number of nodes: ";
	std::cin >> n;
	while(n--){
		std::cout << "Enter a number: ";
		std::cin >> inp1;
		enqueue(inp1);
	}
	while(1){
		system("cls");
		std::cout << "[1] Enqueue another node " << std::endl;
		std::cout << "[2] Dequeue a node " << std::endl;
		std::cout << "[3] Print the queue " << std::endl;
		std::cout << "[4] Exit " << std::endl;
		std::cin >> inp1;
		switch(inp1){
			case 1:
				std::cout << "Enter a number: ";
				std::cin >> inp2;
				enqueue(inp2);
				break;
			case 2:
				if(head == NULL && tail == NULL){
					std::cout << "Error occured! Queue is empty";
				} else{
					dequeue(head);
				}
				break;
			case 3:
				print_queue(head);
				std::cout << std::endl;
				break;
			case 4:
				return 0;
			default:
				break;
		}
		std::cout << "Press any key to continue ..";
		getch();
	}
	return 0;
}
