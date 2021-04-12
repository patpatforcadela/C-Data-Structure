#include <iostream>
#include <conio.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* top;

void push(int data){
	struct Node* newNode = new Node();
	newNode->data = data;
	newNode->next = top;
	top = newNode;
}
int pop(){
	struct Node* temp = top;
	top = temp->next;
	int data = temp->data;
	delete(temp);
	return data;
}
void print_stack(struct Node* temp){
	if(temp == NULL)return;
	std::cout << temp->data << "  ";
	print_stack(temp->next);
}
void empty_stack(struct Node* temp){
	if(temp->next == NULL) return;
	empty_stack(temp->next);
	delete(temp->next);
}
int main(){
	top = NULL;
	int n, inp1, inp2;
	std::cout << "Enter the number of nodes: ";
	std::cin >> n;
	while(n--){
		std::cout << "Enter a number: ";
		std::cin >> inp1;
		push(inp1);
	}
	while(1){
		system("cls");
		std::cout << "[1] Push another node" << std::endl;
		std::cout << "[2] Pop a node" << std::endl;
		std::cout << "[3] Print the stack" << std::endl;
		std::cout << "[4] Print the top" << std::endl;
		std::cout << "[5] Empty the stack" << std::endl;
		std::cout << "[6] Exit" << std::endl;
		std::cin >> inp1;
		switch(inp1){
			case 1:
				std::cout << "Enter a number: ";
				std::cin >> inp2;
				push(inp2);
				break;
			case 2:
				if(top == NULL){
					std::cout << "Error occured! Stack is empty" << std::endl;
				} else{
					pop();
				}
				break;
			case 3:
				print_stack(top);
				break;
			case 4:
				if(top == NULL){
					std::cout << "Error occured! Stack is empty" << std::endl;
				} else{
					std::cout <<"The data at the top is " << top->data;
				}
				break;
			case 5:
				if(top == NULL){
					std::cout << "Stack is already empty";
				} else{
					empty_stack(top);
					top = NULL;
				}
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
