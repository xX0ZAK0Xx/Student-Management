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
    int getId();
    void setData(vector<Student> stdnt, char choice);
    void getData(char a);
    void calculate();
};
string Student::subjects[3] = {"Math   ", "English", "Science"};

int Student::getId()
{
    return stid;
}
void Student::setData(vector<Student> stdnt, char choice)
{
    cout << "Enter name : ";
    getline(cin, name);
    // if user choses to edit existing student, he cant change the id
    if (choice == '1')
    {
    idAgain:
        cout << "Enter ID   : ";
        cin >> stid;
        // below lines prevents user from entering same id for multiple students
        for (auto i = stdnt.begin(); i != stdnt.end(); i++)
        {
            if (i->getId() == stid)
            {
                cout << "ID already exists\n";
                goto idAgain;
            }
        }
    }
    cout << "Enter marks\n";
    for (int i = 0; i < 3; i++)
    {
    // below lines prevents user from entering invalid marks
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
    // below lines prevents printing detailed information while
    // user chose to see full list of the students
    if (a == '2')
        for (int i = 0; i < 3; i++)
            cout << subjects[i] << " : " << marks[i] << endl;

    cout << "Grade : " << grades << endl;
    if (a == '5')
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
    cout << "4. Delete student's information\n";
    cout << "5. Show all students' information\n";
    cout << "6. Exit\n";
}

bool searchStudent(vector<Student> &stdnt, char choice)
{
    // as vectors dont pass the address by default
    // we have to grab the address in the parameter(not in the arguement)
    int id;
    cout << "Enter ID of the student : ";
    cin >> id;
    cin.ignore();
    int size = stdnt.size();
    int s = 0;
    for (auto i = stdnt.begin(); i != stdnt.end(); i++, s++)
    {
        if (i->getId() == id)
        {
            if (choice == '2')
                i->getData(choice);
            else if (choice == '3')
            {
                i->setData(stdnt, choice);
                cout << "Student's information updated\n";
            }
            else if (choice == '4')
            {
                stdnt.erase(i);
                cout << "Student's information deleted\n";
            }
            return true;
        }
    }
    return false;
}

int main()
{
    // using vector so that we can add as many students as we want
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
            st->setData(stdnt, choice);
            stdnt.push_back(*st);
            delete st; // we don't need this anymore, otherwise it will be waste of memory
            cout << "Press ENTER to continue..." << endl;
            cin.get();
        }
        else if (choice == '2' || choice == '3' || choice == '4')
        {
            if (!(searchStudent(stdnt, choice)))
                cout << "Student not found\n";
            cout << "Press ENTER to continue..." << endl;
            cin.ignore();
        }
        else if (choice == '5')
        {
            for (auto i = stdnt.begin(); i != stdnt.end(); i++)
                i->getData('5');
            cout << "Press ENTER to continue..." << endl;
            cin.ignore();
        }

    } while (choice != '6');

    return 0;
}