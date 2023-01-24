#include <iostream>
#include <string.h>
#include <unistd.h>
#include <fstream>
using namespace std;
class Student
{
public:
    Student *l_link;
    int roll_no;
    string standard;
    string s_name;
    string remark;
    Student *r_link;
    Student(int roll_no, string s_name, string remark)
    {
        l_link = NULL;
        this->roll_no = roll_no;
        this->s_name = s_name;
        this->remark = remark;
        r_link = NULL;
    }

    Student(string standard)
    {
        l_link = NULL;
        this->standard = standard;
        r_link = NULL;
    }
};
void load()
{
    cout << "[";
    for (int i = 112; i > 0; i--)
    {
        cout << "#";
        cout.flush();
        usleep(i * 4900 / 10);
    }
    cout << "]" << endl;
}
/*
--------------------------------------------------------------
                    FUNCTIONS TO INSERT:
--------------------------------------------------------------
*/
// This function will make a node and insert it to the front of the dounle linked list.
void insertDllNodeHead(Student *&header, int x, string s_name, string s_remark)
{
    ofstream fout("note1.txt", ios::app);
    Student *new_node = new Student(x, s_name, s_remark);
    Student *ptr = header->r_link;
    if (header->r_link == NULL)
    {
        header->r_link = new_node;
        new_node->l_link = header;
        new_node->r_link = NULL;
        fout << new_node->s_name << endl
             << new_node->roll_no << endl
             << new_node->remark << endl;
    }
    else
    {
        new_node->r_link = header->r_link;
        header->r_link = new_node;
        new_node->l_link = header;
        ptr->l_link = new_node;
        fout << new_node->s_name << endl
             << new_node->roll_no << endl
             << new_node->remark;
    }
    fout.close();
}
// This function will make a node and insert it to the end of the double linked list.
void insertDllNodeEnd(Student *&header, int x, string s_name, string s_remark)
{
    ofstream fout("note1.txt", ios::app);
    Student *ptr = header;
    while (ptr->r_link != NULL)
        ptr = ptr->r_link;
    Student *new_node = new Student(x, s_name, s_remark);
    ptr->r_link = new_node;
    new_node->l_link = ptr;
    fout << new_node->s_name << endl
         << new_node->roll_no << endl
         << new_node->remark;
    fout.close();
}
// This function will make a node and insert it after the key element of the linked list.
void insertDllNodeAny(Student *&header, string key, int x, string s_name, string s_remark)
{
    ofstream fout("note.txt", ios::app);
    Student *ptr = header->r_link;
    while ((ptr->s_name != key) && (ptr->r_link != NULL))
        ptr = ptr->r_link;
    if (ptr->r_link == NULL)
        cout << endl
             << "Data not found." << endl;
    else
    {
        Student *new_node = new Student(x, s_name, s_remark);
        Student *ptr1;
        ptr1 = ptr->r_link;
        new_node->l_link = ptr;
        new_node->r_link = ptr1;
        ptr->r_link = new_node;
        ptr1->l_link = new_node;
        fout << new_node->s_name << endl
             << new_node->roll_no << endl
             << new_node->remark;
    }
    fout.close();
}
/*
--------------------------------------------------------------
                    FUNCTIONS TO DELETE:
--------------------------------------------------------------
*/
// This function will delete a mode from front.
void deletDllNodeHead(Student *&header)
{
    if (header->r_link == NULL)
        cout << endl
             << "Record Empty: Can't Delet." << endl;
    else
    {
        Student *ptr = header->r_link;
        Student *ptr1 = ptr->r_link;
        header->r_link = ptr1;
        ptr1->l_link = header;
        delete (ptr);
        cout << endl
             << "Student deleted Sucessfully." << endl;
    }
}
// This function will delete a node from end.
void deletDllNodeEnd(Student *&header)
{
    Student *ptr = header->r_link;
    Student *ptr1;
    if (ptr->r_link == NULL)
    {
        cout << endl
             << "Deletion from END not possible. Delete from front" << endl;
    }
    else
    {
        while (ptr->r_link != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->r_link;
        }
        ptr1->r_link = NULL;
        delete (ptr);
        cout << endl
             << "Gecork Sucessfully deleted." << endl;
    }
}
// This function will delete a node of the key element.
int deletDllNodeAny(Student *&header, string key)
{
    Student *ptr = header->r_link;
    Student *ptr1;
    Student *ptr2;
    if (ptr == NULL)
    {
        cout << "Record is empty: No deletion possible";
        return 0;
    }

    while ((ptr->s_name != key) && (ptr->r_link != NULL))
        ptr = ptr->r_link;
    if (ptr->s_name == key)
    {
        ptr1 = ptr->l_link;
        ptr2 = ptr->r_link;
        ptr1->r_link = ptr2;
        if (ptr2 != NULL)
            ptr2->l_link = ptr1;
        delete (ptr);
        cout << endl
             << "Record deleted Sucessfully.";
    }
    else
        cout << endl
             << "The node does not exist in the given list." << endl;
    return 0;
}
void meargDllNode(Student *header, Student *header1)
{
    Student *ptr = header->r_link;
    Student *ptr1 = header1->r_link;
    Student *header2;
    while (ptr->r_link != NULL)
        ptr = ptr->r_link;
    ptr->r_link = header1->r_link;
    header2 = header;
    delete (header1);
}
/*
--------------------------------------------------------------
                    FUNCTIONS TO PRINT:
--------------------------------------------------------------
*/
// This function will print the whole double linked list
void printDllNode(Student *header)
{
    Student *ptr = header->r_link;
    int i = 0;
    cout << " | " << header->standard << " | "
         << "  :  " << endl;
    while (ptr != NULL)
    {
        cout << ++i << ".  | Student Name: " << ptr->s_name << " | " << endl
             << "    | Roll No.: " << ptr->roll_no << " |" << endl
             << "    | Remark: " << ptr->remark << " |" << endl;
        ptr = ptr->r_link;
    }
    cout << "NULL" << endl;
}

// This function will print the whole double linked list from the end(i.e.it will reverse the linked list).
void reverseADll(Student *header)
{
    Student *ptr = header->r_link;
    while (ptr->r_link != 0)
        ptr = ptr->r_link;
    cout << endl
         << endl;
    while (ptr->l_link != NULL)
    {
        cout << "| " << ptr->s_name << " |  ->  ";
        ptr = ptr->l_link;
    }
    cout << "| " << ptr->s_name << " |  ->  NULL" << endl;
}
void student_read(Student *&stand)
{
    fstream fin;
    fin.open("note1.txt", ios::in);
    string stud_name, remark;
    int rollno;
    int i = 0;
    fin.seekg(0, ios::beg);
    while (!fin.eof())
    {
        getline(fin, stud_name);
        fin >> rollno;
        getline(fin, remark);
        if (i == 3)
            break;
        insertDllNodeEnd(stand, rollno, stud_name, remark);
        i++;
    }
    fin.close();
}
/*
--------------------------------------------------------------------------------------------
                    FUNCTIONS TO PERFORM OPERATIONS ON 2 LINKED LIST:
--------------------------------------------------------------------------------------------
*/
// To mearg 2 records into the
Student *meargRecords(Student *&head, Student *head1)
{
    Student *ptr;
    Student *head2;
    ptr = head;
    while (ptr->r_link != NULL)
        ptr = ptr->r_link;
    ptr->r_link = head1->r_link;
    head2 = head;
    delete (head1);
    return head2;
}
// To copy a linked list into the another one.
void upgradeStudent(Student *head, Student *head1)
{
    Student *ptr = head->r_link;
    while (ptr != NULL)
    {
        insertDllNodeEnd(head1, ptr->roll_no, ptr->s_name, ptr->remark);
        ptr = ptr->r_link;
    }
}
// To search a perticular student.
void searchStudent(Student *&head, string key)
{
    Student *ptr = head->r_link;
    while ((ptr->s_name != key) && (ptr != NULL))
    {
        ptr = ptr->r_link;
    }
    if (ptr == NULL)
        cout << endl
             << "----------------------------Student Not Found.----------------------------" << endl;
    else
    {
        cout << "__________________________________________________________________________" << endl;
        cout << endl
             << "Student Name: " << ptr->s_name
             << endl
             << "Roll No.: " << ptr->roll_no
             << endl
             << "Remark: " << ptr->remark;
        cout << endl
             << "__________________________________________________________________________" << endl;
    }
}
int main()
{
    cout << "\t -------   --------  |       |   |---\\     |-----  |\\      |   ---------   -------" << endl;
    cout << "\t |            |      |       |   |    \\    |       | \\     |       |       |" << endl;
    cout << "\t |            |      |       |   |     \\   |       |  \\    |       |       |" << endl;
    cout << "\t -------      |      |       |   |     |   |---    |   \\   |       |       -------" << endl;
    cout << "\t        |     |      |       |   |     /   |       |    \\  |       |              |" << endl;
    cout << "\t        |     |      |       |   |    /    |       |     \\ |       |              |" << endl;
    cout << "\t -------      |      ---------   |---/     |-----  |      \\|       |       -------" << endl;
    cout << "\n\n\t\t        -----    |-----   ------   |-----|    -----    |---\\" << endl;
    cout << "\t\t       |     |   |        |        |     |   |     |   |    \\" << endl;
    cout << "\t\t       |     |   |        |        |     |   |     |   |     \\" << endl;
    cout << "\t\t       |-----    |---     |        |     |   |-----    |     |" << endl;
    cout << "\t\t       | \\       |        |        |     |   | \\       |     /" << endl;
    cout << "\t\t       |  \\      |        |        |     |   |  \\      |    /" << endl;
    cout << "\t\t       |   \\     |-----   ------   |-----|   |   \\     |---/" << endl;
    cout << endl
         << endl
         << "\t\tPress ENTER to contniue.";
    cin.ignore();
    load();
    string header_name;
    cout << "Enter Standered of which you want to store data: ";
    getline(cin, header_name);
    Student *s = new Student(header_name);
    Student *s1;
    Student *stand;
    Student *stand1;
    stand = s;
    string header_name1, header_name2;
    string s_name, s_remark, key;
    int n_nodes, choise, rollno, i = 0;
    while (choise != 20)
    {
    start:
        i = 0;
        cout << endl
             << endl
             << "\t\t\t" << ++i << ".Press '1' to insert from FROUNT."
                                   "\n\n\t\t\t"
             << ++i << ".Press '2' to insert from END.\n\n\t\t\t"

             << ++i << ".Press '3' to insert a student AFTER a perticular Student.\n\n\n\t\t\t"

             << ++i << ".Press '4' to PRINT the record.\n\n\n\t\t\t"

             << ++i << ".Press '5' to DELETE a student(i.e. from BEGNING) from the record.\n\n\t\t\t"

             << ++i << ".Press '6' to DELETE a student(i.e. from END) from the record.\n\n\t\t\t"

             << ++i << ".Press '7' to DELETE a particular student from the records.\n\n\n\t\t\t"

             << ++i << ".Press '8' to Promote " << header_name << " to next standared.\n\n\t\t\t"

             << ++i << ".Press '9' to Search a Perticular Students of Class: " << header_name << ".\n\n\t\t\t"

             << ++i << ".Press '10' to print record of "<<header_name1<<".\n\n\t\t\t"

             << ++i << ".Press 'Ctrl+C or 20' to exit.\n\n\t\t\t";
        cout << "Choise: ";
        cin >> choise;
        switch (choise)
        {
        case 1: // to insert from frount.
            cin.ignore();
            cout << endl
                 << "Enter NAME OF STUDENT: ";
            getline(cin, s_name);
            cout << endl
                 << "Enter ROLL NO. OF STUDENT: ";
            cin >> rollno;
            cin.ignore();
            cout << endl
                 << "Enter REMARK for this STUDENT: ";
            getline(cin, s_remark);
            insertDllNodeHead(stand, rollno, s_name, s_remark);
            cout << endl
                 << "\t\tData Saved sucesfully into the file('note1.txt').";
            system("clear");
            cout << endl
                 << "__________________________________________________________________________________" << endl;
            break;
        case 2: // to insert from end.
            cin.ignore();
            cout << endl
                 << "Enter NAME OF STUDENT: ";
            getline(cin, s_name);
            cout << endl
                 << "Enter ROLL NO. OF STUDENT: ";
            cin >> rollno;
            cin.ignore();
            cout << endl
                 << "Enter REMARK for this STUDENT: ";
            getline(cin, s_remark);
            insertDllNodeEnd(stand, rollno, s_name, s_remark);
            // load();
            cout << endl
                 << "\t\tData Saved sucesfully into the file('note1.txt').";
            system("clear");
            cout << endl
                 << "__________________________________________________________________________________" << endl;
            break;
        case 4: // to print the hole linked list
            system("clear");
            cout << endl
                 << "Records of the stuents: " << endl;
            printDllNode(stand);
            cout << endl
                 << "__________________________________________________________________________________" << endl;
            break;
        case 3: // to insert a record after the key element.
            cin.ignore();
            cout << endl
                 << "Name of student after which you want to insert the record: ";
            getline(cin, key);
            cout << endl
                 << "Enter NAME OF STUDENT: ";
            getline(cin, s_name);
            cout << endl
                 << "Enter ROLL NO. OF STUDENT: ";
            cin >> rollno;
            cin.ignore();
            cout << endl
                 << "Enter REMARK for this STUDENT: ";
            getline(cin, s_remark);
            insertDllNodeAny(stand, key, rollno, s_name, s_remark);
            cout << endl
                 << "__________________________________________________________________________________" << endl;
            break;
        case 5: // to delete a record from front.
            deletDllNodeHead(stand);
            cout << endl
                 << "__________________________________________________________________________________" << endl;
            break;
        case 6: // to delete a record from end.
            deletDllNodeEnd(stand);
            cout << endl
                 << "__________________________________________________________________________________" << endl;
            break;
        case 7: // to delete a perticular element from the record.
            cin.ignore();
            cout << endl
                 << "Enter name of the student which you want to delet: ";
            getline(cin, key);
            deletDllNodeAny(stand, key);
            cout << endl
                 << "__________________________________________________________________________________" << endl;
            break;
        case 8: // to copy a linked list to the another one.
        {

            cin.ignore();
            cout << endl
                 << "Enter Standered in which you want to upgrade: ";
            getline(cin, header_name1);
            s1 = new Student(header_name1);
            stand1 = s1;
            upgradeStudent(stand, stand1);
            cout << endl
                 << "__________________________________________________________________________________" << endl;
        }
        break;
        case 9: // to search a particular student from a record.
            cin.ignore();
            cout << endl
                 << "Enter Student Name to search: ";
            getline(cin, key);
            searchStudent(stand, key);
            cout << endl
                 << "__________________________________________________________________________________" << endl;
            break;
        case 10:
            printDllNode(stand1);
        default:
            cout << endl
                 << "Please Enter a correct choise." << endl;
            cout << endl
                 << "__________________________________________________________________________________" << endl;
            goto start;
        }
    }
}