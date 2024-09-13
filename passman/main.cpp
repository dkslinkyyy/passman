#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Manager.h"
#include "FileWriter.h"


using namespace std;


void copyToClipboard(const std::string& str) {
    const size_t len = str.length() + 1;

    if (OpenClipboard(nullptr)) {
        EmptyClipboard();

        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
        memcpy(GlobalLock(hMem), str.c_str(), len);
        GlobalUnlock(hMem);

        SetClipboardData(CF_TEXT, hMem);
        CloseClipboard();
    }
}


int main()
{
	Manager m;

	m.addPassword("Google", "Test12345");
	m.addPassword("Facebook", "Testing12!");

	m.displayPasswords();

    FileWriter fw;


    //Test 
    std::vector<std::string> linesToWrite = { "Lösenord1", "Lösenord2", "Lösenord3" };
    fw.write(linesToWrite);
    
    std::vector<std::string> linesRead;
    fw.read(linesRead);

    // Skriv ut innehållet som lästes från filen
    for (const std::string& line : linesRead) {
        std::cout << line << std::endl;
    }
	
	return 0;
}
