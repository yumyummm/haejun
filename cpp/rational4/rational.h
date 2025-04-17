#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational{
friend std::ostream& operator<<(std::ostream& out , Rational& rhs);
private:
    int num_;
    int den_;

    void reduce(); // helper func. tool func.
public:


    Rational(int num  = 0, int den = 1);

    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;

    const Rational operator+(const Rational& rhs) const;

    int num() const;
    int den() const;

    void num(int num);
    void den(int den);

    // Rational(){ }
    // Rational(const Rational&) { /* memberwise copy*/ }
    // ~Rational() {}
    // Rational& operator=(const Rational&) {/* memberwise copy*/ return *this; }
    // Rational *operator&() { return this; } 
    // const Rational *operator&() const { return this; } 
    
};

#endif