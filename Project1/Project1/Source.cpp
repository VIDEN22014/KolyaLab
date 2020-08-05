#include <iostream>
using namespace std;
class Alpha {
public:
	static int objCount;
	Alpha();
	~Alpha();
};
int Alpha::objCount;
Alpha::Alpha()
{
	if (objCount == 0) cout << "First object has been created" << endl;
	objCount++;
}
Alpha::~Alpha()
{
	objCount--;
	if (objCount == 0) cout << "Last element has been deleted";
}
int main()
{
	Alpha* a;
	a = new Alpha[5];
	delete[] a;
	return 0;
}