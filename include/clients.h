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
    Client();
    ~Client();

    //Getters
    std::string get_name();
    std::string get_number();
    int get_id();

    //Setters
    void set_name(std::string name);
    void set_number(std::string number);
    void set_id(int id);

    //Printing info
    void print_info();

};

#endif
