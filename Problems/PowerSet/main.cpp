//
//  main.cpp
//  PowerSet
//
//  Created by Taras Nikulin on 19.10.2017.
//  Copyright © 2017 Taras Nikulin. All rights reserved.
//

#include <iostream>
#include <vector>

std::vector<std::vector<char>> increment(std::vector<std::vector<char>> prevV, std::vector<char> inV, size_t nextInd) {
    if (nextInd == inV.size()) return {};
    std::vector<std::vector<char>> result;
    for (size_t i = nextInd; i < inV.size(); i++) {
        std::vector<char> newV = prevV.back();
        newV.push_back(inV[i]);
        result.push_back(newV);
        std::vector<std::vector<char>> tempRes = increment(result, inV, i + 1);
        if (tempRes.size() > 0) {
            result.insert(result.end(), tempRes.begin(), tempRes.end());
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::vector<char> inputV = {'a', 'b', 'c', 'd', 'e'};
    std::vector<std::vector<char>> result;
    for (size_t i = 0; i < inputV.size(); i++) {
        std::vector<std::vector<char>> res1 = {{inputV[i]}};
        std::vector<std::vector<char>> res2 = increment(res1, inputV, i + 1);
        result.insert(result.end(), res2.begin(), res2.end());
        result.push_back({inputV[i]});
    }
    result.push_back({});
    for (auto vec: result) {
        std::cout << "{";
        for (int i = 0; i < int(vec.size()); i++) {
            std::cout << vec[i];
            if (vec.size() - i > 1) {
                 std::cout << ",";
            }
        }
        std::cout << "},";
    }
    return 0;
}
