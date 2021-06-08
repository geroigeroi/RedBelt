//
//  main.cpp
//  bad_macro
//
//  Created by Andre on 12/01/21.
//
#include <iomanip>
#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl
 



int main() {
    ostringstream output;
    int a=2,b=3;
        if(false)PRINT_VALUES(std::cout, a, b);
        else PRINT_VALUES(std::cout, a, b);
    PRINT_VALUES(output<<std::setw(5), 5, 6);
    //    ostringstream output;
//    if (true) PRINT_VALUES(output, 5, "red belt")
//    else PRINT_VALUES(output, 5, "red belt");
    //int a = 2, b = 3;
    //if(false) PRINT_VALUES(std::cout, a, b);
    
    return 0;
}
