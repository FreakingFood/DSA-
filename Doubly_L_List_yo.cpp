//Doubly linked list Renu jha 20/440
//we will maintain two pointer prev* & next*(to creat two links from each node
//one forword node and one backword(--> & <--)
/*4. Write a program to implement doubly linked list which supports the following operations:
(i)Insert an element x at the beginning of the doubly linked list**
(ii) Insert an element x at position in the doubly linked list
(iii)Insert an element x at the end of the doubly linked list**
(iv) Remove an element from the beginning of the doubly linked list**
(v) Remove an element from position in the doubly linked list.**
(vi) Remove an element from the end of the doubly linked list**
(vii) Search for an element x in the doubly linked list and return its pointer
(viii) Concatenate two doubly linked lists */

#include<iostream>
using namespace std;

class Dnode{
	public:
		int info;
		Dnode* next;
		Dnode* prev;
		Dnode(int val){
			info=val;
			next=NULL;
			prev=NULL;
		}
};
void insertAtHead(Dnode* &head,int val){
	Dnode* n=new Dnode(val);
	n->next=head;
	if(head!=NULL){
		head->prev=n;
	}
	head=n;
}
void insertAtTail(Dnode* &head,int val){
	if(head==NULL){
		insertAtHead(head,val);
		return;
	}
	Dnode* n=new Dnode(val);
	Dnode* temp=head;
	
	while(temp->next !=NULL){
		temp=temp->next;
	}
	temp->next=n;
	n->prev=temp;
}
//			cout<<"->";
		//temp=temp->next	}
void insertAT(Dnode* &head,int val,int pos){//------>(ii)
		Dnode* p=new Dnode(val);
	if(pos==1)
	{
		insertAtHead(head,val);
	}
	else
	{
		int count=1;
		Dnode* temp=head;
		while(count<(pos-1))
		{
			count++;
			temp=temp->next;
		}
		if(temp!=0)
		{
			p->next=temp->next;
			p->prev=temp;
			temp->next=p;
			p->next->prev=p;
		}
		else
			cout<<"\n xxxxx WRONG POSITION xxxxx";
}  }

void concatenation(Dnode* head1,Dnode* head2) //to display list
{ cout<<"\nEnter one more list to concatenate :"; 
int n;
cout<<"\nEnter no. of elements in new list :";cin>>n;
 head2=NULL;
 for(int i=0;i<n;i++){ 
	    int e;
		cout<<"\nwhat do you want to insert at "<<i<<" position :";cin>>e;
		insertAtHead(head2,e);}

if(head1==NULL || head2==NULL){
	cout<<"\neither one of the list is empty!! ";
}
Dnode *temp=head1;
    while(temp->next!=NULL){
    	temp=temp->next;}
    temp->next=head2;
	head2->prev=temp;	
	
}

void display(Dnode* head){
	Dnode* temp=head;
	cout<<"NULL<--";
	while(temp!=NULL){
		cout<<temp->info<<"<--> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
void deletion(Dnode* &head,int pos){
  if(head==NULL){
		cout<<"\nList is already empty!!  \n";
	}
	if(pos==1){
		head=head->next;
		return;
	}
	Dnode* temp=head;
	if(temp==NULL){
		cout<<"\nList is already empty!!  \n";
	}
	int c=1;
	while(temp!=NULL && c!=pos){
		temp=temp->next;
		
		c++;
	}

	temp->prev->next=temp->next; //prev<--Temp-->next-=====prev<-->next
	if(temp->next!=NULL){
		temp->next->prev=temp->prev;//deltet both links
	}
	
	delete temp;
}
void delete_from_head(Dnode* &head) //remove info from front of li------------->(iv)
{
	
	
		Dnode* temp=head; //save current head  
		head=head->next; //skip over old head 
		head->prev=NULL; // point to null
		delete temp; //delete old head
	
}

void delete_from_tail(Dnode* &head) //remove info from last of list--------------->(vi)
{
	if(head->next==head && head->prev==head)
		delete head;
	else // more than 1 node
	{   Dnode* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	   	temp->prev->next=temp->next; //prev<--Temp-->next-=====prev<-->next
	if(temp->next!=NULL){
		temp->next->prev=temp->prev;//deltet both links
	}
	
	delete temp;
}
}
Dnode* search(Dnode* &head,int x) //search for an element x in list and return its pointer---------->(vii)
{
	Dnode* temp=head;
	while(temp->info != x)	
	{
		temp=temp->next;
		if(temp==NULL)
		{
			cout<<"Element not found in the list.";
			return 0;
		}
	}
	return temp;
}


int main(){
	int p,n,choice;
	Dnode* head=NULL;
	//int n;
	cout<<"\nWelcome to Doubly Linked List implimentation.......................>>>>>>>>\n\n";
	char ch='y';
	cout<<"\nHow many elements you want to insert : ";cin>>n;
	cout<<"\nDo you want to insert starting from :\n1.HEAD\n2.TAIL   : ";//
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
		insertAtHead(head,e); }  }


	cout << "\nElements of the list are: ";

	// Print the list
	display(head);
	cout << endl;
	while(ch=='y'){
		int cho;
cout<<"\nwhat do you want to perform:";
	cout<<"\n(i) Insert an element x at the beginning of the doubly linked list";
cout<<"\n(ii) Insert an element x at position in the doubly linked list";
cout<<"\n(iii)Insert an element x at the end of the doubly linked list";
cout<<"\n(iv) Remove an element from the beginning of the doubly linked list";
cout<<"\n(v) Remove an element from position in the doubly linked list";
cout<<"\n(vi) Remove an element from the end of the doubly linked list";
cout<<"\n(vii) Search for an element x in the doubly linked list and return its pointer";
cout<<"\n(viii) Concatenate two doubly linked lists ";
cout<<"\nDisplay the list formed";
cin>>cho;
switch(cho){
	case 2:int el6,n_;
	cout<<"\nEnter element to be inserted:";cin>>el6;
	cout<<"\nEnter the position:";cin>>el6;
		insertAtHead(head,el6);
		break;
	case 5:
    cout<<"\nat what position you want to delete :";cin>>p;
	// Delete node at position e.
	deletion(head,p);

	cout << "\nNew Elements of the list are: ";
	display(head);
	cout << endl;
	break;
	case 1:
	int el;
	cout<<"\nEnter the element :";cin>>el;
	insertAtHead(head,el);
	break;
	case 3:int el2;
	cout<<"\nEnter any element :";cin>>el2;
	insertAtTail(head,el2);
	break;
	case 4:
	delete_from_head(head);
	break;
	case 6:
	delete_from_tail(head);
	break;
	case 7:int el5;
	cout<<"\nEnter the element";cin>>el5;
	cout<<search(head,el5);
	break;
	case 8:Dnode* head2;
	concatenation(head,head2);
	break;
    case 9:display(head);
		break;}
	cout<<"\nDo you want to continue operations on your list :(y/n) ::";cin>>ch;
} 


	return 0;
	
}

