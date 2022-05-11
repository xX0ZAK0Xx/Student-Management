#include <iostream>
#include <vector>

using namespace std;

class Student
{
private:
    int stid;
    string name;
    float marks[3];
    static string subjects[3];
    string grades;

public:
    static int totalStudent;
    int getId();
    void setData();
    void getData(char a);
    void calculate();
};
string Student::subjects[3] = {"Math   ", "English", "Science"};
int Student::totalStudent;

int Student::getId()
{
    return stid;
}
void Student::setData()
{
    cout << "Enter name : ";
    getline(cin, name);
    cout << "Enter ID   : ";
    cin >> stid;
    cout << "Enter marks\n";
    for (int i = 0; i < 3; i++)
    {
    enterAgain:
        cout << subjects[i] << " : ";
        cin >> marks[i];
        if (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks. Please enter again\n";
            goto enterAgain;
        }
    }
    cin.ignore();
    calculate();
}

void Student::getData(char a)
{
    cout << "Name  : " << name << endl;
    cout << "ID    : " << stid << endl;
    if (a == '2')
        for (int i = 0; i < 3; i++)
        {
            cout << subjects[i] << " : " << marks[i] << endl;
        }
    cout << "Grade : " << grades << endl;
    if (a == '4')
        cout << "\n";
}

void Student::calculate()
{
    float av;
    for (int i = 0; i < 3; i++)
        av += marks[i];
    av /= 3;

    if (av >= 80)
        grades = "A+";
    else if (av >= 75)
        grades = "A";
    else if (av >= 70)
        grades = "A-";
    else if (av >= 65)
        grades = "B+";
    else if (av >= 60)
        grades = "B";
    else if (av >= 55)
        grades = "B-";
    else if (av >= 50)
        grades = "C+";
    else if (av >= 45)
        grades = "C";
    else if (av >= 40)
        grades = "D";
    else if (av < 40)
        grades = "F";
}

void menu()
{
    system("cls");
    cout << "1. Enter student\n";
    cout << "2. Get student's information\n";
    cout << "3. Edit student's information\n";
    cout << "4. Show all students' information\n";
    cout << "5. Exit\n";
}

int main()
{

    vector<Student> stdnt;
    char choice;
    do
    {
        menu();
        cout << "Enter your choice : ";
        cin >> choice;
        cin.ignore();
        system("cls");

        if (choice == '1')
        {
            Student *st = new Student;
            st->setData();
            stdnt.push_back(*st);
            delete st;
            cout << "Press any key to continue..." << endl;
            cin.get();
        }
        else if (choice == '2')
        {

            int id;
            cout << "Enter ID of the student : ";
            cin >> id;
            cin.ignore();

            for (auto i = stdnt.begin(); i != stdnt.end(); i++)
            {
                if (i->getId() == id)
                    i->getData('2');
            }

            cout << "Press ENTER to continue..." << endl;
            cin.get();
        }
        else if (choice == '3')
        {
            int id;
            cout << "Enter ID of the student : ";
            cin >> id;
            cin.ignore();

            for (auto i = stdnt.begin(); i != stdnt.end(); i++)
            {
                if (i->getId() == id)
                    i->setData();
            }

            cout << "Press ENTER to continue..." << endl;
            cin.get();
        }
        else if (choice == '4')
        {
            for (auto i = stdnt.begin(); i != stdnt.end(); i++)
            {
                i->getData('4');
            }

            cout << "Press ENTER to continue..." << endl;
            cin.get();
        }

    } while (choice != '5');

    return 0;
}