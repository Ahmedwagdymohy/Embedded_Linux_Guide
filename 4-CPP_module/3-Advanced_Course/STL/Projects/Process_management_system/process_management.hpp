/**
 * @file process_management.hpp
 * @brief Header file for process management classes.
 */

#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include <string>
#include <queue>
#include <stack>

class Process {
private:
    int id;
    std::string name;
    int priority;

public:
    Process(int id, const std::string &name, int priority);
    ~Process();

    // Getters
    int getId() const;
    std::string getName() const;
    int getPriority() const;
};

class Task_manager {
private:
    std::queue<Process> processQueue;
    std::stack<Process> processStack; 
    Task_manager() = default; // Singleton

public:
    static Task_manager& getInstance();

    void addProcess(const Process &processx);
    bool removeProcess(const Process &processx); // Return bool to indicate success/failure
    Process get_next_process();
    void get_all_processes();
    void sort_processes();
    void start_processes();
};

#endif // PROCESS_MANAGEMENT_HPP
