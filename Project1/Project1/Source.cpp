#include <iostream>

using namespace std;

class String {
public:
	char* p=nullptr;
	int size=0;
	String() {}
	String(char *string) {
		p = new char[strlen(string)];
		size = strlen(string);
		for (int i = 0; i <= size; i++)
		{
			*(p + i) = *(string + i);
		}
	}
	String(char string) {
		p = new char;
		size = 1;
		*p = string;
		*(p + 1) = '\0';
	}
	int putSize() { return size; }
	void clearSize() { size = 0;}
	void clear() {
	p = new char;
	*p = '\0';
	}

};

int main() {
	char ch;
	cin >> ch;
	String a(ch);
	cout << a.p<<endl;
	a.clear();
	cout << a.p<<endl;
	return 0;
}