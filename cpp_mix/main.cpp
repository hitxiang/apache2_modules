#include "animal.h"
#include <iostream>
using namespace std;

int main(int argc, char*argv[])
{
   //    if (argc < 2) exit(EXIT_FAILURE);
    cout << "--- Start ---";
    Animal a(25, 1.83); // 6'0" 25yo (perhaps a human? :P)
    a.setAge(26); // birthday
    cout << "Age: " << a.getAge() << endl << "Height: " << a.getHeight()<< endl;
    exit(EXIT_SUCCESS);
}
