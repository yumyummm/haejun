#ifndef ARRAY_H
#define ARRAY_H
#define ARRAY_SIZE 100

class Array{
private:
    int *pArr_;
    int size_;

public:
    //Array();
    explicit Array(int size = ARRAY_SIZE);
    Array(const int *pArr, int size);
    Array(const Array& rhs);
    ~Array();
    
    Array& operator=(const Array& rhs);
    
    bool operator==(const Array& rhs) const;

    int& operator[](int index);
    const int& operator[](int index) const;

    //Array(const Array&)
    //Array& operator=(const Array&)
    //Array *operator&() {return *this;}
    //const Array *operator&() const{return *this;}

    int size() const;


};
#endif