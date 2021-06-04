#include "id.h"

void data::initialize() {
    if (data::id != 0) {
        return;
    }

    std::ifstream idFile("id.dat", std::ios::in | std::ios::binary);
    if (!idFile) {
        throw std::runtime_error("Could not open ID configuration file [id.dat]!");
    }
    // idFile >> data::id;

    std::string line;
    std::getline(idFile, line);
    std::stringstream value(line);
    value.clear();
    if (!value) {
        throw std::runtime_error("Invalid content of file [id.dat]!");
    }

    value >> data::id;
    idFile.close();
}

uint data::getAndIncrease() {
    if (data::id == ADMIN_ID) {
        throw std::runtime_error("Maximum number of users has been reached! Restart server.");
    }

    data::save();
    return data::id++;
}

void data::save() {
    std::ofstream idFile("id.dat", std::ios::out | std::ios::binary | std::ios::trunc);
    if (!idFile) {
        throw std::runtime_error("Could not open ID configuration file [id.dat]!");
    }

    idFile << data::id;
    idFile.close();
}