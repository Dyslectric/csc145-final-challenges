#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> parse() {
    int n;
    std::cin >> n;
    std::vector<int> set(n);
    for(int i = 0; i < n; i++) {
        std::cin >> set[i];
    }
    return set;
}

int main() {
    auto set = parse();

    // print the set
    //for(int elem : set) {
    //    std::cout << elem << " ";
    //}
    //std::cout << std::endl;

    // sort the set
    std::sort(set.begin(), set.end());

    // create a table of largest divisible subset ending at each index
    std::vector<std::vector<int>> subsets(set.size());

    std::vector<int> max_subset;

    for(int i = 0; i < set.size(); i++) {
        subsets[i].push_back(set[i]);
        for(int j = i - 1; j >= 0; j--) {
            if (
                set[i] % set[j] == 0 &&
                subsets[i].size() < subsets[j].size() + 1
            ) {
                subsets[i] = subsets[j];
                subsets[i].push_back(set[i]);
            }
        }
        if (subsets[i].size() > max_subset.size()) 
            max_subset = subsets[i];
    }

    // print max subset
    //for( int elem : max_subset ) {
    //    std::cout << elem << " ";
    //}
    //std::cout << std::endl;

    //std::cout << "Max: " << max_subset.size() << std::endl;
    std::cout << max_subset.size() << std::endl;

    return 0;
}