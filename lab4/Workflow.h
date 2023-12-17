//
// Created by vadya on 16.12.2023.
//

#ifndef LAB4_WORKFLOW_H
#define LAB4_WORKFLOW_H

#pragma once

#include "Keyboard.h"

class Workflow
{
public:
    explicit Workflow(Keyboard& keyboard) : keyboard(keyboard) {}

    void keypress(const std::string& key);

    void undo();

    void perform();

    void addAction(const Action& action);

private:
    Keyboard& keyboard;
    std::vector<Action> actions;
};


#endif //LAB4_WORKFLOW_H
