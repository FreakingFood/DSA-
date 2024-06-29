// C++ program to Implement a stack 
//using singly linked list 
//Impliment stack Using Linked List :
//Time complexity= O(1)..,LIFO structure =Last in first out
//-Renu Jha ,-20/440

#include <bits/stdc++.h> 
#include<iostream>
using namespace std; 
 
// Declare linked list node 
 

class Node 
{ 
   public:
    int data; 

    class Node* link; 
}; 
 

class Node* top; 
 
// Utility function to add an element 
// data in the stack insert at the beginning 

void push(int data) 
{ 

     

    // Create new node temp and allocate memory 

     Node* temp; 

    temp = new Node(); 
 

    // Check if stack (heap) is full. 

    // Then inserting an element would 

    // lead to stack overflow 

    if (!temp)

    { 

        cout << "\nHeap Overflow"; 

        exit(1); 

    } 
 

    // Initialize data into temp data field 

    temp->data = data; 
 

    // Put top pointer reference into temp link 

    temp->link = top; 
 

    // Make temp as top of Stack 

    top = temp; 
} 
 
// Utility function to check if 
// the stack is empty or not 

int isEmpty() 
{ 

    return top == NULL; 
} 
 
// Utility function to return top element in a stack 

int peek() 
{ 

     

    // Check for empty stack 

    if (!isEmpty()) 

        return top->data; 

    else

        exit(1); 
} 
 
// Utility function to pop top 
// element from the stack 

void pop() 
{ 

     Node* temp; 
 

    // Check for stack underflow 

    if (top == NULL) 

    { 

        cout << "\nStack Underflow" << endl; 

        exit(1); 

    } 

    else

    { 

         

        // Top assign into temp 

        temp = top; 
 

        // Assign second node to top 

        top = top->link; 
 

        // Destroy connection between

        // first and second 

        temp->link = NULL; 
 

        // Release memory of top node 

        free(temp); 

    } 
} 
 
// Function to print all the 
// elements of the stack 

void display() 
{ 

     Node* temp; 
 

    // Check for stack underflow 

    if (top == NULL)

    { 

        cout << "\nStack Underflow"; 

        exit(1); 

    } 

    else

    { 

        temp = top; 

        while (temp != NULL)

        { 
 

            // Print node data 

            cout << temp->data << "-> "; 
 

            // Assign temp link to temp 

            temp = temp->link; 

        } 
        cout<<"NULL";

    } 
} 
 
// Driver Code 

int main() 
{ 
    int s,ch;
    cout<<"\nEnter Size :";cin>>s;
    for(int i=0;i<s;i++){
    int St;
    cout<<"\nEnter any integer : "<<i+1<<"..\n";cin>>St;
    push(St);}
    char c='y';
    while(c=='y'){
   cout<<"\nWhat do you want to perform :1.Push\n2.Pop\n3.Know size \n4.Want to know 1st element \n5.Want to know Empty or not\n6.Display";
   cin>>ch;
   switch(ch){
   	case 1: int x; 
	   cout<<"\nWhat integer you want to push :";cin>>x;
	   push(x);
	   break;
	case 2:pop();
	break;   
	case 4:cout<<"\nTop Element :"<<peek();
	break;
	case 3:cout<<s;
	break;
	case 5:{
	if (isEmpty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    } }
    break;
    case 6:display();
   }
   cout<<"\nWant to continue :(y/n) :";cin>>c;}
          

    return 0; 
}
