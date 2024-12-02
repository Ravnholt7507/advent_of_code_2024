#include "first_solution.h"

bool is_safe(const std::vector<int>& levels) {
    if (levels.size() < 2) return true;

    bool increasing = levels[0] < levels[1];
    for (size_t i = 0; i < levels.size() - 1; ++i) {
        int diff = std::abs(levels[i + 1] - levels[i]);
        if ((increasing && !(levels[i] < levels[i + 1])) ||
            (!increasing && !(levels[i] > levels[i + 1])) ||
            (diff < 1 || diff > 3)) {
            return false; 
        }
    }
    return true;
}

int second_solution() {
    int result = 0;
    std::vector<std::vector<int>> data = get_data();  

    for (const auto& levels : data) {
        if (is_safe(levels)) {
            result++;
        } else {
            bool dampened_safe = false;
            for (size_t i = 0; i < levels.size(); ++i) {
                std::vector<int> modified_levels = levels;
                modified_levels.erase(modified_levels.begin() + i);
                if (is_safe(modified_levels)) {
                    dampened_safe = true;
                    break;
                }
            }
            if (dampened_safe) result++;
        }
    }

    return result;
}
