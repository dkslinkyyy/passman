#pragma once

#include <string>

#include <vector>

using namespace std;

class Manager {
private:
    struct PasswordEntry {
        std::string service;
        std::string password;
    };

    std::vector<PasswordEntry> entries;

public:
    void addPassword(const std::string& service, const std::string& password);
    void displayPasswords() const;
    void removePassword(const std::string& service);
};
