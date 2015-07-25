//
// Created by ami on 23/07/15.
//

#ifndef FSCSMOCK_PROFILE_H
#define FSCSMOCK_PROFILE_H
#include <string>


class Profile {
public:
    Profile() {}
    void checkReading(std::string name, float reading) {}
    void checkTime(tm* gmt);
};


#endif //FSCSMOCK_PROFILE_H
