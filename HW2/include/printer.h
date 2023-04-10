#pragma once
#include <iostream>

template <class Out, class T>
void printer(Out& out, const T& data) {
   out << data;
}