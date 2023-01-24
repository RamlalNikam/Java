#include <iostream>
#include <iomanip>
#include <string.h>
#include <unistd.h>
#include <fstream>
using namespace std;
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
class Student
{
public:
    int no_records;
    struct node
    {
        // Student Details.
        int roll_no;
        string s_name, remark, standared;
        // Pointers to point the next node.
        struct node *l_link;
        struct node *r_link;
    };
    struct node *header[12], *ptr, *get_new, *ptr1, *ptr2;
    Student();
    void setHeader(int);
    void create();
    void setHeader(int, string);
    // to insert:
    void insertFront(int);
    void insertEnd(int);
    // void insertEndCopy(int, string, int, string);
    void insertAny(int, string);
    // to delete:
    void deletFront(int);
    void deletEnd(int);
    void deletAny(int, string);
    // to display:
    void printRecordBook(int);
    void reverseDll();
    // to perform operations on 2 records:
    void merg(int, int, int);
    void copy(int, int, string);
    void search(int, string);
};
Student::Student()
{
    cout << endl
         << "\t\t-------------------------JAIPURIA VIDHYALAYA-------------------------" << endl
         << endl;
    cout << "\t -------   -------   |       |   |---\\     |-----  |\\      |   ---------   -------" << endl;
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
}
void Student::setHeader(int no_header, string header_name)
{
    header[no_header] = new node;
    header[no_header]->l_link = NULL;
    header[no_header]->standared = header_name;
    header[no_header]->r_link = NULL;
}
void Student::create()
{
    no_records = 0;
    int choise, choise1, choise2, choise3;
    int s_no, mearg_rec1, mearg_rec2, cpy_rec1;
    string header_name, key, header_name1;
    while (choise != 20)
    {
    goback1:
        cout << endl
             << "Enter your choise from these:" << endl;
        cout << "\n\t\tPress '1' to Create a new Record Book of a Class and Section."
             << "\n\n\t\tPress '2' to Edit Existing record."
             << "\n\n\t\tPress '3' to See all your records"
             << "\n\n\t\tPress 'Ctrl + C or 20' to EXIT";
        cout << endl
             << "Choise: ";
        cin >> choise;
        cout << endl
             << "__________________________________________________________________________________" << endl;
        switch (choise)
        {
        case 1:
            cin.ignore();
            cout << endl
                 << endl
                 << "Enter standerd of Record Book: ";
            getline(cin, header_name);
            setHeader(no_records, header_name);
        goback2:
            cout << endl
                 << endl
                 << "Enter Your Choise:"
                    "\n\n\t\tPress '1' to INSERT a Record from FRONT."
                    "\n\n\t\tPress '2' to INSERT a Record from END."
                    "\n\n\t\tPress '3' to INSERT a Record AFTER a PARTICULAR STUDENT."
                    "\n\n\t\tPress '4' to DELETE a Record from FRONT."
                    "\n\n\t\tPress '5' to DELETE a Record from END."
                    "\n\n\t\tPress '6' to DELETE a Record of a PARTICULAR STUDENT."
                    "\n\n\t\tPress '7' to PRINT all Records."
                    "\n\n\t\tPress '8' to GO BACK";
            cout << endl
                 << "Choise: ";
            cin >> choise1;

            switch (choise1)
            {
            case 1: // to insert a record from frount.
                insertFront(no_records);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback2;
            case 2: // to insert a record from end.
                insertEnd(no_records);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback2;
            case 3: // to insert a record after a perticular student.
                cin.ignore();
                cout << endl
                     << "Name of student after which you want to insert the record: ";
                getline(cin, key);
                insertAny(no_records, key);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback2;
            case 4: // to delet a record from front.
                deletFront(no_records);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback2;
            case 5: // to delet a record from end.
                deletEnd(no_records);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback2;
            case 6: // to delet a perticular record.
                cin.ignore();
                cout << endl
                     << "Enter NAME of student which you want to delete: ";
                getline(cin, key);
                deletAny(no_records, key);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback2;
            case 7: // to print the hole record book.
                printRecordBook(no_records);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback2;
            case 8:
                no_records++;
                system("clear");
                goto goback1;
            }
            break;
        case 2:
        goback3:
            cout << endl
                 << endl
                 << "All Record Books of JAIPURIA VIDHYALAYA are: ";
            cout << endl
                 << "\t\tS.No.    Records";
            cout << endl
                 << "\t\t--------------------------" << endl;
            for (int i = 0; i < no_records; i++)
            {
                cout << endl
                     << "\t\t" << i + 1 << setw(3) << ".   |   " << header[i]->standared;
            }
            cout << endl
                 << endl
                 << "Enter '55' to goback." << endl;
            cout << endl
                 << "Enter S.No. of the record to edit them: ";
            cin >> s_no;
            system("clear");
            if (s_no == 55)
                goto goback1;
        goback4:
            cout << endl
                 << endl
                 << "Enter Your Choise:"
                    "\n\n\t\tPress '1' to INSERT a Record from FRONT."
                    "\n\n\t\tPress '2' to INSERT a Record from END."
                    "\n\n\t\tPress '3' to INSERT a Record AFTER a PARTICULAR STUDENT."
                    "\n\n\t\tPress '4' to DELETE a Record from FRONT."
                    "\n\n\t\tPress '5' to DELETE a Record from END."
                    "\n\n\t\tPress '6' to DELETE a Record of a PARTICULAR STUDENT."
                    "\n\n\t\tPress '7' to PRINT all Records."
                    "\n\n\t\tPress '8' to SEARCH a PARTICULAR STUDENT."
                    "\n\n\t\tPress '9' to GO BACK";
            cout << endl
                 << "Choise: ";
            cin >> choise2;

            switch (choise2)
            {
            case 1: // to insert a record from frount.
                insertFront(s_no - 1);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback4;
            case 2: // to insert a record from end.
                insertEnd(s_no - 1);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback4;
            case 3: // to insert a record after a perticular student.
                cin.ignore();
                cout << endl
                     << "Name of student after which you want to insert the record: ";
                getline(cin, key);
                insertAny(s_no - 1, key);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback4;
            case 4: // to delet a record from front.
                deletFront(s_no - 1);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback4;
            case 5: // to delet a record from end.
                deletEnd(s_no - 1);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback4;
            case 6: // to delet a perticular record.
                cin.ignore();
                cout << endl
                     << "Enter NAME of student which you want to delete: ";
                getline(cin, key);
                deletAny(s_no - 1, key);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback4;
            case 7: // to print the hole record book.
                printRecordBook(s_no - 1);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback4;
            case 8: // to search a perticular student.
                cin.ignore();
                cout << endl
                     << "Enter Name of the Student to get details of it: ";
                getline(cin, key);
                search(s_no - 1, key);
                cout << endl
                     << "__________________________________________________________________________________" << endl;
                goto goback4;
            case 9:
                // no_records++;
                system("clear");
                goto goback3;
            default:
                cout << endl
                     << "\t\tEntered wrong choise: Please enter correct choise." << endl;
                goto goback4;
            }
            goto goback1;
        case 3:
        goback5:
            cout << endl
                 << endl
                 << "All Record Books of JAIPURIA VIDHYALAYA are: ";
            cout << endl
                 << "\t\tS.No.       Records";
            cout << endl
                 << "\t\t--------------------------" << endl;
            for (int i = 0; i < no_records; i++)
            {
                cout << endl
                     << "\t\t  " << i + 1 << setw(3) << ".   |   " << header[i]->standared;
            }
            cout << endl
                 << "Enter your choise:" << endl;
            cout << endl
                 << "\n\t\tPress '1' to MEARG a Record Book into the another one."
                 << endl
                 << "\n\t\tPress '2' to Copy a Record Book into a new(and empty) Record Book."
                 << endl
                 << "\n\t\tPress '3' to Go Back.\nChoise:";
            cin >> choise3;
            switch (choise3)
            {
            case 1:
                cout << "\n\tEnter 'S.No.' of Record Book in which you have to mearg: ";
                cin >> mearg_rec1;
                cout << "\n\tEnter 'S.No.' of Record Book which will be mearged: ";
                cin >> mearg_rec2;
                // cin.ignore();
                // cout << endl
                //      << "Enter Name for the Record Book: ";
                // getline(cin, header_name1);
                // setHeader(no_records, header_name1);
                merg(mearg_rec1 - 1, mearg_rec2 - 1, no_records);
                // no_records++;
                system("clear");
                goto goback5;
            case 2:
                cout << endl
                     << "Enter 'S.No.' of the record which you want to copy into the another: ";
                cin >> cpy_rec1;
                cin.ignore();
                cout << endl
                     << "Enter standered of the Record Book: ";
                getline(cin, header_name1);
                copy(cpy_rec1 - 1, no_records, header_name1);
                no_records++;

                goto goback5;
            case 3:
                system("clear");
                goto goback1;
            default:
                cout << endl
                     << "\t\tEntered Wrong Choise: Please Enter a correct choise." << endl;
                goto goback5;
            }
            goto goback5;
        case 20:
            break;
        default:
            cout << endl
                 << "\t\tEntered Wrong Choise: Please Enter a correct choise." << endl;
            goto goback1;
            break;
        }
    }
}
/*
--------------------------------------------------------------
                    FUNCTIONS TO INSERT:
--------------------------------------------------------------
*/
void Student::insertFront(int i)
{
    ptr = header[i]->r_link;
    get_new = new node;
    if (get_new == NULL)
    {
        cout << endl
             << "Insufficient Memory." << endl;
        return;
    }
    cin.ignore();
    cout << endl
         << "Student Name: ";
    getline(cin, get_new->s_name);
    cout << endl
         << "Roll No.: ";
    cin >> get_new->roll_no;
    cin.ignore();
    cout << endl
         << "Remark: ";
    getline(cin, get_new->remark);
    if (header[i]->r_link == NULL)
    {
        get_new->l_link = header[i];
        get_new->r_link = header[i]->r_link;
        header[i]->r_link = get_new;
        system("clear");
        cout << "\n\t------------------------------------------------------------------\n"
                "\t\t\tSTUDENT INSERTED SUCESSFULLY"
                "\n\t------------------------------------------------------------------\n";
    }
    else
    {
        get_new->l_link = header[i];
        header[i]->r_link = get_new;
        get_new->r_link = ptr;
        ptr->l_link = get_new;
        system("clear");
        cout << "\n\t------------------------------------------------------------------\n"
                "\t\t\tSTUDENT INSERTED SUCESSFULLY"
                "\n\t------------------------------------------------------------------\n";
    }
}
void Student::insertEnd(int i)
{
    ptr = header[i];
    get_new = new node;
    if (get_new == NULL)
    {
        cout << endl
             << "Insufficient Memory." << endl;
        return;
    }
    cin.ignore();
    cout << endl
         << "Student Name: ";
    getline(cin, get_new->s_name);
    cout << endl
         << "Roll No.: ";
    cin >> get_new->roll_no;
    cin.ignore();
    cout << endl
         << "Remark: ";
    getline(cin, get_new->remark);
    while (ptr->r_link != NULL)
    {
        ptr = ptr->r_link;
    }
    get_new->l_link = ptr;
    ptr->r_link = get_new;
    get_new->r_link = NULL;
    system("clear");
    cout << "\n\t------------------------------------------------------------------\n"
            "\t\t\tSTUDENT INSERTED SUCESSFULLY"
            "\n\t------------------------------------------------------------------\n";
}
void Student::insertAny(int n, string key)
{
    ptr = header[n]->r_link;
    get_new = new node;
    while ((ptr->s_name != key) && (ptr != NULL))
        ptr = ptr->r_link;
    // system("clear");
    if (ptr == NULL)
        cout << endl
             << "---------------STUDENT NOT FOUND : INSERTION NOT POSSIBLE---------------" << endl;
    else
    {
        cin.ignore();
        cout << endl
             << "Student Name: ";
        getline(cin, get_new->s_name);
        cout << endl
             << "Roll No.: ";
        cin >> get_new->roll_no;
        cin.ignore();
        cout << endl
             << "Remark: ";
        getline(cin, get_new->remark);
        if (ptr->r_link == NULL)
        {
            get_new->l_link = ptr;
            ptr->r_link = get_new;
            get_new->r_link = NULL;
        }
        else
        {
            ptr1 = ptr->r_link;
            get_new->l_link = ptr;
            get_new->r_link = ptr1;
            ptr->r_link = get_new;
            ptr1->l_link = get_new;
        }
        system("clear");
        cout << "\n\t------------------------------------------------------------------\n"
                "\t\t\tSTUDENT INSERTED SUCESSFULLY"
                "\n\t------------------------------------------------------------------\n";
    }
}
/*
--------------------------------------------------------------
                    FUNCTIONS TO DELETE:
--------------------------------------------------------------
*/
void Student::deletFront(int n)
{
    ptr = header[n]->r_link;
    ptr1 = ptr->r_link;
    system("clear");
    if (header[n]->r_link == NULL)
        cout << endl
             << "\t----------DELETION NOT POSSIBLE: RECORD BOOK IS EMPTY----------" << endl;
    else
    {
        header[n]->r_link = ptr1;
        ptr1->l_link = header[n];
        delete (ptr);
        cout << "\n\t------------------------------------------------------------------\n"
                "\t\t\tSTUDENT DELETED SUCESSFULLY"
                "\n\t------------------------------------------------------------------\n";
    }
}
void Student::deletEnd(int n)
{
    ptr = header[n]->r_link;
    system("clear");
    if (header[n]->r_link == NULL)
        cout << endl
             << "\t----------DELETION NOT POSSIBLE: RECORD BOOK IS EMPTY----------" << endl;
    else
    {
        while (ptr->r_link != NULL)
            ptr = ptr->r_link;
        ptr1 = ptr->l_link;
        ptr1->r_link = NULL;
        delete (ptr);
        cout << "\n\t------------------------------------------------------------------\n"
                "\t\t\tSTUDENT DELETED SUCESSFULLY"
                "\n\t------------------------------------------------------------------\n";
    }
}
void Student::deletAny(int n, string key)
{
    ptr = header[n]->r_link;
    if (ptr == NULL)
        cout << endl
             << "---------------LIST IS EMPTY: NO DELETION MADE---------------" << endl;
    else
    {
        while ((ptr->s_name != key) && (ptr->r_link != NULL))
            ptr = ptr->r_link;
        if (ptr->s_name == key)
        {
            ptr1 = ptr->l_link;
            ptr2 = ptr->r_link;
            ptr1->r_link = ptr2;
            if (ptr2 != NULL)
            {
                ptr2->l_link = ptr1;
                delete (ptr);
            }
            system("clear");
            cout << "\n\t------------------------------------------------------------------\n"
                    "\t\t\tSTUDENT DELETED SUCESSFULLY"
                    "\n\t------------------------------------------------------------------\n";
        }
        else
            cout << endl
                 << "----------Student does not exist in the given record book----------" << endl;
    }
}
/*
------------------------------------------------------------------------------------
                        FUNCTIONS TO PRINT:
------------------------------------------------------------------------------------
*/
void Student::printRecordBook(int n)
{
    system("clear");
    ptr = header[n]->r_link;
    cout << endl
         << "\t| " << header[n]->standared << " |" << endl;
    cout << "------------------------------------------------------------" << endl;
    while (ptr != NULL)
    {
        cout << endl
             << "| Student Name: " << ptr->s_name << " |" << endl
             << "| Roll No.: " << ptr->roll_no << " |" << endl
             << "| Remark: " << ptr->remark << " |" << endl;
        ptr = ptr->r_link;
    }
}
/*
---------------------------------------------------------------------------------------
                FUNCTIONS TO PERFORM OPERATIONS ON 2 LINKED LIST:
---------------------------------------------------------------------------------------
*/
void Student::merg(int n1, int n2, int n3)
{
    ptr = header[n1]->r_link;
    ptr1 = header[n2]->r_link;
    while (ptr->r_link != NULL)
        ptr = ptr->r_link;
    ptr->r_link = header[n2]->r_link;
    ptr1->l_link = ptr;
    // header[n3] = temp;
    cout << endl
         << "\t---------------RECORDS MEARGED SUCESSFULLY---------------" << endl;
}
void Student::copy(int n, int rec_no, string header_name)
{
    ptr = header[n]->r_link;
    setHeader(no_records, header_name);
    ptr1 = header[no_records];
    no_records++;
    while (ptr != NULL)
    {
        get_new = new node;
        get_new->s_name = ptr->s_name;
        get_new->roll_no = ptr->roll_no;
        get_new->remark = ptr->remark;
        ptr1->r_link = get_new;
        get_new->l_link = ptr1;
        get_new->r_link = NULL;
        ptr1 = get_new;
        ptr = ptr->r_link;
    }
    system("clear");
    cout << endl
         << "---------------RECORD COPIED SUCESSFULLY---------------" << endl
         << endl;
}
void Student::search(int n, string key)
{
    ptr = header[n]->r_link;
    while ((ptr->s_name != key) && (ptr != NULL))
        ptr = ptr->r_link;
    if (ptr == NULL)
    {
        cout << endl
             << "\t---------------STUDENT NOT FOUND---------------" << endl
             << endl;
    }
    else
    {
        if (ptr->s_name == key)
            cout << endl
                 << "| Student Name: " << ptr->s_name << " |" << endl
                 << "| Roll No.: " << ptr->roll_no << " |" << endl
                 << "| Remark: " << ptr->remark << " |" << endl;
        else
            cout << endl
                 << "\t---------------STUDENT NOT FOUND---------------" << endl
                 << endl;
    }
}
int main()
{
    Student s;
    s.create();
    return 0;
}