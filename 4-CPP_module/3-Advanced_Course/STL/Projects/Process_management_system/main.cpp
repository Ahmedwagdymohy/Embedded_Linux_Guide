#include <iostream>
#include <string>
#include <limits>
#include "process_management.hpp"

static void printAsciiArt() {
    // Print top portion in blue (representing "TASK")
    std::cout << "\033[94m"
              << "████████╗ █████╗ ███████╗██╗  ██╗    ███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗██████╗ \n"
              << "╚══██╔══╝██╔══██╗██╔════╝██║ ██╔╝    ████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝██╔══██╗\n"
              << "   ██║   ███████║███████╗█████╔╝     ██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██████╔╝\n"
              << "   ██║   ██╔══██║╚════██║██╔═██╗     ██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██╔══██╗\n"
              << "   ██║   ██║  ██║███████║██║  ██╗    ██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║  ██║\n"
              << "   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝\n"
              << "\033[0m";

     std::cout << "\033[92m"
              << "                                                                                         ┓ ┏┏┓┏┓┳┓┓┏\n"
              << "                                                                                         ┃┃┃┣┫┃┓┃┃┗┫\n"
              << "                                                                                         ┗┻┛┛┗┗┛┻┛┗┛\n"
              << "\033[0m";}


static void displayMenu() {
    std::cout << "\n\033[96m====== Task Manager Menu ======\033[0m\n";
    std::cout << " \033[94m1.\033[0m Add Process\n";
    std::cout << " \033[94m2.\033[0m Remove Process\n";
    std::cout << " \033[94m3.\033[0m View Next Process\n";
    std::cout << " \033[94m4.\033[0m View All Processes\n";
    std::cout << " \033[94m5.\033[0m Start Processes (Sort by Priority)\n";
    std::cout << " \033[94m6.\033[0m Exit Task Manager\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "\033[93mEnter your choice:\033[0m ";
}

int main() {
    Task_manager& taskManager = Task_manager::getInstance();
    int choice;

    // Print the ASCII art once at the start
    printAsciiArt();

    while (true) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[91mInvalid input. Please enter a number.\033[0m\n";
            continue;
        }

        switch (choice) {
            case 1: {
                int id, priority;
                std::string name;

                std::cout << "\nEnter Process ID: ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter Process Name: ";
                std::getline(std::cin, name);

                std::cout << "Enter Process Priority: ";
                std::cin >> priority;

                Process newProcess(id, name, priority);
                taskManager.addProcess(newProcess);
                std::cout << "\033[92mProcess added successfully.\033[0m\n";
                break;
            }

            case 2: {
                int id;
                std::cout << "\nEnter Process ID to Remove: ";
                std::cin >> id;
                Process dummyProcess(id, "", 0); 
                bool removed = taskManager.removeProcess(dummyProcess);
                if (removed) {
                    std::cout << "\033[92mProcess removed successfully.\033[0m\n";
                } else {
                    std::cout << "\033[91mNo process found with the given ID.\033[0m\n";
                }
                break;
            }

            case 3: {
                try {
                    Process nextProcess = taskManager.get_next_process();
                    std::cout << "\n\033[94m[Next Process in Queue]\033[0m\n";
                    std::cout << "ID: " << nextProcess.getId()
                              << ", Name: " << nextProcess.getName()
                              << ", Priority: " << nextProcess.getPriority() << "\n";
                } catch (const std::exception& e) {
                    std::cerr << "\033[91mError:\033[0m " << e.what() << std::endl;
                }
                break;
            }

            case 4: {
                taskManager.get_all_processes();
                break;
            }

            case 5: {
                std::cout << "\n\033[96mStarting Processes (sorted by priority):\033[0m\n";
                taskManager.start_processes();
                break;
            }

            case 6: {
                std::cout << "\033[92mExiting Task Manager. Goodbye!\033[0m\n";
                return 0;
            }

            default:
                std::cout << "\033[91mInvalid choice. Please try again.\033[0m\n";
        }
    }

    return 0;
}
