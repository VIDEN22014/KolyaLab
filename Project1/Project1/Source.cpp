#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class University {
public:
	class Faculty {
	public:
		struct Data
		{
			string faculty_name;
			string decan_prizv;
			int group_count;
			vector<int> group;

		}data;

		Faculty* next;
		Faculty(Data a, Faculty* p = nullptr) { data = a; next = p; };

		void add_group(int a) {
			this->data.group.push_back(a);
			this->data.group_count++;
		}
		void del_group() {
			this->data.group.pop_back();
			this->data.group_count--;
		}
		void calc_stud() {
			int stud_count = 0;
			for (int i = 0; i < data.group_count; i++)
			{
				stud_count += data.group[i];
			}
			cout << stud_count << " Students on this faculty" << endl;
		}

	};
	Faculty* head;

	University() { head = nullptr; }
	~University() {}
	Faculty* operator[](int a) {
		int count = 0;
		Faculty* temp = head;
		while (temp != nullptr) {
			if (count == a) { return temp; }
			temp = temp->next;
			count++;
		}
	}
	void add_faculty(Faculty::Data a) {
		if (head == nullptr)
		{
			head = new Faculty(a);
		}
		else {
			Faculty* temp = this->head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new Faculty(a);
		}
	}
	void del_faculty() {
		Faculty* temp = head;
		while (temp != nullptr)
		{
			if (temp->next == nullptr) {
				head = nullptr;

			}
			else if (temp->next->next == nullptr) {
				temp->next = nullptr;
			}
			temp = temp->next;
		}
	}
};
ostream& operator<<(ostream& stream, const University& obj) {
	University::Faculty* temp = obj.head;
	while (temp != nullptr) {
		stream << "Faculty name : "<<temp->data.faculty_name<<endl;
		stream << "Dekan prizv : "<<temp->data.decan_prizv<<endl;
		stream << "Group count : "<<temp->data.group_count<<endl;
		stream << "Student count : ";
		for (int i = 0; i < temp->data.group_count ; i++)
		{
			stream << temp->data.group[i]<<" ";
		}
		stream << endl;
		temp = temp->next;
	}
	stream << endl;
	return stream;
}
istream& operator>>(istream& stream, University& obj) {
	while (obj.head!=nullptr) {
		obj.del_faculty();
	}
	int faculty_count;
	cout << "Enter count of faculty : "<<endl;
	stream >> faculty_count;
	for (int i = 0; i < faculty_count; i++)
	{
		University::Faculty::Data str;
		cout << "Enter faculty name : " << endl;
		stream >> str.faculty_name;
		cout << "Enter dekan prizv : " << endl;
		stream >> str.decan_prizv;
		cout << "Enter group count : " << endl;
		stream >> str.group_count;
		cout << "Enter students count : " << endl;
		for (int i = 0; i < str.group_count; i++)
		{
			int temp_group;
			stream >> temp_group;
			str.group.push_back(temp_group);
		}
		obj.add_faculty(str);
	}
	return stream;
}

ofstream& operator<<(ofstream& stream, const University& obj) {
	University::Faculty* temp = obj.head;
	while (temp != nullptr) {
		stream << "Faculty name : " << temp->data.faculty_name << endl;
		stream << "Dekan prizv : " << temp->data.decan_prizv << endl;
		stream << "Group count : " << temp->data.group_count << endl;
		stream << "Student count : ";
		for (int i = 0; i < temp->data.group_count; i++)
		{
			stream << temp->data.group[i] << " ";
		}
		stream << endl;
		temp = temp->next;
	}
	return stream;
}

ifstream& operator>>(ifstream& stream, University& obj) {
	while (obj.head != nullptr) {
		obj.del_faculty();
	}
	int faculty_count;
	stream >> faculty_count;
	for (int i = 0; i < faculty_count; i++)
	{
		University::Faculty::Data str;
		stream >> str.faculty_name;
		stream >> str.decan_prizv;
		stream >> str.group_count;
		for (int i = 0; i < str.group_count; i++)
		{
			int temp_group;
			stream >> temp_group;
			str.group.push_back(temp_group);
		}
		obj.add_faculty(str);
	}
	return stream;
}



int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	University::Faculty::Data b;
	b.decan_prizv = "Pilipiv";
	b.faculty_name = "MIF";
	b.group_count = 2;
	b.group.push_back(40);
	b.group.push_back(15);

	University a;
	a.add_faculty(b);
	b.faculty_name = "FIM";
	b.group[0] = 0;
	a.add_faculty(b);


	a[0]->calc_stud();
	a[0]->del_group();
	a[0]->calc_stud();
	a[0]->add_group(32);
	a[0]->calc_stud();
	a[1]->calc_stud();
	cout << a;
	cout << a;
	out << a;
	in >> a;
	cout << a;
	return 0;
}
