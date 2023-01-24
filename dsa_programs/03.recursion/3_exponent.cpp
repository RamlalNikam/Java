#include<iostream>
using namespace std;
int power (int num, int pow1, int pow2, int ans)
{
    // Base Case
    if(pow1>=pow2)
        return ans;
    ans=ans*num;
    power(num, pow1+1, pow2, ans);
}
int main()
{
    cout<<power(3,1,12,1);
}