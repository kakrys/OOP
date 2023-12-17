#include "Workflow.h"
#include "Keyboard.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Keyboard keyboard;

    keyboard.registerKey("A", []() { std::cout << "Key A pressed\n"; }, []() { std::cout << "Key A action undone\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C pressed\n"; }, []() { std::cout << "Ctrl+C action undone\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V pressed\n"; }, []() { std::cout << "Ctrl+V action undone\n"; });

    Workflow workflow(keyboard);

    workflow.addAction([&]() { workflow.keypress("A"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+C"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+V"); });
    workflow.addAction([&]() { workflow.undo(); });
    workflow.addAction([&]() { workflow.undo(); });

    std::cout << "Начало работы...\n";
    workflow.perform();

    std::cout << "\nПереназначение клавиш...\n";
    keyboard.registerKey("A", []() { std::cout << "Key A теперь ничего не делает\n"; }, []() { std::cout << "Undo action for A\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C теперь ничего не делает\n"; }, []() { std::cout << "Undo action for Ctrl+C\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V теперь ничего не делает\n"; }, []() { std::cout << "Undo action for Ctrl+V\n"; });

    workflow.perform();

    return 0;
}