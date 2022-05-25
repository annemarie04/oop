//
// Created by Anne Messner on 24.05.2022.
//

#ifndef OOP_MY_EXCEPTIE_H
#define OOP_MY_EXCEPTIE_H


class my_exceptie : public std::runtime_error {
public:
    explicit my_exceptie(const std::string &arg) : runtime_error(arg) {}
};

class eroare_server : public my_exceptie {
public:
    explicit eroare_server(const std::string &arg) : my_exceptie(arg) {}
};

class eroare_client : public my_exceptie {
public:
    explicit eroare_client(const std::string &arg) : my_exceptie(arg) {}
};


#endif //OOP_MY_EXCEPTIE_H
