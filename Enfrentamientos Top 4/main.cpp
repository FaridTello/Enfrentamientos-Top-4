#include <iostream>
#include "menus.h"
#include <stdlib.h>
#include "rlutil.h"

using namespace std;

int main(){
    setlocale(LC_ALL,"spanish");
    rlutil::setBackgroundColor(rlutil::YELLOW);
    rlutil::setColor(rlutil::BLACK);
    rlutil::hidecursor();
    menu();
    return 0;
}
