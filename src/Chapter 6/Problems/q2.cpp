/*
    ## Problem ##
    Take input from a file of numbers of type double and ouput the average of 
    the numbers in the file to the screen. The numbers are separated by blanks
    and/or line breaks.

    ## Solution ##
    Open the file with ifstream. Keep track of the sum. Read in the values using
    the output stream of the file.
*/

#include <iostream> // for cout
#include <fstream> // for ifstream
#include <stdlib.h> // for exit

int main() {

    std::ifstream in;
    in.open("Data/q2-data.txt");

    if (in.fail()) {
        std::cout << "Error opening input file.\n";
        exit(1);
    }

    double sum = 0, current;
    int count = 0;

    while (in >> current) {
        sum += current;
        count++;
    }

    in.close();

    std::cout << "The average is: " << sum/count << std::endl;

    return 0;
}