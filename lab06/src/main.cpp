#include "NPC.h"
#include "knight.h"
#include "robber.h"
#include "elf.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <set>

// Определение типа для удобства
using set_t = std::set<std::shared_ptr<NPC>>;


// Паттерн Observer 
// Класс наблюдателя для вывода информации о боях
class TextObserver : public IFightObserver {
private:
    TextObserver() = default; 

public:
    // Метод для получения экземпляра наблюдателя
    static std::shared_ptr<IFightObserver> get() {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver*) {});
    }

    // Метод для обработки события боя
    void on_fight(const std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> const defender, bool win) override {
        if (win) {
            std::cout << "\nMurder --------" << std::endl;
            attacker->print();
            defender->print();
        }
    }
};


//Паттерн Factory
// Фабричная функция для создания NPC из потока ввода
std::shared_ptr<NPC> factory(std::istream& is) {
    int type = 0;
    if (is >> type) {
        switch (static_cast<NpcType>(type)) {
            case KnightType: return std::make_shared<Knight>(is);
            case RobberType: return std::make_shared<Robber>(is);
            case ElfType: return std::make_shared<Elf>(is);
            default: std::cerr << "Unexpected NPC type: " << type << std::endl; break;
        }
    }
    return nullptr;
}

// Фабричная функция для создания NPC с указанием типа, координат и имени
std::shared_ptr<NPC> factory(NpcType type, int x, int y, const std::string& name) {
    switch (type) {
        case KnightType: return std::make_shared<Knight>(x, y, name);
        case RobberType: return std::make_shared<Robber>(x, y, name);
        case ElfType: return std::make_shared<Elf>(x, y, name);
        default: return nullptr;
    }
}

// Функция для сохранения списка NPC в файл
void save(const set_t& array, const std::string& filename) {
    std::ofstream fs(filename);
    if (!fs.is_open()) {
        std::cerr << "Failed to open file for saving: " << filename << std::endl;
        return;
    }
    fs << array.size() << std::endl; // Запись количества NPC
    for (const auto& npc : array)
        npc->save(fs); // Сохранение каждого NPC
}

// Функция для загрузки списка NPC из файла
set_t load(const std::string& filename) {
    set_t result;
    std::ifstream fs(filename);
    if (!fs.is_open()) {
        std::cerr << "Failed to open file for loading: " << filename << std::endl;
        return result;
    }

    size_t count = 0;
    fs >> count; // Чтение количества NPC
    for (size_t i = 0; i < count; ++i) {
        if (auto npc = factory(fs)) { // Создание NPC из потока
            result.insert(npc);
        }
    }
    return result;
}

// Перегрузка оператора вывода для вывода списка NPC
std::ostream& operator<<(std::ostream& os, const set_t& array) {
    for (const auto& npc : array)
        npc->print(); // Вывод информации о каждом NPC
    return os;
}

// Функция для проведения боев между NPC
set_t fight(const set_t& array, size_t distance) {
    set_t dead_list;

    for (const auto& attacker : array) {
        for (const auto& defender : array) {
            if (attacker != defender && attacker->is_close(defender, distance)) {
                bool success = defender->accept(attacker); // Проверка, может ли атакующий атаковать защищающегося
                if (success)
                    dead_list.insert(defender); // Добавление защищающегося в список убитых
            }
        }
    }

    return dead_list;
}

int main() {
    set_t array;

    // Генерация начальных NPC
    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 100; ++i) {
        NpcType type = static_cast<NpcType>(std::rand() % 3 + 1);
        int x = std::rand() % 100;
        int y = std::rand() % 100;
        std::string name = "NPC_" + std::to_string(i); // Генерация имени

        auto npc = factory(type, x, y, name);
        if (npc) array.insert(npc);
    }

    // Сохранение
    std::cout << "Saving ..." << std::endl;
    save(array, "npc.txt");

    // Загрузка
    std::cout << "Loading ..." << std::endl;
    array = load("npc.txt");

    // Битва
    std::cout << "Fighting ..." << std::endl << array;
    for (size_t distance = 20; distance <= 100 && !array.empty(); distance += 10) {
        auto dead_list = fight(array, distance); // Проведение боев
        for (const auto& dead : dead_list)
            array.erase(dead); // Удаление убитых из списка

        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl;
    }

    // Оставшиеся в живых
    std::cout << "Survivors:" << std::endl << array;

    return 0;
}