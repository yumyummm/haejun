#include "data_process.hpp"
#include <algorithm>

DataProcessor::DataProcessor(std::vector<std::string> data) : data_(data) {}
auto DataProcessor::sort_by_length() -> std::vector<std::string>
{
    auto result = data_;
    std::sort(result.begin(),
              result.end(),
              [](const std::string &a, const std::string &b)
              {
                  return a.length() < b.length();
              });
    return result;
}
auto DataProcessor::filter_by_prefix(const std::string &prefix) -> std::vector<std::string>
{
    std::vector<std::string> result;
    std::copy_if(data_.begin(),
                 data_.end(),
                 std::back_inserter(result), //이 벡터에 대해서 푸시백 연산을 해서 23줄의 result로 출력됨.
                 [prefix](const std::string &s)
                 {
                     return s.find(prefix) == 0;
                 });
    return result;
}