//
// Created by Anne Messner on 08.06.2022.
//

#include "Manager.cpp"

template
class
Manager<int>;

template
class
Manager<std::string>;

template
std::ostream &operator<<<>(std::ostream &os, const Manager<int> &x);

template
std::ostream &operator<<<>(std::ostream &os, const Manager<std::string> &x);

