#include "Manager.h"  


#include <iostream>   
#include <algorithm>  

void Manager::addPassword(const std::string& service, const std::string& password) {
    entries.push_back({ service, password });
    std::cout << "Lösenord för " << service << " har lagts till.\n";
}

void Manager::displayPasswords() const {
    int index = 0;
    for (const auto& entry : entries) {
        std::cout << "[" << index << "]" <<" Tjänst: " << entry.service << " | Lösenord: " << entry.password << '\n';
        index++;
    }
}

// Implementering av removePassword
void Manager::removePassword(const std::string& service) {
    entries.erase(
        std::remove_if(entries.begin(), entries.end(), [&](const PasswordEntry& entry) {
            return entry.service == service;
            }),
        entries.end()
    );
    std::cout << "Lösenord för " << service << " har tagits bort.\n";
}
