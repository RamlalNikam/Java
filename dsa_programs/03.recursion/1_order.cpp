#include <iostream>
using namespace std;
//Head Recursion
void count(int n)
{
    //base case
    if(n==0)
        return;
    //Recursive relation
    count(n-1);
    //processing
    cout<<n<<" ";
}
//Tail Recursion
void count1(int n)
{
    //base case
    if(n==0)
        return;
    //processing
    cout<<n<<" ";
    //Recursive relation
    count1(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<endl<<"In Ascending Order: "<<endl;
    count(n);
    cout<<endl<<"In Descending Order: "<<endl;
    count1(n);
}