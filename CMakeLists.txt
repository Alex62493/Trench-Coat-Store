cmake_minimum_required(VERSION 3.19)
project(Trench_Coat_Store)
include_directories(.idea)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
find_package(Qt5Widgets REQUIRED)

include_directories(domain)
include_directories(exceptions)
include_directories(repo)
include_directories(serv)
include_directories(tests)
include_directories(UI)
include_directories(validator)

add_executable(Trench_Coat_Store
        domain/DynamicArray.cpp
        domain/DynamicArray.h
        domain/TrenchCoat.cpp
        domain/TrenchCoat.h
        exceptions/ValidatorException.cpp
        exceptions/ValidatorException.h
        repo/Cart.cpp
        repo/Cart.h
        repo/DataBase.cpp
        repo/DataBase.h
        serv/Controller.cpp
        serv/Controller.h
        serv/CSVFileService.cpp
        serv/CSVFileService.h
        serv/FileServ.cpp
        serv/FileServ.h
        serv/HTMLFileServ.cpp
        serv/HTMLFileServ.h
        serv/UserFileServ.cpp
        serv/UserFileServ.h
        serv/UserServ.cpp
        serv/UserServ.h
        tests/Tests.cpp
        tests/Tests.h
        UI/AdminConsole.cpp
        UI/AdminConsole.h
        UI/AdminGUI.cpp
        UI/AdminGUI.h
        UI/CoatTable.cpp
        UI/CoatTable.h
        UI/GUI.cpp
        UI/GUI.h
        UI/LoginGUI.cpp
        UI/LoginGUI.h
        UI/UserConsole.cpp
        UI/UserConsole.h
        UI/UserGUI.cpp
        UI/UserGUI.h
        validator/Validator.cpp
        validator/Validator.h
        main.cpp)

target_link_libraries(Trench_Coat_Store Qt5::Widgets)
