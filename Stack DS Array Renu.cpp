//Submit implementation of stack using array 
//Time complexity= O(1)..,LIFO structure =Last in first out
//-Renu Jha ,-20/440

#include <iostream>
#include <cstdlib>
using namespace std;
 
                    
#define SIZE 15 // Defining the default capacity of  stack in programme
 

template <class X> //  class to represent a stack
class stack
{
    X *arr;
    int top;
    int capacity;
 
public:
    stack(int size = SIZE);         // constructor
 
    void push(X);
    X pop();
    X peek();
 
    int size();
    bool isEmpty();
    bool isFull();
 
    // destructor
    ~stack() {
        delete[] arr;
    }
};
 
// Constructor to initialize the stack
template <class X>
stack<X>::stack(int size)
{
    arr = new X[size];
    capacity = size;
    top = -1;
}
 
// Function to add an element `x` to the stack
template <class X>
void stack<X>::push(X x)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}
 
// Function to pop the top element from the stack
template <class X>
X stack<X>::pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Removing " << peek() << endl;
 
    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}
 
// Function to return the top element of the stack
template <class X>
X stack<X>::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to return the size of the stack
template <class X>
int stack<X>::size() {
    return top + 1;
}
 
// Utility function to check if the stack is empty or not
template <class X>
bool stack<X>::isEmpty() {
    return top == -1;               // or return size() == 0;
}
 
// Utility function to check if the stack is full or not
template <class X>
bool stack<X>::isFull() {
    return top == capacity - 1;     // or return size() == capacity;
}
 
int main()
{   int n,s,ch;
    cout<<"\nChoose : \n1.String Array or \n2.Integer Array  :";cin>>n;
    if(n==1){
   	cout<<"\nEnter Size :";cin>>s;
    stack<char> pt(s);
    for(int i=0;i<s;i++){
    char st;
    cout<<"\nEnter any character : "<<i+1<<"..\n";cin>>st;
    pt.push(st);
}  char c='y';
  while(c=='y'){
   cout<<"\nWhat do you want to perform :1.Push\n2.Pop\n3.Know size \n4.Want to know 1st element \n5.Want to know Empty or not";
   cin>>ch;
   switch(ch){
   	case 1: char x; 
	   cout<<"\nWhat character you want to push :";cin>>x;
	   pt.push(x);
	   break;
	case 2:pt.pop();
	break;   
	case 3:cout<<"\nTop Element :"<<pt.peek();
	break;
	case 4:cout<<pt.size();
	break;
	case 5:if (pt.isEmpty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    }
    break;
   }
   cout<<"\nWant to continue (y/n) :";cin>>c; }
}
 
    if(n==2){
   	cout<<"\nEnter Size :";cin>>s;
    stack<int> pt(s);
    for(int i=0;i<s;i++){
    int St;
    cout<<"\nEnter any character : "<<i+1<<"..\n";cin>>St;
    pt.push(St);}
    char c='y';
    while(c=='y'){
   cout<<"\nWhat do you want to perform :1.Push\n2.Pop\n3.Know size \n4.Want to know 1st element \n5.Want to know Empty or not";
   cin>>ch;
   switch(ch){
   	case 1: int x; 
	   cout<<"\nWhat integer you want to push :";cin>>x;
	   pt.push(x);
	   break;
	case 2:pt.pop();
	break;   
	case 3:cout<<"\nTop Element :"<<pt.peek();
	break;
	case 4:cout<<pt.size();
	break;
	case 5:if (pt.isEmpty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    }
    break;
   }
   cout<<"\nWant to continue :(y/n) :";cin>>c;}
   
}
 
    return 0;
}


