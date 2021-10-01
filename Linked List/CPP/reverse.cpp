#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

class NodeOperation{
public:

	void pushNode(class Node** head_ref,int data_val){
	
		class Node *new_node = new Node();
		new_node->data = data_val;
		
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	
	void printNode(class Node *head){
		while(head != NULL){
			cout <<head->data << "->";
			head = head->next;
		}
		cout << "NULL" << endl;
	}
};

Node* reverse(Node* head) {
    Node* current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
} 

int main(){
	class Node *head = NULL;
	class NodeOperation *temp = new NodeOperation();
	for(int i=5; i>0; i--)
		temp->pushNode(&head, i);
    temp -> printNode(head);
    cout << "\n";
    temp -> printNode(reverse(head));
	return 0;
}
