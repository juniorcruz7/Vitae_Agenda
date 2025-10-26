#ifndef CLIENTS_H
#define CLIENTS_H

#include <string>

class Client {
private:

    std::string name;
    std::string number;
    int id;

public:

    //Construtor e Destrutor
    Client(std::string name, std::string number, int id);
    ~Client();

};

#endif
