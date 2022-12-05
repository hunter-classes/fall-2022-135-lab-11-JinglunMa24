#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

// Task A
TEST_CASE("Profile class") {
    Profile p1 = Profile("jayden", "JAYDEN");
    Profile p2 = Profile("jack", "JACK");
    CHECK(p1.getUsername() == "jayden");
    CHECK(p1.getFullName() == "JAYDEN (@jayden)");
    p1.setDisplayName("JAYDENTHEBEST");
    CHECK(p1.getFullName() == "JAYDENTHEBEST (@jayden)");
}

TEST_CASE("Network class") {
    // Task B
    Network nw;
    CHECK(nw.addUser("one", "ONE") == true);    // true (1)
    CHECK(nw.addUser("two", "TWO") == true);    // true (1)

    CHECK(nw.addUser("one", "ONE2") == false);      // false (0)
    CHECK(nw.addUser("one 2", "ONE2") == false);    // false (0)
    CHECK(nw.addUser("one-2", "ONE2") == false);    // false (0)

    for (int i = 2; i < 20; i++) {
        CHECK(nw.addUser("one" + std::to_string(i), "ONE" + std::to_string(i)) == true);     // true (1)
    }
    CHECK(nw.addUser("yo", "YO") == false);      // false (0)

    // Task C
    Network nw2;
    CHECK(nw2.addUser("one", "ONE") == true);
    CHECK(nw2.addUser("two", "TWO") == true);
    CHECK(nw2.addUser("three", "THREE") == true);

    CHECK(nw2.follow("one", "two") == true);
    CHECK(nw2.follow("one", "three") == true);
    CHECK(nw2.follow("two", "one") == true);
    CHECK(nw2.follow("two", "three") == true);
    CHECK(nw2.follow("three", "one") == true);
    CHECK(nw2.follow("three", "two") == true);

    CHECK(nw2.follow("two", "four") == false);
    CHECK(nw2.follow("five", "six") == false);
    CHECK(nw2.follow("seven", "eight") == false);

    CHECK(nw2.getFollowing(0,0) == false);
    CHECK(nw2.getFollowing(0,1) == true);
    CHECK(nw2.getFollowing(0,2) == true);
    CHECK(nw2.getFollowing(1,0) == true);
    CHECK(nw2.getFollowing(1,1) == false);
    CHECK(nw2.getFollowing(1,2) == true);
    CHECK(nw2.getFollowing(2,0) == true);
    CHECK(nw2.getFollowing(2,1) == true);
    CHECK(nw2.getFollowing(2,2) == false);

}