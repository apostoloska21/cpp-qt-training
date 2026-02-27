#include <iostream>
using std::cout; using std::endl;
#include "cpp/time.h"

int main() {
    Time t1;
    Time t2(2);
    Time t3(21, 34);

    t1.printMilitary(); cout << endl;
    t2.printMilitary(); cout << endl;
    t3.printStandard(); cout << endl;
}
