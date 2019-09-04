////
//// Created by Daniel Shema on 12/01/2018.
////
#ifndef CPPA_EX3_COMPLEX_H
#define CPPA_EX3_COMPLEX_H

#include <string>

class Complex{
public:
    Complex (double a, double b): r (a), c (b) {}
    Complex (){
        std::string s ="dsfaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaadgfssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
                "gdfgsfadsssssssssssssssssssssssssssssfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
                "gdfgsfadsssssssssssssssssssssssssssssfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss" ;
    }
private:
    double r; // Real Part
    double c; // Complex Part
};
#endif //CPPA_EX3_COMPLEX_H
