#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Task {
public:
    int id;
    std::string name;
    std::string project;
    int priority; // 1 = high, 2 = medium, 3 = low
    bool completed;

    Task(int id, const std::string& name, const std::string& project, int priority)
        : id(id), name(name), project(project), priority(priority), completed(false) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;
    int nextId;

public:
    TaskManager() : nextId(1) {
        // Initialize with sample data
        addTask("Complete project report", "ProjectA", 1);
        addTask("Update website", "ProjectB", 2);
        addTask("Prepare presentation", "ProjectA", 3);
    }

    void addTask(const std::string& name, const std::string& project, int priority) {
        tasks.emplace_back(nextId++, name, project, priority);
    }

    void displayTasks() {
        std::cout << std::setw(5) << "ID" << std::setw(30) << "Name" << std::setw(15) << "Project" 
                  << std::setw(10) << "Priority" << std::setw(10) << "Completed" << std::endl;
        for (const auto& task : tasks) {
            std::cout << std::setw(5) << task.id
                      << std::setw(30) << task.name
                      << std::setw(15) << task.project
                      << std::setw(10) << task.priority
                      << std::setw(10) << (task.completed ? "Yes" : "No") << std::endl;
        }
    }

    void updateTask(int id, const std::string& name, const std::string& project, int priority, bool completed) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.name = name;
                task.project = project;
                task.priority = priority;
                task.completed = completed;
                break;
            }
        }
    }

    void deleteTask(int id) {
        tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [id](const Task& task) {
            return task.id == id;
        }), tasks.end());
    }

    void filterTasksByPriority(int priority) {
        for (const auto& task : tasks) {
            if (task.priority == priority) {
                std::cout << task.id << " - " << task.name << std::endl;
            }
        }
    }

    void filterTasksByProject(const std::string& project) {
        for (const auto& task : tasks) {
            if (task.project == project) {
                std::cout << task.id << " - " << task.name << std::endl;
            }
        }
    }
};

int main() {
    TaskManager manager;

    std::cout << "Initial task list:" << std::endl;
    manager.displayTasks();

    std::cout << "\nAdding a new task..." << std::endl;
    manager.addTask("New task example", "ProjectC", 2);
    manager.displayTasks();

    std::cout << "\nUpdating task with ID 1..." << std::endl;
    manager.updateTask(1, "Updated project report", "ProjectA", 1, false);
    manager.displayTasks();

    std::cout << "\nDeleting task with ID 2..." << std::endl;
    manager.deleteTask(2);
    manager.displayTasks();

    std::cout << "\nFiltering tasks by priority 1:" << std::endl;
    manager.filterTasksByPriority(1);

    std::cout << "\nFiltering tasks by project 'ProjectA':" << std::endl;
    manager.filterTasksByProject("ProjectA");

    return 0;
}