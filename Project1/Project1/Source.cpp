#include <iostream>
#include <conio.h>
using namespace std;
class Alpha {
public:
	static int n;
	Alpha();
	~Alpha();
};
int Alpha::n = 0;
Alpha::Alpha()
{
		if (n == 0) cout << "First object has been created" << endl;
	n++;
}
Alpha::~Alpha()
{
	n--;
	if (n == 0) cout << "Last element has been deleted";
}
int main()
{
	Alpha* a;
	a = new Alpha[5];
	delete[] a;
	return 0;
}