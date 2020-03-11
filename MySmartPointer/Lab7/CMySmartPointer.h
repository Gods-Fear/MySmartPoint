#include<iostream>
#include<string>

using namespace std;

class CRefCounter
{
public:
	CRefCounter() { i_count; }
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); }
	int iGet() { return(i_count); }
private:
	int i_count  = 0;
};

////////////////////////////////////////

template <typename T>
class CMySmartPointer
{
private:
	T *pc_pointer;
	CRefCounter *pc_counter;
	bool b_is_array;

public:
	CMySmartPointer( T *pcPointer , bool b_is_array); 
	CMySmartPointer(const CMySmartPointer &pcOther);
	~CMySmartPointer();

	T& operator*();
	T* operator->();
	void  operator= ( const CMySmartPointer &pcOtherPointer);
	void show();
	T At(int iOffset);
};


template <typename T>
CMySmartPointer<T>::CMySmartPointer( T *pcPointer, bool b_New_is_array) 
{
	std::cout << "Constructor CMySmartPointer\n";
	b_is_array = b_New_is_array;
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
}


template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer &pcOther)    
{
	b_is_array = pcOther.b_is_array;
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
	if (pc_counter->iDec() == 0)
	{
		if (b_is_array)
		{
			delete[]pc_pointer;
		}
		else { delete pc_pointer; }
		delete pc_counter;
		std::cout << "Destruktor CMySmartPointer\n";
	}
}

template <typename T>
 T& CMySmartPointer<T>::operator*()
{
	 return(*pc_pointer);
}

 template <typename T>
 T* CMySmartPointer<T>::operator->()
 {
	 return(pc_pointer);
 }


 template <typename T>
 void CMySmartPointer<T>::operator= (const CMySmartPointer &pcOtherPointer)
 {


	 if (pc_pointer != NULL)
	 {

		 if (pc_counter->iDec() == 0)
		 {
			 if (b_is_array)
			 {
				 delete[]pc_pointer;
			 }
			 else { delete pc_pointer; }
			 delete pc_counter;
		 }
		 pc_pointer = pcOtherPointer.pc_pointer;
		 pc_counter = pcOtherPointer.pc_counter;
		 pc_counter->iAdd();

	 }
 }

 template<typename T>
 void CMySmartPointer<T>::show()
 {
	 cout <<"Counter : "<< pc_counter->iGet()<<endl;
 }


//Live 
 ///////////////////////////
 template <typename T>

 T CMySmartPointer<T>::At(int iOffset)
 {
	 if (!b_is_array) throw;
	 return *(pc_pointer + iOffset);
 }
 
 