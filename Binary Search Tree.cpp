#include <iostream>
#include <cmath>
#include <windows.h>
#include <queue>
#include <conio.h>
#define SIZE 120

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* find_min(struct Node* temp){
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}
struct Node* find_max(struct Node* temp){
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}
int find_height(struct Node* temp){
	if(temp == NULL) return -1;
	int left_height = find_height(temp->left);
	int right_height = find_height(temp->right);
	return fmax(left_height, right_height) + 1;
}
struct Node* delete_node(struct Node* temp, int data){
	if(temp == NULL) return temp;
	else if(data < temp->data) temp->left = delete_node(temp->left, data);
	else if(data > temp->data) temp->right = delete_node(temp->right, data);
	else{
		if(temp->left == NULL && temp->right == NULL){
			delete(temp);
			temp = NULL;
		} else if(temp->left == NULL){
			struct Node* current = temp;
			temp = temp->right;
			delete(current);
		} else if(temp->right == NULL){
			struct Node* current = temp;
			temp = temp->left;
			delete(current);
		} else{
			struct Node* current = find_min(temp->left);
			temp->data = current->data;
			temp->left = delete_node(temp->left, current->data);
		}
		return temp;
	}
}
struct Node* insert_node(struct Node* temp, int data){
	if(temp==NULL){
		struct Node* newNode = new Node();
		newNode->data = data;
		newNode->left = newNode->right = NULL;
		temp = newNode;
	}
	else if(data <= temp->data) temp->left = insert_node(temp->left, data);
	else{
		temp->right = insert_node(temp->right, data);
	} 
	return temp;
}
void breadth_first(struct Node* temp){
	if(temp == NULL) return;
	std::queue<struct Node*> q;
	q.push(temp);
	while(!q.empty()){
		struct Node* current = q.front();
		std::cout << current->data << " ";
		if(current->left != NULL) q.push(current->left);
		if(current->right != NULL) q.push(current->right);
		q.pop();
	}
}
void preorder(struct Node* temp){
	if(temp == NULL) return;
	std::cout << temp->data << " ";
	preorder(temp->left);
	preorder(temp->right);
}
void inorder(struct Node* temp){
	if(temp == NULL) return;
	inorder(temp->left);
	std::cout << temp->data << " ";
	inorder(temp->right);
}
void postorder(struct Node* temp){
	if(temp == NULL) return;
	postorder(temp->left);
	postorder(temp->right);
	std::cout << temp->data << " ";
}

int main(){
	struct Node* head = NULL;
	int n, inp1, inp2;
	std::cout << "Enter the number of nodes: ";
	std::cin >> n;
	while(n--){
		std::cout << "Enter a number: ";
		std::cin >> inp1;
		head = insert_node(head, inp1);
	}
	while(1){
		system("cls");
		std::cout << "[1] Insert another node" << std::endl;
		std::cout << "[2] Delete a node" << std::endl;
		std::cout << "[3] Print the height of the tree" << std::endl;
		std::cout << "[4] Traverse the tree" << std::endl;
		std::cout << "[5] Find the maximum value" << std::endl;
		std::cout << "[6] Find the minimum value" << std::endl;
		std::cout << "[7] Exit" << std::endl;
		std::cin >> inp1;
		system("cls");
		switch(inp1){
			case 1:
				std::cout << "Enter a number: ";
				std::cin >> inp2;
				insert_node(head, inp2);
				break;
			case 2:
				std::cout << "Enter a number to delete: ";
				std::cin >> inp2;
				delete_node(head, inp2);
				break;
			case 3:
				std::cout << "The height of the tree is " <<  find_height(head) << std::endl;
				break;
			case 4:
				std::cout << "[1] Breadth First search" << std::endl;
				std::cout << "[2] Preorder traversal" << std::endl;
				std::cout << "[3] Inorder traversal" << std::endl;
				std::cout << "[4] Postorder traversal" << std::endl;
				std::cin >> inp2;
				switch(inp2){
					case 1:
						breadth_first(head);
						break;
					case 2:
						preorder(head);
						break;
					case 3:
						inorder(head);
						break;
					case 4:
						postorder(head);
						break;
					default:
						break;
				}
				break;
			case 5:
				std::cout << "The maximum value of the tree is " << find_max(head)->data << std::endl;
				break;
			case 6:
				std::cout << "The minimum value of the tree is " << find_min(head)->data << std::endl;
				break;
			case 7:
				return 0;
			default:
				break;
		}
		std::cout << std::endl << "Press any key to continue.. ";
		getch();
	}
	return 0;
}
