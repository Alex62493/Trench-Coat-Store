//
// Created by Alex on 19.04.2021.
//

#ifndef A67_ALEX62493_CSVFILESERVICE_H
#define A67_ALEX62493_CSVFILESERVICE_H

#include "UserFileServ.h"
#include <vector>
#include <algorithm>

namespace polymorphism {
    class CSVFileService : public UserFileServ {
    public:
        CSVFileService(const std::string &name, Cart *cart1);
        void writeInFile();
        void openFile();
    };
}

#endif //A67_ALEX62493_CSVFILESERVICE_H
