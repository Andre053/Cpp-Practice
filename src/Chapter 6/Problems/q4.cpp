/*
    ## Problem ##
    Program takes input from a file of numbers of type double.
    Ouput the average and the standard deviation of the numbers in the file.


    ## Solution ##
*/

// libraries
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

int main() {

    double avg = 0, stdDev = 0, current = 0;
    int count = 0;

    std::ifstream input;
    input.open("Data/q3-data.txt");

    if (input.fail()) {
        std::cout << "[ERROR] Opening file" << std::endl;
        exit(1);
    }

    // during the iteration, calculate the values
    while (input >> current) {
        avg += current;
        count++;
    }

    avg /= count;

    input.close();

    input.open("Data/q3-data.txt");

    if (input.fail()) {
        std::cout << "[ERROR] Opening file" << std::endl;
        exit(1);
    }

    while (input >> current) {
        stdDev += pow((current-avg), 2);
    }

    stdDev /= count;
    stdDev = sqrt(stdDev);

    input.close();

    // print the values
    std::cout << "The mean value is:\t\t" << avg << "\nThe standard deviation is:\t" << stdDev << std::endl;

    return 0;
}