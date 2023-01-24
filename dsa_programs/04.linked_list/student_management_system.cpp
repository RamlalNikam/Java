#include<iostream>
using namespace std;
class Student{
public:
    struct record
    {
        int roll_no;
        string s_name;
        string remark;
        string class_name;
        record *r_link;
        record *l_link;
    };
    struct record *header[15],*get_new,*ptr;
    void setHeader(int, string);
    void insertAtHeader();
    void create();
};
void Student::setHeader(int i, string c_name){
    header[i]->r_link=NULL;
    header[i]->l_link=NULL;
    header[i]->class_name=c_name;
}
void Student::create()
{
    cout<<endl<<"\t\tWelcome to student record system"<<endl;
    int choise;
    
}
int main(){

}