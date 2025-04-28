#include <iostream>
#include <cstddef>

template <typename T, std::size_t N> 
class MyContainer {
private:
    T data_[N]; // 배열 선언에 세미콜론 추가

public:
    MyContainer() {
        for (std::size_t i = 0; i < N; ++i) {
            data_[i] = static_cast<T>(i + 1);
        }
    }

    class Iter {
    private: 
        T* ptr;

    public: 
        using iterator_category = std::forward_iterator_tag; // 공백 제거
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit Iter(T* p) : ptr(p) {} // 클래스 이름 수정
        reference operator*() const { return *ptr; }
        pointer operator->() { return ptr; }
        Iter& operator++() {
            ++ptr;
            return *this;
        } 
        Iter operator++(int) {
            Iter temp = *this;
            ++(*this);
            return temp;
        }
        friend bool operator==(const Iter& a, const Iter& b) {
            return a.ptr == b.ptr;
        }
        friend bool operator!=(const Iter& a, const Iter& b) {
            return a.ptr != b.ptr;
        }
    }; // 클래스 정의 끝에 세미콜론 추가

    Iter begin() { return Iter(data_); }
    Iter end() { return Iter(data_ + N); }
};

using namespace std;

int main() {
    MyContainer<int, 10> container;

    for (auto v : container) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}