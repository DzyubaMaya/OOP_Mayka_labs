#include <gtest/gtest.h>
#include "allocator.h"
#include "queue.h"

// Тест для MyMemoryResource
TEST(MyMemoryResourceTest, BasicAllocation) {
    MyMemoryResource mr;

    // Выделяем память
    void* ptr1 = mr.allocate(100, 1);
    EXPECT_NE(ptr1, nullptr); // Убедимся, что память выделена

    // Освобождаем память
    mr.deallocate(ptr1, 100, 1);

  
}




// Тест для MyQueue с int
TEST(MyQueueTest, IntQueueOperations) {
    MyMemoryResource mr;
    MyQueue<int> queue(&mr);

    // Проверяем, что очередь изначально пуста
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);

    // Добавляем элементы в очередь
    queue.push(10);
    queue.push(20);
    queue.push(30);

    // Проверяем размер и содержимое очереди
    EXPECT_FALSE(queue.empty());
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.back(), 10); // Последний элемент в очереди

    // Удаляем элементы из очереди
    EXPECT_EQ(queue.pop(), 10);
    EXPECT_EQ(queue.pop(), 20);
    EXPECT_EQ(queue.pop(), 30);

    // Проверяем, что очередь пуста
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);

    // Попытка удаления из пустой очереди
    EXPECT_THROW(queue.pop(), std::out_of_range);
}

// Тест для MyQueue с std::string
TEST(MyQueueTest, StringQueueOperations) {
    MyMemoryResource mr;
    MyQueue<std::string> queue(&mr);

    // Добавляем элементы в очередь
    queue.push("Hello");
    queue.push("World");
    queue.push("!");

    // Проверяем размер и содержимое очереди
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.back(), "Hello");

    // Удаляем элементы из очереди
    EXPECT_EQ(queue.pop(), "Hello");
    EXPECT_EQ(queue.pop(), "World");
    EXPECT_EQ(queue.pop(), "!");

    // Проверяем, что очередь пуста
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
}

// Тест для итератора
TEST(MyQueueTest, IteratorOperations) {
    MyMemoryResource mr;
    MyQueue<int> queue(&mr);

    // Добавляем элементы в очередь
    queue.push(10);
    queue.push(20);
    queue.push(30);

    // Проверяем итератор
    auto it = queue.begin();
    EXPECT_EQ(*it, 30); // Первый элемент в очереди
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(it, queue.end()); // Достигли конца очереди
}

// Основной файл для запуска тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}