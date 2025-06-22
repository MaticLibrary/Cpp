#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Task {
    std::string name;
    int priority;
    bool completed;
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& name, int priority) {
        tasks.push_back({name, priority, false});
        std::cout << "Task added.\n";
    }

    void showAllTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks.\n";
            return;
        }
        auto sorted = tasks;
        std::sort(sorted.begin(), sorted.end(), [](const Task& a, const Task& b) {
            return a.priority > b.priority;
        });
        for (size_t i = 0; i < sorted.size(); ++i) {
            std::cout << i + 1 << ". [" << (sorted[i].completed ? 'X' : ' ') << "] "
                      << sorted[i].name << " (Priority: " << sorted[i].priority << ")\n";
        }
    }

    void markTaskDone(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid index.\n";
            return;
        }
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    }

    void deleteTask(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid index.\n";
            return;
        }
        tasks.erase(tasks.begin() + (index - 1));
        std::cout << "Task deleted.\n";
    }

    void showIncomplete() const {
        bool found = false;
        for (size_t i = 0; i < tasks.size(); ++i) {
            if (!tasks[i].completed) {
                std::cout << i + 1 << ". [ ] " << tasks[i].name
                          << " (Priority: " << tasks[i].priority << ")\n";
                found = true;
            }
        }
        if (!found) std::cout << "No incomplete tasks.\n";
    }
};

void menu() {
    TaskManager manager;
    int choice;
    std::string name;
    int priority, index;

    while (true) {
        std::cout << "\nMENU:\n"
                     "1. Add task\n"
                     "2. Show all tasks\n"
                     "3. Mark task as completed\n"
                     "4. Delete task\n"
                     "5. Show incomplete tasks\n"
                     "6. Exit\n"
                     "> Choose option: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Task name: ";
                std::getline(std::cin, name);
                std::cout << "Priority (1-10): ";
                std::cin >> priority;
                std::cin.ignore();
                manager.addTask(name, priority);
                break;
            case 2:
                manager.showAllTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> index;
                std::cin.ignore();
                manager.markTaskDone(index);
                break;
            case 4:
                std::cout << "Enter task number to delete: ";
                std::cin >> index;
                std::cin.ignore();
                manager.deleteTask(index);
                break;
            case 5:
                manager.showIncomplete();
                break;
            case 6:
                std::cout << "Program ended.\n";
                return;
            default:
                std::cout << "Invalid option.\n";
        }
    }
}

int main() {
    std::cout << "=== Task Manager CLI ===\n";
    menu();
    return 0;
}
