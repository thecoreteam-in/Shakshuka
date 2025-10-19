#ifndef AUTOSAVE_H
#define AUTOSAVE_H

#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <iostream>

class AutoSave {
public:
    AutoSave(int interval = 30) : saveInterval(interval), isRunning(false) {}

    void start() {
        isRunning = true;
        saveThread = std::thread(&AutoSave::autoSaveRoutine, this);
    }

    void stop() {
        isRunning = false;
        if (saveThread.joinable()) {
            saveThread.join();
        }
    }

    void createBackup() {
        // Code to create a backup
        std::cout << "Backup created." << std::endl;
        backups.push_back("backup_" + std::to_string(backups.size() + 1));
    }

    void restoreBackup(int index) {
        if (index >= 0 && index < backups.size()) {
            // Code to restore a specific backup
            std::cout << "Restored backup: " << backups[index] << std::endl;
        } else {
            std::cout << "Invalid backup index." << std::endl;
        }
    }

    void listBackups() const {
        std::cout << "List of backups:" << std::endl;
        for (const auto& backup : backups) {
            std::cout << backup << std::endl;
        }
    }

    std::string status() const {
        return isRunning ? "AutoSave is running." : "AutoSave is stopped.";
    }

private:
    int saveInterval;
    bool isRunning;
    std::thread saveThread;
    std::vector<std::string> backups;

    void autoSaveRoutine() {
        while (isRunning) {
            createBackup();
            std::this_thread::sleep_for(std::chrono::seconds(saveInterval));
        }
    }
};

#endif // AUTOSAVE_H
