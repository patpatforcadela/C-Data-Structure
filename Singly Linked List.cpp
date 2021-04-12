#include <iostream>
#include <conio.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head;

void reverse_list(struct Node* temp){
	if(temp->next == NULL)
	{
		head = temp;
		return;
	}
	struct Node* prev = temp;
	reverse_list(temp->next);
	temp->next->next = prev;
	prev->next = NULL;
	return;
}
void print_list(struct Node* temp){
	if(temp == NULL) return;
	std::cout << temp->data << "  ";
	print_list(temp->next);
}
void print_reverse(struct Node* temp){
	if(temp == NULL) return;
	print_reverse(temp->next);
	std::cout << temp->data << "  ";
}
void create_node(int data){
	struct Node* temp; struct Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
		return;
	}
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	return;
}
void insert_node(int data, int index){
	struct Node* newNode = new Node();
	newNode->data = data;
	if(index == 1){
		newNode->next = head;
		head = newNode;
		return;
	}
	struct Node* temp = head;
	for(int i=0; i<index-2; i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return;
}
void delete_node(int index){
	if(head == NULL) return;
	struct Node* temp = head; struct Node* nextNode;
	if(index == 1){
		head = temp->next;
		delete(temp);
		return;
	}
	for(int i=0; i<index-2; i++){
		temp = temp->next;
	}
	nextNode = temp->next;
	temp->next = nextNode->next;
	delete(nextNode);
	return;
}
int main(){
	head = NULL;
	int n, inp, inp2, inp3, inp4;
	std::cout << "Enter the number of nodes: ";
	std::cin >> n;
	while(n--){
		std::cout << "Enter a number: ";
		std::cin >> inp;
		create_node(inp);
	}
	while(1){
		system("cls");
		std::cout << "[1] Insert another node" << std::endl;
		std::cout << "[2] Delete a node" << std::endl;
		std::cout << "[3] Reverse the list" << std::endl;
		std::cout << "[4] Print the reverse of the list" << std::endl;
		std::cout << "[5] Print the list" << std::endl;
		std::cout << "[6] Exit" << std::endl;
		std::cin >> inp;
		system("cls");
		switch(inp){
			case 1:
				std::cout << "[1] Insert at the beginning" << std::endl;
				std::cout << "[2] Insert at the ith position" << std::endl;
				std::cout << "[3] Insert at the end" << std::endl;
				std::cin >> inp2;
				switch(inp2){
					case 1:
						std::cout << "Enter a number: ";
						std::cin >> inp3;
						insert_node(inp3, 1);
						break;
					case 2:
						std::cout << "Enter a number: ";
						std::cin >> inp3;
						std::cout << "Enter the index: ";
						std::cin >> inp4;
						insert_node(inp3, inp4);
						break;
					case 3:
						std::cout << "Enter a number: ";
						std::cin >> inp3;
						create_node(inp3);
						break;
					default:
						break;
				}
				break;
			case 2:
				print_list(head);
				std::cout << std::endl << "Enter the index you want to delete: ";
				std::cin >> inp2;
				delete_node(inp2);
				break;
			case 3:
				reverse_list(head);
				break;
			case 4:
				print_reverse(head);
				break;
			case 5:
				print_list(head);
				break;
			case 6:
				return 0;
				break;
			default:
				break;
			}
			std::cout << std::endl << "Press any key to continue .. ";
			getch();
		}
	return 0;
}
