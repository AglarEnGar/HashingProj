#include <iostream>
#include <hash_map>
#include <string>
#include "Store.h"

using namespace std;


struct hList
{
    std::string word;
    std::size_t index;
};

int main() {
    Store program = Store();
    program.getMenu();
    return 0;
}
