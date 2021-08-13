#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* NewNode(int x)
{
	node* New_Node = new node;
	New_Node->data = x;
	New_Node->next = NULL;
	return New_Node;
}
node* InsertNode(node* head, int x)
{
	if (head == NULL)
	{
		return NewNode(x);
	}
	else
		head->next = InsertNode(head->next, x);
		return head;
}
void Traverse(node* head)
{
	if (head == NULL)
		return;
	cout << head->data << " ";
	Traverse(head->next);
	
}
void Reverse_Triverse(node* temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{
		Reverse_Triverse(temp->next);
		cout << temp->data << " ";
		
	}
}
node* DeleteNode(node* head, int k)
{
	if (k < 1)
		return head;
	if (head == NULL)
		return NULL;
	if (k == 1)
	{
		node* n = head->next;
		delete(head);
		return n;
	}
	head->next = DeleteNode(head->next, k - 1);
		return head;
}
void Display()
{
	//node* head = NULL;
	node* temp = NULL;
	temp = InsertNode(temp, 10);
	temp = InsertNode(temp, 20);
	temp = InsertNode(temp, 30);
	temp = InsertNode(temp, 40);
	temp = InsertNode(temp, 50);
	temp = InsertNode(temp, 60);
	Traverse(temp);
	cout << endl;
	/*head = DeleteNode(head, 5);
	cout << "New list \n";
	Traverse(head);*/
	cout << "Reversed triverse is \n";
	Reverse_Triverse(temp);

}
int main()
{
	Display();
	return 0;
}