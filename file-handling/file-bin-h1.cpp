#include <iostream>
#include <fstream>

#include <cstring>

using namespace std;

int id = 0;

struct student{
    int id;
    char name[40];
    int marks;
};

void refresh() {
    ofstream file("data.dat", ios::trunc|ios::binary);
    file.close();
}

void read() {
    student ob1;
    ifstream file("data.dat", ios::in | ios::binary);

    while ( file.read((char*)&ob1, sizeof(ob1)) ) {
        cout << "Id = " << ob1.id << endl;
        cout << "Name = " << ob1.name << endl;
        cout << "Aggregate marks = " << ob1.marks << endl;
    }

    file.close();
}

void search(char name[40]){
    // search for the given name
    student ob1;
    ifstream file("data.dat", ios::in | ios::binary);

    while ( file.read((char*)&ob1, sizeof(ob1)) ) {
        if(strcmp(name, ob1.name)==0) {
            cout << "\nName = " << ob1.name << endl;
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

void insert(student ob2) { // This doesn't work :(
    student ob1;
    fstream file("data.dat", ios::binary);

    int ws = 0;

    while ( file.read((char*)&ob1, sizeof(ob1)) ) {
        if (ob1.id == ob2.id) {
            ws++;
            file.seekg(-sizeof(ob2), ios::cur);
            file.write((char*)&ob2, sizeof(ob2));
        }

        else if (ob1.id > ob2.id && ws) {
            ob1.id++;
            file.write((char*)&ob1, sizeof(ob1));
        }
    }

    file.close();
}

void input() {
    student ob1;
    cout << "Enter the Name :" << endl;
    cin.getline(ob1.name, 40);
    cout << "Enter Aggregate marks :" << endl;
    cin >> ob1.marks;
    ob1.id = ++id;

    append(ob1);
}

void parser(){
    char command[40];

    while ( strcmp(command, "q") ){
        cout << "\n*> ";

        cin.getline(command, 40);

        if (strcmp(command, "new") == 0) {
            input();
            
        }

        else if (strcmp(command, "search") == 0) {
            char query[40];
            cout << "Enter Name to search > ";
            cin.getline(query, 40);
            search(query);
        }

        else if (strcmp(command, "display") == 0) {
            read();
        }

        else if (strcmp(command, "delete") == 0) {
            char confirm;
            cout << "Enter y to confirm > ";
            cin >> confirm;
            if (confirm == 'y') {
                refresh();
            }
        }

    }
}

int main() {

    parser();

    return 0;
}
