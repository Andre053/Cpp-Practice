/*
    ## Problem ##
    Program that gives and takes advice on programming writing.
    Write advice to the screen, ask the user to type different advice, then ends.
    The next person to run the program receives the advice given by the last person
    Advice is kept in a file, the contents of the file change after every program runs
    Advice is of any length, end the advice by pressing return twice

    ## Solution ##
    '\n' is the Enter key, wait for two occurances
*/

// libraries
#include <iostream>
#include <fstream>
#include <stdlib.h>

int main() {

    bool enterLast = false;
    char current;
    std::ifstream in;
    std::ofstream out;
    std::string file = "Data/q5-data.txt", line;

    
    in.open(file);

    if (in.fail()) {
        std::cout << "[ERROR] Opening file" << std::endl;
        exit(1);
    }

    std::cout << "Here is some advice!\n" << std::endl;

    // send the file contents to output
    while (std::getline(in, line)) std::cout << line << "\n";    

    in.close();

    std::cout << "Now enter your own advice! Press ENTER twice to finish\n" << std::endl;

    out.open(file);

    if (out.fail()) {
        std::cout << "[ERROR] Opening file" << std::endl;
        exit(1);
    }

    while (std::getline(std::cin, line)) {
        out << line << '\n';
        if (line.empty()) break;
    }

    out.close();

    std::cout << "Thank you for your advice." << std::endl;
    return 0;
}