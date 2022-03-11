//
// Created by Alex on 19.04.2021.
//

#include "HTMLFileServ.h"

namespace polymorphism{
    HTMLFileServ::HTMLFileServ(const std::string &name, Cart *cart1) : UserFileServ(name, cart1) {
    }

    void HTMLFileServ::openFile()
    {
        ShellExecuteA(nullptr, nullptr, "chrome.exe", this->fileName.c_str(), nullptr, SW_SHOWMAXIMIZED);
    }

    void HTMLFileServ::writeInFile()
    {
        this->file.close();
        this->file.open(this->fileName);

        this->file << "<!DOCTYPE html>" << std::endl;
        this->file << "<html>" << std::endl;
        this->file << "<head>" << std::endl;
        this->file << "<title>Cart</title>" << std::endl;
        this->file << "</head>" << std::endl;
        this->file << "<body>" << std::endl;
        this->file << "<table border=\"1\">" << std::endl;

        int i;
        std::vector<std::string> all = this->cart->getPrintList(i);

        for (const std::string& s : all) {
            std::vector<std::string> elem;
            polymorphism::HTMLFileServ::split(s, "\t", elem);
            this->file << "<tr>" << std::endl;
            this->file << "<td>" << elem[0] << "</td>" << std::endl;
            this->file << "<td>" << elem[1] << "</td>" << std::endl;
            this->file << "<td>" << elem[2] << "</td>" << std::endl;
            this->file << "<td>" << elem[3] << "</td>" << std::endl;
            this->file << "<td>" << elem[4] << "</td>" << std::endl;

            if (elem[5] != "Photograph")
                this->file << "<td><a href=\"" << elem[5] << "\">Link</a></td>" << std::endl;
            else
                this->file << "<td>" << elem[5] << "</td>" << std::endl;

            this->file << "</tr>" << std::endl;
        }

        this->file << "</table>" << std::endl;
        this->file << "</body>" << std::endl;
        this->file << "</html>" << std::endl;
    }

    void HTMLFileServ::split(const std::string &str, const std::string &delim, std::vector<std::string> &parts) {
        size_t start, end = 0;
        while (end < str.size()) {
            start = end;
            while (start < str.size() && (delim.find(str[start]) != std::string::npos)) {
                start++;
            }
            end = start;
            while (end < str.size() && (delim.find(str[end]) == std::string::npos)) {
                end++;
            }
            if (end - start != 0) {
                parts.push_back(std::string(str, start, end - start));
            }
        }
    }
}