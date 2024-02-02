#include"PmergeMe.hpp"
void displaySequence(const std::vector<int> &sequence, const std::string &message) {
    std::cout << message << ": ";
    for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void displayTiming(const std::string &containerName, const clock_t &startTime, const clock_t &endTime) {
    std::cout << "Time to process a range of " << containerName << " : "
              << double(endTime - startTime) / CLOCKS_PER_SEC * 1000000 << " us." << std::endl;
}

int findMedian(const std::list<int> &indices) {
    std::vector<int> temp(indices.begin(), indices.end());
    std::sort(temp.begin(), temp.end());
    return temp[temp.size() / 2];
}

int customPartition(std::vector<int> &c, int start, int end, int pivotIndex) {
    std::swap(c[pivotIndex], c[end]); // Move pivot to end
    int storeIndex = start;
    for (int i = start; i < end; i++) {
        if (c[i] < c[end]) {
            std::swap(c[i], c[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(c[storeIndex], c[end]); // Move pivot to its final place
    return storeIndex;
}

void fordJohnsonMergeInsertionSort(std::vector<int> &c, int start, int end) {
    if (start >= end) return; // Base case for single element or invalid range

    // Base case for two elements
    if (end - start == 1) {
        if (c[start] > c[end]) {
            std::swap(c[start], c[end]);
        }
        return;
    }

    // Sort pairs and find medians
    std::list<int> medians;
    for (int i = start; i < end; i += 2) {
        if (c[i] > c[i + 1]) {
            std::swap(c[i], c[i + 1]);
        }
        medians.push_back(i + 1);
    }

    // Handle odd number of elements
    if ((end - start + 1) % 2 != 0) {
        medians.push_back(end);
    }

    // Find median of medians
    int medianOfMedians = findMedian(medians);

    // Partition around median of medians
    int mid = customPartition(c, start, end, medianOfMedians);

    // Recursively sort elements before and after the partition index
    fordJohnsonMergeInsertionSort(c, start, mid - 1);
    fordJohnsonMergeInsertionSort(c, mid, end);
}

void performSorting(std::vector<int> sequence) {
    clock_t startTime = clock();
    fordJohnsonMergeInsertionSort(sequence, 0, sequence.size() - 1);
    clock_t endTime = clock();

    displaySequence(sequence, "After");

    displayTiming("std::vector", startTime, endTime);
}
