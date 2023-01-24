#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;
int main()
{
    
    DllNode *n1 = new DllNode[3];
   
    DllNode *header ;
    n1=header;
    insertDllNodeHeadInt(header, 89);
    insertDllNodeHeadInt(header, 90);
    insertDllNodeHeadInt(header, 91);
    insertDllNodeEndInt(header, 88);
    insertDllNodeEndInt(header, 86);
    insertDllNodeEndInt(header, 87);
    insertDllNodeAnyInt(header, 89, 55);
    // deletDllNodeHeadInt(header);
    // deletDllNodeEndInt(header);
    deletDllNodeAnyInt(header, 999);
    printDllNodeInt(header);
    reverseADll(header);
}