#include "../../include/clients.h"
#include <iostream>

//Constructor without parameters
Client::Client() {
    name = "";
    number = "";
    id = 0;
}

//Constructor with parameters
Client::Client(std::string name, std::string number, int id) {
    this->name = name;
    this->number = number;
    this->id = id;
}

//Destructor
Client::~Client() {

}

//Getters
std::string Client::get_name() {
    return name;
}

std::string Client::get_number() {
    return number;
}

int Client::get_id() {
    return id;
}

//Setters
void Client::set_name(std::string name) {
    this->name = name;
}

void Client::set_number(std::string number) {
    this->number = number;
}

void Client::set_id(int id) {
    this->id = id;
}

//Printing informations
void Client::print_info() {
    std::cout << "Paciente: " << name
              << " | Telefone: " << number
              << " | ID: " << id << std::endl;
}
