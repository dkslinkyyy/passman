#pragma once
#include <iostream>
#include <fstream>
#include <vector>  

class FileWriter {
private:
    std::ofstream writer;
    std::ifstream reader;

public:
    void write(const std::vector<std::string>& lines); 
    void read(std::vector<std::string>& lines);         
};
