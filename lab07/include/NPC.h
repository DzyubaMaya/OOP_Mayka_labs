#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <set>
#include <math.h>
#include <cstdlib> // Для std::rand()

// Предварительные объявления структур
struct NPC;
struct Elf;
struct Knight;
struct Robber;

// Перечисление типов NPC
enum NpcType {
    Unknown = 0,
    ElfType = 1,
    KnightType = 2,
    RobberType = 3
};

// Абстрактный интерфейс для наблюдателя, который будет получать уведомления о сражениях
struct IFightObserver {
    virtual void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) = 0;
};

// Класс NPC, который содержит общую информацию и логику для всех NPC
struct NPC : public std::enable_shared_from_this<NPC> {
    std::mutex mtx;
    NpcType type; // Тип NPC
    int x{0}; // Координата x
    int y{0}; // Координата y
    std::string name; // Имя NPC
    std::vector<std::shared_ptr<IFightObserver>> observers; // Наблюдатели
    bool alive{true}; // Флаг жизни

    // Конструктор с параметрами для инициализации типа, координат и имени
    NPC(NpcType t, int _x, int _y, const std::string& name);

    // Конструктор из потока ввода для инициализации типа, координат и имени
    NPC(NpcType t, std::istream& is);

    // Метод для подписки наблюдателя на события боя
    void subscribe(std::shared_ptr<IFightObserver> observer);

    // Уведомление наблюдателей о результате боя
    void fight_notify(std::shared_ptr<NPC> defender, bool win);

    // Проверка, находится ли другой NPC в пределах заданного расстояния
    virtual bool is_close(std::shared_ptr<NPC> other, size_t distance) const;

    // Абстрактный метод решения о победе
    virtual bool accept(std::shared_ptr<NPC> attacker) = 0;

    // Методы для проверки типа NPC (по умолчанию возвращают false)
    virtual bool is_knight() const;
    virtual bool is_elf() const;
    virtual bool is_robber() const;

    // Абстрактные методы для боя с другими типами NPC
    virtual bool fight(std::shared_ptr<Knight> other) = 0;
    virtual bool fight(std::shared_ptr<Elf> other) = 0;
    virtual bool fight(std::shared_ptr<Robber> other) = 0;

    // Абстрактный метод для вывода информации о NPC
    virtual void print() = 0;

    // Метод для сохранения базовых данных объекта в поток
    virtual void save(std::ostream& os);

    // Перегрузка оператора вывода для вывода информации о NPC
    friend std::ostream& operator<<(std::ostream& os, NPC& npc);

    // Метод для броска 6-гранного кубика
    int roll_dice() const {
        return std::rand() % 6 + 1;
    }

    // Метод для перемещения NPC
    void move(int dx, int dy, int max_x, int max_y);

     // Метод для проверки, жив ли NPC
    bool is_alive() const {
        return alive; // По умолчанию NPC считается живым
    }

    // Метод для установки флага смерти
    void must_die() {
        alive = false;
    }


    // Метод для получения типа NPC
     NpcType get_type() const {
        return type;
    }

    // Метод для получения текущих координат
    std::pair<int, int> position() const;

    

    // Виртуальный деструктор по умолчанию
    virtual ~NPC() = default;
};

// Определение типа для удобства
using set_t = std::set<std::shared_ptr<NPC>>;