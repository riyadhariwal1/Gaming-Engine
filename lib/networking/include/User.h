

#ifndef WEBSOCKETNETWORKING_USER_H
#define WEBSOCKETNETWORKING_USER_H

#include "Server.h"
using networking::Connection;

class User {
public:
    Connection connection;
    int roomId;

    User(){
        connection = {0};
        roomId = 0;
    }
    User(Connection connection){
        this->connection = connection;
        roomId = 0;
    }

    Connection getConnection(){return connection;}
    int getRoom(){return roomId;}

    bool
    operator==(User other) const {
        return connection == other.connection;
    }
};


#endif //WEBSOCKETNETWORKING_USER_H
