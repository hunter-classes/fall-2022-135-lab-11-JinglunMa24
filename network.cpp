#include <iostream>
#include "network.h"

Network::Network() {
    // Task B
    numUsers = 0;

    // Task C
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_USERS; j++) {
            following[i][j] = false;
        }
    }
}

bool Network::addUser(std::string usrn, std::string dspn) {
    bool alpha = true;

    for (int i = 0; i < usrn.length(); i++) {
        if (!isalpha(usrn[i]) && !isdigit(usrn[i])) {
            alpha = false;
        }
    }

    if (numUsers < MAX_USERS && alpha && findID(usrn) == -1) {
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    }

    return false;
}

bool Network::follow(std::string usrn1, std::string usrn2) {
    if (findID(usrn1) != -1 && findID(usrn2) != -1) {
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
    else {
        return false;
    }
}

void Network::printDot() {
    std::string connectionStr, usrnStr;
    bool firstTrue = true;

    for (int row = 0; row < MAX_USERS; row++) {
        for (int col = 0; col < MAX_USERS; col++) {
            if (following[row][col] == true) {
                connectionStr += "\t\"@" + profiles[row].getUsername() + "\" -> \"@" + profiles[col].getUsername() + "\"\n";
                if (firstTrue) {
                    usrnStr += "\t\"@" + profiles[row].getUsername() + "\"\n";
                    firstTrue = false;
                }
            }
        }
        firstTrue = true;
    }

    std::string finalStr = "digraph {\n" + usrnStr + '\n' + connectionStr + "}\n";
    std::cout << finalStr;
}

bool Network::getFollowing(int row, int col) const{
    return following[row][col];
}