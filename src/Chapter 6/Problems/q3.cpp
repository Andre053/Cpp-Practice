/*
    ## Problem ##
    Compute the median of a data file. Assume the data is sorted.
    Find the three quartiles for the data file.

    ## Solution ##
    Run through the file once to count the values.
    Run through again and extract the relevant data points.
*/

#include <iostream> // for cout
#include <fstream> // for ifstream
#include <stdlib.h> // for exit

int main() {

    std::ifstream in;
    in.open("Data/q3-data.txt");

    if (in.fail()) {
        std::cout << "Failure opening input file.\n";
        exit(1);
    }

    int count = 0;
    double current;
    while (in >> current) count++;

    in.close();


    int median = count/2;
    int first_quartile = median/2, second_quartile = median, third_quartile = median*1.5;

    in.open("Data/q3-data.txt");

    if (in.fail()) {
        std::cout << "Failure opening input file.\n";
        exit(1);
    }

    int median_count = 0;
    while (in >> current) {
        if (median_count++ == median) {
            if (count%2 != 0) {
                std::cout << "Median (odd) is: " << current << std::endl;
                break;
            }
            else {
                double val = current;
                in >> current;

                std::cout << "Median (even) is: " << (current+val)/2 << std::endl;
                break;
            }
        }
    }

    in.close();

    in.open("Data/q3-data.txt");

    if (in.fail()) {
        std::cout << "Failure opening input file.\n";
        exit(1);
    }

    int quartile_count = 0;

    // quartiles should also be averaged if even
    while (in >> current) {
        if (quartile_count == first_quartile) {
            if (count%2 != 0) {
                std::cout << "First quartile (odd): " << current << std::endl;
            }
            else {
                double val = current;
                in >> current;

                std::cout << "First quartile (even) is: " << (current+val)/2 << std::endl;
                quartile_count++;                 
            }
            
        }
        else if (quartile_count == second_quartile) {
            if (count%2 != 0) {
                std::cout << "Second quartile (odd): " << current << std::endl;
            }
            else {
                double val = current;
                in >> current;

                std::cout << "Second quartile (even) is: " << (current+val)/2 << std::endl;
                quartile_count++;                 
            }
        }
        else if (quartile_count == third_quartile) {
            if (count%2 != 0) {
                std::cout << "Third quartile (odd): " << current << std::endl;
            }
            else {
                double val = current;
                in >> current;

                std::cout << "Third quartile (even) is: " << (current+val)/2 << std::endl;
                quartile_count++;                 
            }
        }
        ++quartile_count;
    }

    in.close();
    

    return 0;
}