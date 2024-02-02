#include"PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Error: No input sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> sequence;
    std::string arg;

    for (int i = 1; i < argc; ++i) {
        arg = argv[i];
        int num = atoi(arg.c_str()); // Convert string to int using atoi
        if (num < 0) {
            std::cout << "Error: Negative number encountered." << std::endl;
            return 1;
        }
        sequence.push_back(num);
    }

    displaySequence(sequence, "Before");

    // Make a copy to keep the original sequence
    std::vector<int> sequenceCopy = sequence;

    // Perform Ford-Johnson Merge-Insertion Sort
    performSorting(sequenceCopy);

    return 0;
}