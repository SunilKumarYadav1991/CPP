/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 17 Aug 2021
* Description:  15. Define a pvector to be like a vector of pointers except that it contains pointers to objects
*      and its destructor deletes each object.
*	16. Define an ovector that is like pvector except that the [ ] and * operators return a reference to the
*       object pointed to by an element rather than the pointer. 
*       17. Define an ownership_vector that hold pointers to objects like pvector but provides a mechanism for the
*        user to decide which objects are owned by the vector (i.e., which objects are deleted by the destructor).
*	 Hint: This exercise is simple if you were awake for Chapter 13.
*	18. Define a range-checked iterator for vector (a random-access iterator).
*
* Note: 
***********************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

//template<typename T>
class pvector
{
public:
	pvector()=delete;
	pvector(int n)
	{
		p_elem=vector<T*>  ;
		sz=n;
		offset=0;
		
	}
	int& at(int i,int j)
	{ 
	
		return p_elem[i][j];
	}
	
	~pvector()
	{
		cout<<"~pvector()\n";
		delete[] p_elem;
	}
	
private:
	vector<int*> p_elem;
	int sz;
	int offset;

};


int main()
{
	pvector pptr(5);
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j)
			pptr.at(i,j)=i+j;
			
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j)
			cout<<pptr.at(i,j)<<'\t';		
	
	cout<<'\n';
	return 0;
}



