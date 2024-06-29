//circular linked list data structure --Renu Jha 20/440 3rd sem
//head->data1->data2->data3...............data_n->head  
//there will be no null conected value
//data_n->next=head;(data_n before null value)
/*Write a program to implement circularly linked list which supports the following operations:
(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointer**
(viii) Concatenate two circularly linked lists*/
#include<iostream>
using namespace std;

class Cnode{
	public:  
		int info;
		Cnode* next;
		
		Cnode(int val){
			info=val;
			next=NULL;
		}
};  


void insertAtFront(Cnode* &head, int val){  //------------>(i)
	Cnode *n=new Cnode(val);
	if(head==NULL){
		n->next=n;
		head=n;
		return;
	}
	Cnode* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
	head=n;
}
Cnode *search(Cnode* &head, int x) //-------------------->(vii)
{
    Cnode *temp=head;
	while(temp->info != x)	
	{
		temp=temp->next;
		if(temp==head)
		{
			cout<<"Element not found in the list.";
	        break;
		}
		else continue;
	}
	return temp; //found at this
}
void display(Cnode* head){
	
	Cnode* temp=head;
	int tempinfo=temp->info;
	do{
		cout<<temp->info<<"-->";
		temp=temp->next;}
		while(temp!=head);
		cout<<tempinfo;
	
	cout << endl;
	
		
	}

void insertAtTail(Cnode* &head,int val){  //------------->(iii)
	if(head==NULL){
		insertAtFront(head,val);
		return;
	}
	Cnode* n=new Cnode(val);
	Cnode* temp=head;
	
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
}
void insertAfter(Cnode* head,int x,int y){ //insert-x after value y of LinkedList------------->(ii)
   Cnode* temp=head->next;
   Cnode* n=new Cnode(x);
   n->info=x;
   while(temp->info!=y){
   	temp=temp->next;
   }
   n->next=temp->next;
   temp->next=n;
   
}
void concatenation(Cnode* &head,Cnode*  &head2) //to concatenate two linked list------>(viii)
{   cout<<"\nEnter one more list to concatenate :"; 
   int n;
    cout<<"\nEnter no. of elements in new list :";cin>>n;
   head2=NULL;
    for(int i=0;i<n;i++){ 
	    int sc;
		cout<<"\nwhat do you want to insert at "<<i<<" position :";cin>>sc;
		insertAtTail(head2,sc);  }
	Cnode* temp=head;
	while(temp==NULL || head2 == NULL)
	{
		cout<<"Either one of the list is empty.";
	}
	while(temp->next !=head)
	{
		temp=temp->next;
	}
	Cnode* x =head2;
	temp->next=x;
	while(x->next!=head2)
	{
		temp->next=x;
		temp=temp->next;
		x=x->next;
	}
	x->next=head;
}
void deleteAtHead(Cnode* &head){ //------->(v)
    
	Cnode* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	if(temp->next==NULL){
		cout<<"\nAll elements deleted already";}
	else 
	{  
	Cnode * todel=head;
	temp->next=head->next;
	head=head->next;
	
	delete todel;}
}
void removeFromBack(Cnode* &head){//---------->(iv)
	Cnode* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	if(temp->next==NULL){
		cout<<"\nAll elements deleted already";}
	else 
	{  
	Cnode * todel=head;
	temp->next=head->next;
	head=head->next;
	
	delete todel;}
}
void remove_this(Cnode* &head,int val){//---------------->(vi)
	if(head->info==val){
		deleteAtHead(head);
		return;
	}
	Cnode* temp=head;
	while(temp->next->info!=val){
		temp=temp->next;
	}
	Cnode* torem=temp->next;
	temp->next=temp->next->next;
	delete torem;
	
}
void deletion(Cnode* &head,int pos){//------->(x)
	if(pos==1){
		deleteAtHead(head);
		return;
	}
	Cnode* temp=head;
	int c=1;
	while(c!=pos-1){
		temp=temp->next;
		c++;
	}
	if(head->next==head){
		cout<<"->Buffer values"; }
	
	Cnode *todel=temp->next;
	temp->next=temp->next->next;
	
	delete todel;
}





int main(){
int p,n,choice;
	Cnode* head=NULL;
	//int n;
	cout<<"\nWelcome to Circular Linked List implimentation.......................>>>>>>>>\n\n";
	char ch='y';
	cout<<"\nHow many elements you want to insert : ";cin>>n;
	cout<<"\nDo you want to insert starting from :\n1.HEAD\n2.TAIL   : ";
	cin>>choice;
	switch(choice){
    case 1:	for(int i=0;i<n;i++){ 
	    int e;
		cout<<"\nwhat do you want to insert at "<<i<<" position :";cin>>e;
		insertAtTail(head,e);
	}  break;
	case 2:	for(int i=0;i<n;i++){ 
	    int e;
		cout<<"\nwhat do you want to insert at "<<i<<" position :";cin>>e;
		insertAtFront(head,e); }  }


	cout << "\nElements of the list are: ";

	// Print the list
	display(head);
	cout << endl;
	while(ch=='y'){ int cho;
	cout<<"\n(i) Insert an element x at the front of the circularly linked list  **";
cout<<"\n(ii) Insert an element x after an element y in the circularly linked list";
cout<<"\n(iii)Insert an element x at the back of the circularly linked list **";
cout<<"\n(iv) Remove an element from the back of the circularly linked list**";
cout<<"\n(v) Remove an element from the front of the circularly linked list**";
cout<<"\n(vi) remove the element x from the circularly linked list**";
cout<<"\n(vii)Search for an element x in the circularly linked list and return its pointer**";
cout<<"\n(viii) Concatenate two circularly linked lists";
cout<<"\n(ix)Display list ";
cout<<"\n(x)Delete an element from a position";
cout<<"\n\nChoose from above";cin>>cho;
switch(cho){
    case 10:		
    cout<<"\nat what position you want to delete :";cin>>p;
	// Delete node at position e.
	deletion(head,p);
      
	cout << "\nNew Elements of the list are: ";
	display(head);
    break;
    case 1:int el;
    cout<<"\nEnter the element: ";cin>>el;
    insertAtFront(head,el);
    break;
    case 2: int e1,e2;
    cout<<"\nEnter the element to be inserted";cin>>e1;
    cout<<"\nEnter element after which you want to inserted :";cin>>e2;
    insertAfter(head,e1,e2);
    break;
    case 3: 
	int e3;
	cout<<"\nEnter element :";cin>>e3;
	insertAtTail(head,e3);
	break;
	case 4:
	removeFromBack(head);
	break;
	case 5:deleteAtHead(head);
	break;
	case 6: int e4;
	cout<<"\nEnter the element you want to delete :";cin>>e4;
	remove_this(head,e4);
	break;
	case 7: int e5;
	cout<<"\nWhich element's address you want to search :";cin>>e5;
	cout<<"\nYour address : "<<search(head,e5);
	break;
	case 8: Cnode* head2;
	
	concatenation(head,head2);
	break;
	case 9: display(head);
	break;}
	cout<<"\nDo you want to continue operations on your list :(y/n) ::";cin>>ch;
}
return 0;
}
/*
(ix)Display list
(x)Delete an element from a position

Choose from above1

Enter the element: 100

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above9
100-->11-->22-->33-->44-->55-->100

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above2

Enter the element to be inserted0

Enter element after which you want to inserted :33

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above9
100-->11-->22-->33-->0-->44-->55-->100

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above3

Enter element :1000

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above9
100-->11-->22-->33-->0-->44-->55-->1000-->100

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above4

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above9
11-->22-->33-->0-->44-->55-->1000-->11

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above5

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above9
22-->33-->0-->44-->55-->1000-->22

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above6

Enter the element you want to delete :44

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above9
22-->33-->0-->55-->1000-->22

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above7

Which element's address you want to search :0

Your address : 0x3f5750
Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above8

Enter one more list to concatenate :
Enter no. of elements in new list :3

what do you want to insert at 0 position :111

what do you want to insert at 1 position :222

what do you want to insert at 2 position :333

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above9
22-->33-->0-->55-->1000-->111-->222-->333-->22

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above10

at what position you want to delete :4

New Elements of the list are: 22-->33-->0-->1000-->111-->222-->333-->22

Do you want to continue operations on your list :(y/n) ::y

(i) Insert an element x at the front of the circularly linked list  **
(ii) Insert an element x after an element y in the circularly linked list
(iii)Insert an element x at the back of the circularly linked list **
(iv) Remove an element from the back of the circularly linked list**
(v) Remove an element from the front of the circularly linked list**
(vi) remove the element x from the circularly linked list**
(vii)Search for an element x in the circularly linked list and return its pointe
r**
(viii) Concatenate two circularly linked lists
(ix)Display list
(x)Delete an element from a position

Choose from above9
22-->33-->0-->1000-->111-->222-->333-->22

Do you want to continue operations on your list :(y/n) ::n

--------------------------------
Process exited after 205.1 seconds with return value 0
Press any key to continue . . . */
