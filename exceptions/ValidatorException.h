//
// Created by Alex on 12.04.2021.
//

#ifndef A45_ALEX62493_VALIDATOREXCEPTION_H
#define A45_ALEX62493_VALIDATOREXCEPTION_H
#include <string>


class ValidatorException {
private:
    std::string message;
public:
    explicit ValidatorException(const std::string& msg);
    std::string what();
};


#endif //A45_ALEX62493_VALIDATOREXCEPTION_H
