#include <iostream>

using namespace std;

class String {
protected:
	char* p;
	int size;
public:
	String() {
		clear();
	}
	String(char* string) {
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
	String(const String& obj) {
		delete p;
		size = strlen(obj.p);
		p = new char[size];
		for (int i = 0; i <= size; i++)
		{
			*(p + i) = *(obj.p + i);
		}
	}
	~String() {}

	int putSize() { return size; }
	void clearSize() { size = 0; }
	void clear() {
		p = new char;
		*p = '\0';
		size = 0;
	}
	void Display() { cout << p << endl; }
};

class StringId :public String {
public:
	StringId() { clear(); }
	StringId(char* string) :String(string) {
		if (isNotID())clear();
	}
	StringId(char string) :String(string) {
		if (isNotID())clear();
	}
	StringId(StringId& obj) {
		if (isNotID()) { clear(); }
		else {
			delete p;
			size = strlen(obj.p);
			p = new char[size];
			for (int i = 0; i <= size; i++)
			{
				*(p + i) = *(obj.p + i);
			}
		}
	}
	~StringId() {}
	void Uppercase() {
		for (int i = 0; i < size; i++)
		{
			if (*(p + i) >= 97 && *(p + i) <= 122) *(p + i) -= 32;
		}

	}
	void Lowercase() {
		for (int i = 0; i < size; i++)
		{
			if (*(p + i) >= 65 && *(p + i) <= 90) *(p + i) += 32;
		}
	}
	char* find(char a) {
		for (int i = 0; i < size; i++)
		{
			if (*p == a)return (p + i);
		}
		return nullptr;
	}
	bool isNotID() {
		for (int i = 1; i < size; i++)
		{
			if (*p >= 48 && *p <= 57) { return true; }
			if (*(p + i) < 48 || *(p + i) > 122) { return true; }
			if (*(p + i) > 57 && *(p + i) < 65) { return true; }
			if (*(p + i) > 90 && *(p + i) < 97 && *(p + i) != 95) { return true; }
		}
		return false;
	}
};

int main() {
	char ch[100];
	cin >> ch;
	StringId a(ch);
	StringId b(a);
	StringId c;
	b.Lowercase();
	b.Display();
	b.Uppercase();
	b.Display();
	c.Display();
	return 0;
}