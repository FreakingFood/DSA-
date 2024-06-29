#include<iostream>
using namespace std;
template <class T>
class lower_triangular_matrix{
	public:
	lower_triangular_matrix(int N=10);
	~lower_triangular_matrix()
	{
		delete []element;
	}
	T get(int i,int j) const;
	void set(int i,int j,const T& value);
	private:
	int n; // dimention of the matrix
	T *element;// 1D array	
};
template<class T>
lower_triangular_matrix<T>::lower_triangular_matrix(int N)
{
	if(N<1)
	 cout<<" invalid dimention of matrix"<<endl;
	 n=N;
	 element=new T[n*(n-1)/2];
}
template<class T>
T lower_triangular_matrix<T>::get(int i,int j) const
{  
   if(i<1||j<1||i>n||j>>n)
    cout<<" matrix index out of bounds"<<endl;
   if(i>=j)
       return element[(i*(i-1))/2+j-1];
   else
       return 0;
}
template<class T>
void lower_triangular_matrix<T>::set(int i,int j,const T& value)
{
	// store new value at (i,j) th position
	if(i<1||j<1||i>n||j>n)
	  cout<<" invalid index of matrix"<<endl;
	  
	  if(i>=j)
	  	element[(i*(i-1))/2+j-1]=value;
	  else
	  {
	  	if(value!=0)
	  	{
	  		cout<<"elements in lower triangular matrix must be zero"<<endl;
	    }	
	  }
}
int main()
{   
    lower_triangular_matrix<int> d(3);
    d.set(1,1,1);
    d.set(1,2,0);
    d.set(1,3,0);
    d.set(2,1,8);
    d.set(2,2,6);
    d.set(2,3,0);
    d.set(3,1,5);
    d.set(3,2,7);
    d.set(3,3,9);
    cout<<"lower triangular matrix is:"<<endl;
    cout<<d.get(1,1)<<" "<<d.get(1,2)<<" "<<d.get(1,3)<<endl;
    cout<<d.get(2,1)<<" "<<d.get(2,2)<<" "<<d.get(2,3)<<endl;
    cout<<d.get(3,1)<<" "<<d.get(3,2)<<" "<<d.get(3,3)<<endl;
    return 0;	
}


	
	
	
	
	
	

