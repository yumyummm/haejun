#pragma once
#include <string>
#include <vector>

class DataProcessor
{
public:
    DataProcessor(std::vector<std::string> data);
    auto sort_by_length() -> std::vector<std::string>;
    // std::vector<std::string> sort_by_length(); 앞쪽에 엄청 긴 이름이 오면 가독성 떨어지니까 위처럼 써라.
    auto filter_by_prefix(const std::string &prefix) -> std::vector<std::string>;
    std::vector<std::string> data_;
};