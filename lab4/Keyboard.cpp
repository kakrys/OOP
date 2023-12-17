//
// Created by vadya on 16.12.2023.
//

#include "Keyboard.h"

void Keyboard::pressKey(const std::string& key)
{
    assert(keymap.count(key) && "Unknown key pressed");
    history.push_back(key);
    keymap[key].first();
}

void Keyboard::undo()
{
    if (!history.empty())
    {
        std::cout << "Undo action for key: " << history.back() << "\n";
        keymap[history.back()].second();
        history.pop_back();
    }
}

void Keyboard::registerKey(const std::string &key, const Action &action, const Action &undoAction) {
        keymap[key] = { action, undoAction };
}
