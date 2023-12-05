#include <iostream>
#include <hash_map>
#include <string>
#include <fstream>
#include "main.h"
#include <regex>

#define DEFAULT_INVENTORY "inventory_list.csv"
#define DEFAULT_OUTPUT_FILE "inventory_update.csv"

int max_menu_option = 10;
int max_inventory_file = 5;

using namespace std;

const std::regex comma(",");

Inventory * store::loadFileintoInv(std::string file)
{
    auto * p = new Product;
    auto * inv = new Inventory;
    std::string line = "";
    ifstream input_file;
    input_file.open(file);


    if(!input_file.is_open())
    {
        cout << "ERROR! Cannot read chosen file " << file << ". File \"" << 1 << "\" remains open." << endl;
        return loadFileintoInv(mainInvFile);
    }

    while(input_file && getline(input_file, line))
    {
        std::vector<std::string> row { std::sregex_token_iterator(line.begin(),line.end(),comma,-1), std::sregex_token_iterator() };
        p->setProductId(stoi(row.at(0)));
        p->setProductName(row.at(1));
        p->setProductPrice(std::stod(row.at(2)));
        p->setDescription(row.at(3));
        inv->insert(*p);
    }
    return inv;
}

int main() {

    Inventory * inv = new Inventory;
    store prompt;

    inv = prompt.loadFileintoInv(DEFAULT_INVENTORY);
    inv->printall();

    return 0;
}

