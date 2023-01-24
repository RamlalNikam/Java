#include <iostream>
using namespace std;
class Tower
{
public:
    int static i;
    void move(int n, char org, char init, char des)
    {
        if (n > 0)
        {
            move(n-1,org,des,init);
            cout<<"Step "<<++i<<" : "<<org<<" to "<<des<<endl;
            move(n-1,init,org,des);
        }
    }
};
int Tower::i;
int main(){
    Tower t;
    int disk;
    char a='A',b='B',c='C';
    cout<<"Enter number of disks: ";
    cin>>disk;
    t.move(disk,a,b,c);
    return 0;
}