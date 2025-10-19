#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

struct Task {
    int id;
    std::string title;
    std::string description;
    int priority;
    std::string project;
    std::time_t dueDate;
    int duration;
    std::string status;
    std::time_t timestamps;
    int strikeCount;
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    // Create
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    // Read
    std::vector<Task> getTasks() const {
        return tasks;
    }

    // Update
    void updateTask(int id, const Task& updatedTask) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task = updatedTask;
                break;
            }
        }
    }

    // Delete
    void deleteTask(int id) {
        tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [id](const Task& task) {
            return task.id == id;
        }), tasks.end());
    }

    // Filter by priority
    std::vector<Task> filterByPriority(int priority) const {
        std::vector<Task> filteredTasks;
        for (const auto& task : tasks) {
            if (task.priority == priority) {
                filteredTasks.push_back(task);
            }
        }
        return filteredTasks;
    }

    // Filter by project
    std::vector<Task> filterByProject(const std::string& project) const {
        std::vector<Task> filteredTasks;
        for (const auto& task : tasks) {
            if (task.project == project) {
                filteredTasks.push_back(task);
            }
        }
        return filteredTasks;
    }

    // Filter by status
    std::vector<Task> filterByStatus(const std::string& status) const {
        std::vector<Task> filteredTasks;
        for (const auto& task : tasks) {
            if (task.status == status) {
                filteredTasks.push_back(task);
            }
        }
        return filteredTasks;
    }

    // Sort tasks by dueDate
    void sortByDueDate() {
        std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.dueDate < b.dueDate;
        });
    }
};
