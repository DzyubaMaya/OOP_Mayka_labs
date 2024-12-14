#include "NPC.h"

// Структура Elf, наследующая от NPC
struct Elf : public NPC {
    // Конструктор с параметрами для инициализации координат и имени
    Elf(int x, int y, const std::string& name);

    // Конструктор из потока ввода для инициализации координат и имени
    Elf(std::istream& is);

    // Метод для вывода информации о Elf
    void print() override;

    // Метод для проверки, является ли NPC эльфом
    bool is_elf() const override;

    // Метод для принятия решения о победе в бою с другим NPC
    bool accept(std::shared_ptr<NPC> attacker) override;

    // Методы для боя с другими типами NPC
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Knight> other) override;

    // Метод для сохранения данных объекта в поток
    void save(std::ostream& os) override;

    // Перегрузка оператора вывода для вывода информации о Elf
    friend std::ostream& operator<<(std::ostream& os, Elf& Elf);

    // Деструктор по умолчанию
    ~Elf() = default;
};