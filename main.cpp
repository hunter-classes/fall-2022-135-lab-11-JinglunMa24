#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

int main() {
    Profile profile1("Jayden", "PhonismNM");
    std::cout << profile1.getFullName() << '\n';

    Network nw;
    std::cout << nw.addUser("Jack", "Jackson") << '\n';

    Network nw2;
    nw2.addUser("one", "ONE");
    nw2.addUser("two", "TWO");
    nw2.addUser("three", "THREE");

    nw2.follow("one", "two");
    nw2.follow("one", "three");
    nw2.follow("two", "one");
    nw2.follow("two", "three");
    nw2.follow("three", "one");
    nw2.follow("three", "two");

    nw2.addUser("four", "FOUR");

    // add users that follow @one
    for (int i = 2; i < 6; i++) {
        std::string usrn = "one" + std::to_string(i);
        std::string dspn = "ONE" + std::to_string(i);
        nw2.addUser(usrn, dspn);
        nw2.follow(usrn, "one");
    }

    nw2.follow("one2", "two");

    nw2.printDot();

    return 0;
}