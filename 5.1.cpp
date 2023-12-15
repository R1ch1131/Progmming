#include <iostream>
#include <vector>
#include <list>
#include <string>

// Хеш-функция для строк
constexpr size_t P = 300007; // Размер таблицы. Ближайшее простое > 3*100000
constexpr size_t A = 31;      // Простое и не меньше размера алфавита

size_t hash_str(const std::string& value) {
    size_t h = 0;
    for (char ch : value) {
        h = (h * A + ch) % P;
    }
    return h;
}

class HashTable {
private:
    std::vector<std::list<std::pair<std::string, std::string>>> table;

public:
    HashTable(size_t size) : table(size) {}

    void put(const std::string& key, const std::string& value) {
        size_t index = hash_str(key) % table.size();
        for (auto& kvp : table[index]) {
            if (kvp.first == key) {
                kvp.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }

    void remove(const std::string& key) {
        size_t index = hash_str(key) % table.size();
        table[index].remove_if([key](const std::pair<std::string, std::string>& kvp) { return kvp.first == key; });
    }

    std::string get(const std::string& key) {
        size_t index = hash_str(key) % table.size();
        for (const auto& kvp : table[index]) {
            if (kvp.first == key) {
                return kvp.second;
            }
        }
        return "null";
    }
};

int main() {
    HashTable hashTable(P); // Инициализация хеш-таблицы с размером P

    std::string command, key, value;
    while (std::cin >> command >> key) {
        if (command == "put") {
            std::cin >> value;
            hashTable.put(key, value);
        } else if (command == "delete") {
            hashTable.remove(key);
        } else if (command == "get") {
            std::cout << hashTable.get(key) << std::endl;
        }
    }

    return 0;
}