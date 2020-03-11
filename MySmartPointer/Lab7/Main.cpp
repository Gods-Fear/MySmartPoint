#include"CMySmartPointer.h"


int main()
{

	
	
	CMySmartPointer<int> cSmartPointer(new int[25] , true);
		*cSmartPointer = 10;	
			cout << *cSmartPointer << endl;
		
	//cSmartPointer.show();

	//CMySmartPointer<int> cSmartPointer2(cSmartPointer);
	////*cSmartPointer2 = 20;
	//cSmartPointer = cSmartPointer2;
	//cout << *cSmartPointer << endl;
	//cSmartPointer.show();

	//CMySmartPointer<int> cSmartPointer3(cSmartPointer2);
	////*cSmartPointer3 = 30;
	//cSmartPointer = cSmartPointer3;
	//cout << *cSmartPointer << endl;

	//cSmartPointer.show();
	

	return 0;
}
