#pragma once
#include <memory_resource>
#include <vector>
#include <iostream>
#include <algorithm>


class MyMemoryResource : public std::pmr::memory_resource {
    struct Block {
        size_t offset {0};//смещение блока в буфере
        size_t size {0}; //размер блока
    };

    static constexpr size_t max_size{600};
    char buffer[max_size];
    std::vector<Block> used_blocks; //информация о всех выделенных блоках памяти
    size_t my_last_free_offset{0}; //указатель на последний свободный блок 

public:
      void* do_allocate(size_t bytes, size_t alignment) override {

    // Проверка последнего свободного блока
    size_t result = my_last_free_offset;
    if (result + bytes >= max_size) {
        // Если последний свободный блок недостаточен, ищем новый свободный блок
        result = 0;
        for (const Block& b : used_blocks) {
            if ((result + bytes <= b.offset) || (result >= b.offset + b.size)) {}
            else result = b.offset + b.size + 1;
        }
    }
    // Проверка, достаточно ли места в буфере для выделения памяти
    if (result + bytes >= max_size) throw std::bad_alloc();
    // Добавление нового блока памяти в список используемых блоков
    used_blocks.emplace_back(result, bytes);
    // Сортировка списка используемых блоков по их смещению
    std::sort(used_blocks.begin(), used_blocks.end(),
              [](auto& lhv, auto& rhv) { return lhv.offset <= rhv.offset; });
    // Вывод информации о выделении памяти
    std::cout << "allocate: " << result << ":" << bytes << std::endl;

    my_last_free_offset = result + bytes;// Обновление указателя на последний свободный блок

    return buffer + result; // Возврат указателя на выделенную память
}

    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        std::cout << "deallocate: " << ptr << ":" << bytes << std::endl;
        for (size_t i = 0; i < used_blocks.size(); ++i) {
            if (ptr == buffer + used_blocks[i].offset) {
                used_blocks.erase(used_blocks.begin() + i);
                return;
            }
        }
        throw std::logic_error("удаление не выделяемого блока");
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};





