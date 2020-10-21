

#ifndef WEBSOCKETNETWORKING_USER_H
#define WEBSOCKETNETWORKING_USER_H

#include "Server.h"
using networking::Connection;

class User {
public:
    Connection connection;
    int roomId;
    std::string userName;

    User(){
        connection = {0};
        roomId = 0;
        userName = "";
    }
    User(Connection connection){
        this->connection = connection;
        roomId = 0;
        userName = "";
    }

    void
    setUserName(std::string name){
        this->userName = name;
    }

    std::string getUserName(){return userName;}

    Connection getConnection(){return connection;}
    int getRoom(){return roomId;}

    bool
    operator==(User other) const {
        return connection == other.connection;
    }
};


#endif //WEBSOCKETNETWORKING_USER_H
