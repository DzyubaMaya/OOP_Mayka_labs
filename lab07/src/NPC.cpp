#include "NPC.h"
#include <iostream>
#include <cmath>
#include <memory>

// Конструктор с параметрами для инициализации типа, координат и имени
NPC::NPC(NpcType t, int _x, int _y, const std::string& _name) : type(t), x(_x), y(_y), name(_name) {}

// Конструктор из потока ввода для инициализации типа, координат и имени
NPC::NPC(NpcType t, std::istream& is) : type(t) {
    is >> x >> y >> name; // Чтение координат и имени из потока
}

// Метод для подписки наблюдателя на события боя
void NPC::subscribe(std::shared_ptr<IFightObserver> observer) {
    observers.push_back(observer); // Добавление наблюдателя в список
}

// Метод для уведомления наблюдателей о результате боя
void NPC::fight_notify(std::shared_ptr<NPC> defender, bool win) {
    for (auto& observer : observers) {
        observer->on_fight(shared_from_this(), defender, win); // Уведомление каждого наблюдателя
    }
}

// Метод для проверки, находится ли другой NPC в пределах заданного расстояния
bool NPC::is_close(std::shared_ptr<NPC> other, size_t distance) const {
    // Вычисление квадрата расстояния между текущим NPC и другим NPC
    return std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2);
}

// Методы для проверки типа NPC (по умолчанию возвращают false)
bool NPC::is_knight() const { return false; }
bool NPC::is_elf() const { return false; }
bool NPC::is_robber() const { return false; }

// Метод для сохранения базовых данных объекта в поток
void NPC::save(std::ostream& os) {
    os << x << " " << y << " " << name << std::endl; // Запись координат и имени в поток
}

// Перегрузка оператора вывода для вывода информации о NPC
std::ostream& operator<<(std::ostream& os, NPC& npc) {
    os << "{ type: " << npc.type 
       << ", x: " << npc.x 
       << ", y: " << npc.y 
       << ", name: " << npc.name 
       << " }";
    return os;
}

// Метод для перемещения NPC
void NPC::move(int dx, int dy, int max_x, int max_y) {
    x = std::max(0, std::min(x + dx, max_x));
    y = std::max(0, std::min(y + dy, max_y));
}

// Метод для получения текущих координат
std::pair<int, int> NPC::position() const {
    return {x, y};
}




// Метод для определения результата боя
bool NPC::accept(std::shared_ptr<NPC> attacker) {
    int attack_power = attacker->roll_dice(); // Сила атаки
    int defense_power = this->roll_dice();    // Сила защиты
    return attack_power > defense_power;     // Возвращает true, если атака сильнее защиты
}


