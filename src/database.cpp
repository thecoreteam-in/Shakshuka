#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

class Database {
private:
    sqlite3 *db;

public:
    Database(const std::string &dbName) {
        if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
            std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        }
    }

    ~Database() {
        sqlite3_close(db);
    }

    void createTables() {
        const char *tasksTable = "CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY, name TEXT, completed BOOLEAN);");
        const char *schedulesTable = "CREATE TABLE IF NOT EXISTS schedules (id INTEGER PRIMARY KEY, task_id INTEGER, due_date TEXT, FOREIGN KEY(task_id) REFERENCES tasks(id));";

        char *errMsg;
        sqlite3_exec(db, tasksTable, nullptr, nullptr, &errMsg);
        if (errMsg) {
            std::cerr << "Error creating tasks table: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }

        sqlite3_exec(db, schedulesTable, nullptr, nullptr, &errMsg);
        if (errMsg) {
            std::cerr << "Error creating schedules table: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }

    void addTask(const std::string &name, bool completed) {
        std::string sql = "INSERT INTO tasks (name, completed) VALUES ('" + name + "', " + (completed ? "1" : "0") + ");";
        char *errMsg;
        sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
        if (errMsg) {
            std::cerr << "Error adding task: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }

    std::vector<std::string> getTasks() {
        std::vector<std::string> tasks;
        const char *sql = "SELECT * FROM tasks;";
        sqlite3_stmt *stmt;

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                tasks.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            }
        }
        sqlite3_finalize(stmt);
        return tasks;
    }

    void updateTask(int id, const std::string &name, bool completed) {
        std::string sql = "UPDATE tasks SET name = '" + name + "', completed = " + (completed ? "1" : "0") + " WHERE id = " + std::to_string(id) + ";";
        char *errMsg;
        sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
        if (errMsg) {
            std::cerr << "Error updating task: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }

    void deleteTask(int id) {
        std::string sql = "DELETE FROM tasks WHERE id = " + std::to_string(id) + ";";
        char *errMsg;
        sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
        if (errMsg) {
            std::cerr << "Error deleting task: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }
};

int main() {
    Database db("tasks.db");
    db.createTables();
    db.addTask("Example Task", false);
    auto tasks = db.getTasks();
    for (const auto &task : tasks) {
        std::cout << task << std::endl;
    }
    return 0;
}