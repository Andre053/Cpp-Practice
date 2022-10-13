/*
    ## Problem ##
    Write a program that will search a file of numbers of type int and write the largest
    and smallest numbers to the screen. The file contains nothing but numbers of type int
    separated by blanks or line breaks.

    ## Solution ##
    Open the file in read-only mode. Parse through the file using get
    Use conditionals to find smallest and largest values.
*/

#include <iostream> // for cout
#include <fstream> // for ifstream
#include <stdlib.h> // for exit

int main() {

    std::ifstream in;
    in.open("Data/q1-data.txt");

    if (in.fail()) {
        std::cout << "Input file opening failed" << std::endl;
        exit(1);
    }

    int min = 100000, max = 0, current;

    while (in >> current) {
        if (current > max) max = current;
        if (current < min) min = current;

    }

    in.close();

    std::cout << "Largest value: " << max << "\nSmallest value: " << min << std::endl;


    return 0;
}