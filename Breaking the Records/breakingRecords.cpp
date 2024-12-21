#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> breakingRecords(const std::vector<int>& scores) {
    int minimum = scores[0];
    int maximum = scores[0];
    std::vector<int> record(2, 0); // [max_breaks, min_breaks]

    for (size_t i = 1; i < scores.size(); ++i) {
        if (scores[i] > maximum) {
            maximum = scores[i];
            record[0]++;
        }
        if (scores[i] < minimum) {
            minimum = scores[i];
            record[1]++;
        }
    }

    return record;
}

int main() {
    std::vector<int> scores = {12, 24, 10, 24};
    std::vector<int> result = breakingRecords(scores);
    std::cout << "Max Breaks: " << result[0] << ", Min Breaks: " << result[1] << std::endl;
    return 0;
}
