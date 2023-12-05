
#include <string>
#include <fstream>

#include "Cart.h"
#include "Inventory.h"
#include "store.h"

#define DEFAULT_INVENTORY "inventory_list.csv"
#define DEFAULT_OUTPUT_FILE "inventory_update.csv"

using namespace std;

int main() {

    store prompter;
    auto *inv = new Inventory;
    inv = prompter.loadFileintoInv(DEFAULT_INVENTORY);

    prompter.promptTasksCus(inv);

    return 0;
}

