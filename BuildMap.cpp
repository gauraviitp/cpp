#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Student{
public:
	int id;
	string name;
	Student() {}
	Student(int pid, string pname): id(pid), name(pname) {}
	Student(const Student& s2) {id = s2.id; name = s2.name; }
};

map<int, Student> buildMap(vector<Student>& students){
	map<int, Student> mapping;
	for (Student student : students){
		mapping[student.id] = student;
	}
	return mapping;
}

vector<Student> createSampleStudents(){
	vector<Student> students;
	students.push_back(Student(2, "Ryan"));
	students.push_back(Student(1, "Ishu"));
	return students;
}

int main(int argc, char **argv){
	vector<Student> v = createSampleStudents();
	map<int, Student> m = buildMap(v);
	for (map<int, Student>::iterator it = m.begin(); it != m.end(); ++it){
		cout << "id: " << it->first << ", name: " << (it->second).name << endl;
	}
}
