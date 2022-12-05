#include <iostream>
#include <string>
#include "profile.h"

int main() {
    Profile profile1("Jayden", "PhonismNM");
    std::cout << profile1.getFullName() << '\n';


    return 0;
}