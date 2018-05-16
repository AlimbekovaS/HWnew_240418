#include"vector.h"
#include"library.h"
int main()
{

	Vector V, V2;
	V.push_back(10);
	V.push_back(46);
	V.push_back(50);
	V.push_back(90);
	V.push_back(100);
	V2.push_back(6);
	V2.push_back(46);
	V2.push_back(96);
	V2.push_back(90);
	V2.push_back(55);
	/*V + V2;
	V.print();*/
	
	cout << endl;
	V - V2;
	V.print();
	
	system("pause");
	return 0;
}