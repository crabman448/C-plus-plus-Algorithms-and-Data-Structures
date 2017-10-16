//
//  Person.hpp
//  Stack
//
//  Created by Taras Nikulin on 09.10.2017.
//  Copyright © 2017 Taras Nikulin. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

struct Person {
    string firstname;
    string lastname;
};

ostream& operator<<(ostream& os, Person& person) {
    os << "Person: " << person.firstname << " " << person.lastname;
    return os;
}

#endif /* Person_hpp */
