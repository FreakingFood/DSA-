//Q4 Implement Priority Queue using heap
//---Renu kumari Jha , ---20/440

#include <iostream>
#include <vector>
using namespace std;

// Function to swap position of two elements
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Function to heapify the tree
void heapify(vector<int> &hT, int i) {
  int size = hT.size();
  
  // Find the largest among root, left child and right child
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}

// Function to insert an element into the tree
void insert(vector<int> &hT, int newNum) {
  int size = hT.size();
  if (size == 0) {
    hT.push_back(newNum);
  } else {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(hT, i);
    }
  }
}

// Function to delete an element from the tree
void deleteNode(vector<int> &hT, int num) {
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++) {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(hT, i);
  }
}

// Print the tree
void printArray(vector<int> &hT) {
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

// Driver code
int main() {
  vector<int> heapTree;
  int n; char ch;
  
  cout<<"\nHow many elements you want to insert : ";cin>>n;
  for(int i=0;i<n ;i++){
  	int m;
  	cout<<"\nEnter element at "<<i<<" Position : ";cin>>m;
  	insert(heapTree, m);
  }

  cout << "Max-Heap array: ";
  printArray(heapTree);
  cout<<"\nDo you want to delete ? (y/n) :";cin>>ch;
  if(ch=='y'){
  int p;
  cout<<"\nWhat do you want to delete : ";cin>>p;
  deleteNode(heapTree, p);  }

  cout << "After deleting an element: ";

  printArray(heapTree);
}
/*


How many elements you want to insert : 5

Enter element at 0 Position : 1

Enter element at 1 Position : 2

Enter element at 2 Position : 3

Enter element at 3 Position : 4

Enter element at 4 Position : 5
Max-Heap array: 5 4 1 3 2

Do you want to delete ? (y/n) :y

What do you want to delete : 4
After deleting an element: 5 3 1 2

--------------------------------
Process exited after 27.89 seconds with return value 0
Press any key to continue . . .

*/
