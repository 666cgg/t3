#include<iostream>
#include"other.h"
using namespace std;
int main() {
        const auto b=other::exec("cls");
        std::cout<<b;
        return 0;
}
