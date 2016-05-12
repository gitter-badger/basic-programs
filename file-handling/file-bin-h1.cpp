#include <iostream>
#include <fstream>

#include <string>

using namespace std;

int id = 0;

struct student{
    int id;
    int marks;
    string name;
};

void read() {
    student ob1;
    ifstream file("data.dat", ios::in | ios::binary);

    while ( file.read((char*)&ob1, sizeof(ob1)) ) {
        cout << "Name = " << ob1.name << endl;
        cout << "Id = " << ob1.id << endl;
        cout << "Aggregate marks = " << ob1.marks << endl;
    }

    file.close();
}

void search(string name){
    student ob1;
    ifstream file("data.dat", ios::in | ios::binary);

    while ( file.read((char*)&ob1, sizeof(ob1)) ) {
        if(name == ob1.name) {
            cout << "Name = " << ob1.name << endl;
            cout << "Id = " << ob1.id << endl;
            cout << "Aggregate marks = " << ob1.marks << endl;
        }
    }

    file.close();
}

void append(student ob) {
    ofstream file ("data.dat", ios::out|ios::app);
    file.write((char*)&ob, sizeof(ob));
    file.close();
}

void insert(student ob2) {
    student ob1;
    ifstream file("data.dat", ios::in | ios::binary);
    ofstream temp("temp.dat", ios::out | ios::binary);

    while ( file.read((char*)&ob1, sizeof(ob1)) ) {
        if (ob1.id < ob2.id) {
            temp.write((char*)&ob1, sizeof(ob1));
        }

        else if (ob1.id == ob2.id) {
            temp.write((char*)&ob2, sizeof(ob2));
        }

        else {
            ob1.id++;
            temp.write((char*)&ob1, sizeof(ob1));
        }
    }

    file.close();
    temp.close();

    remove("data.dat");
    rename("temp.dat", "data.dat");
}

void input() {
    student ob1;
    cout << "Enter the Name" << endl;
    getline(cin, ob1.name);
    cout << "Enter Aggregate marks" << endl;
    cin >> ob1.marks;
    ob1.id = ++id;

    append(ob1);
}

int main() {

    input();

    read();

    return 0;
}
