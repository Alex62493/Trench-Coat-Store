//
// Created by Alex on 12.04.2021.
//

#include "ValidatorException.h"

ValidatorException::ValidatorException(const std::string &msg)
{
    this->message = msg;
}

std::string ValidatorException::what()
{
    return this->message;
}