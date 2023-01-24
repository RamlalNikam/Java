#include <iostream>
// #include <conio.h>
using namespace std;
class vector
{
    public:
     int *a,loc,top,fl,el,N;
     int upStack[10],lowStack[10];

     vector();
     void getdata();
     void putdata();
     void push(int,int);
     void pop();
     int divide(int, int);
     void swap(int, int);
     void quickSort();
};
vector::vector()
{
     top=-1;
}
void vector::getdata()
{
     cout<<"Enter the size of Array: ";
     cin>>N;
     a=new int[N];
     cout<<"Enter the elements: ";
     for(int i=0;i<N;i++)
     {
	 cin>>a[i];
     }
}
void vector::putdata()
{
     for(int i=0;i<N;i++)
     {
	 cout<<a[i]<<" ";
     }
}
void vector::push(int a,int b)
{
     top+=1;
     lowStack[top]=a;
     upStack[top]=b;
}
void vector::pop()
{
     fl=lowStack[top];
     el=upStack[top];
     top-=1;
}
void vector::swap(int p1,int p2)
{
     int temp;
     temp=a[p1];
     a[p1]=a[p2];
     a[p2]=temp;
}
int vector::divide(int lft, int rgt)
{
     loc=lft;
     while(1)
     {
	 while(loc!=rgt && a[loc]<=a[rgt])
	 {
	     rgt=rgt-1;
	 }
	 if(loc==rgt)
	     return loc;
	 else
	 {
	     swap(loc,rgt);
	     lft=loc+1;
	     loc=rgt;
	 }
	 while(loc!=lft && a[loc]>=a[lft])
	 {
	     lft=lft+1;
	 }
	 if(loc==lft)
	     return loc;
	 else
	 {
	     swap(loc,lft);
	     rgt=loc-1;
	     loc=lft;
	 }
     }
}
void vector::quickSort()
{
     fl=0,el=N-1;
     if(N-1>0)
	 push(fl,el);
     while(top!=-1)
     {
	 pop();
	 loc=divide(fl,el);
	 if(fl<=loc-1)
	      push(fl,loc-1);
	 if(el>=loc+1)
	      push(loc+1,el);
     }
}
int main()
{
     vector v;
     
     v.getdata();
     cout<<"\nArray before Sorting: ";
     v.putdata();
     v.quickSort();
     cout<<"\n\nArray after Sorting: ";
     v.putdata();

     return 0;
}