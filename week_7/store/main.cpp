#include "store.h"

void testStore(std::string file_name) {
    // *.bin, *.dat std::ios::binary
    // *.txt

    Store test_store;
    std::ifstream in(file_name, std::ios::in);

    // in.bad(), in.good(), in.fail(), in.eof(), in.is_open()

    if (!in.good()) {
        throw std::invalid_argument("Could not open file!");
    }

    uint number_of_items;
    in >> number_of_items;
    // file >> file / stream / variable / const
    // in.get(&number_of_items)
    // number_of_items = in.get()
    // in.getline(...)

    Item current;

    for(uint i = 0; i < number_of_items && !in.eof(); ++i) {
        in >> current;
        test_store.add(current);
    }

    in.close();
    std::cout << test_store << std::endl;
}

int main() {

    testStore("item_list.txt");
    return 0;
}