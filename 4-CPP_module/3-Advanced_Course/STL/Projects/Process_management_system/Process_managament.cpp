/**
 * @file process_management.cpp
 * @brief Implementation file for the Task Manager and Process classes.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "process_management.hpp"

Process::Process(int id, const std::string &name, int priority)
    : id(id), name(name), priority(priority) {
}

Process::~Process() {
}

int Process::getId() const {
    return id;
}

std::string Process::getName() const {
    return name;
}

int Process::getPriority() const {
    return priority;
}

Task_manager& Task_manager::getInstance() {
    static Task_manager instance;
    return instance;
}

void Task_manager::addProcess(const Process &processx) {
    processQueue.push(processx);
}

bool Task_manager::removeProcess(const Process &processx) {
    std::vector<Process> tempVector;
    bool found = false;

    while (!processQueue.empty()) {
        if (processQueue.front().getId() != processx.getId()) {
            tempVector.push_back(processQueue.front());
        } else {
            found = true; 
        }
        processQueue.pop();
    }

    for (auto &p : tempVector) {
        processQueue.push(p);
    }

    return found;
}

Process Task_manager::get_next_process() {
    if (processQueue.empty()) {
        throw std::runtime_error("No processes in the queue.");
    }
    return processQueue.front();
}

void Task_manager::get_all_processes() {
    if (processQueue.empty()) {
        std::cout << "\n\033[93m[No processes in the queue]\033[0m\n" << std::endl;
        return;
    }

    std::queue<Process> tempQueue = processQueue;
    std::cout << "\n\033[94m[All Processes]\033[0m\n";
    std::cout << "-------------------------------------------\n";
    while (!tempQueue.empty()) {
        std::cout << "\033[92mProcess ID:\033[0m " << tempQueue.front().getId() << "\n"
                  << "\033[92mProcess Name:\033[0m " << tempQueue.front().getName() << "\n"
                  << "\033[92mProcess Priority:\033[0m " << tempQueue.front().getPriority() << "\n";
        std::cout << "-------------------------------------------\n";
        tempQueue.pop();
    }
    std::cout << std::endl;
}

void Task_manager::sort_processes() {
    std::vector<Process> tempVector;

    while (!processQueue.empty()) {
        tempVector.push_back(processQueue.front());
        processQueue.pop();
    }

    std::sort(tempVector.begin(), tempVector.end(), [](const Process &a, const Process &b) {
        return a.getPriority() > b.getPriority();
    });

    for (auto &p : tempVector) {
        processQueue.push(p);
    }
}

void Task_manager::start_processes() {
    sort_processes();
    get_all_processes();
}
