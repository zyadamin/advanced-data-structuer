#include <iostream>
#include "BTree.h"

using namespace std;

int main()
{


BTree<int,6>t1;

    t1.Insert(3);
    t1.Insert(7);
    t1.Insert(10);
    t1.Insert(24);
    t1.Insert(14);
    t1.Insert(19);



t1.Print();



    return 0;
}
