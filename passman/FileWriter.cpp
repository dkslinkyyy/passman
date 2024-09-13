#include "FileWriter.h"
#include <string>

// Skriv varje sträng på en ny rad i filen
void FileWriter::write(const std::vector<std::string>& lines) {
    writer.open("output.txt");
    if (writer.is_open()) {
        for (const std::string& line : lines) {
            writer << line << std::endl;
        }
        writer.close();
    }
    else {
        std::cerr << "Kunde inte öppna filen för att skriva." << std::endl;
    }
}

void FileWriter::read(std::vector<std::string>& lines) {
    reader.open("output.txt");
    std::string line;
    if (reader.is_open()) {
        while (std::getline(reader, line)) {
            lines.push_back(line);  // Lägg till varje rad i vectorn
        }
        reader.close();
    }
    else {
        std::cerr << "Kunde inte öppna filen för att läsa." << std::endl;
    }
}
