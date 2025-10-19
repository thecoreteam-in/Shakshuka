#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <vector>

class Database {
public:
    Database(const std::string &dbName);
    ~Database();

    bool initialize();
    bool createTables();
    bool insertTask(const std::string &task);
    bool updateTask(int taskId, const std::string &newTask);
    bool deleteTask(int taskId);
    std::string getTask(int taskId);
    std::vector<std::string> getAllTasks();

private:
    sqlite3 *db;
    std::string dbName;
};

#endif // DATABASE_H
