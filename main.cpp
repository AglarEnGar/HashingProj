#include <iostream>
#include <hash_map>
#include <string>


struct hList
{
    std::string word;
    std::size_t index;
};

int main() {
    std::string word = "ooga";
    std::size_t hash_booger = std::hash<std::string>{}(word);

    std::cout << "Lol hi";

    return 0;
}
