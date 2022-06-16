#include <iostream>
#include <filesystem>
#include <sqlite3.h>

const std::string create_users_str =
    "CREATE TABLE USER("
    "UserId INT PRIMARY KEY	NOT NULL, "
    "Name TEXT				NOT NULL, "
    "Username TEXT			NOT NULL, "
    "Email TEXT				NOT NULL);";

const std::string create_tasks_str =
    "CREATE TABLE TASKS("
    "TaskId INT PRIMARY KEY	NOT NULL, "
    "Message TEXT		NOT NULL, "
    "UserId	INT			NOT NULL, "
    "FOREIGN KEY(UserId) REFERENCES USER(UserId));";

void create_table(sqlite3 *DB, std::string create_str) {
    int status;
    char *message_error;

    status = sqlite3_exec(DB, create_str.c_str(), NULL, 0, &message_error);

    if (status != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", message_error);
        sqlite3_free(message_error);
    } else {
        std::cout << "Table created Successfully" << '\n';
    }
}

void create_database(sqlite3 *DB) {
	create_table(DB, create_users_str);
	create_table(DB, create_tasks_str);
}

int main(int argc, char **argv) {
    sqlite3 *DB;
    int exit;

	std::filesystem::path f{"./example.db"};
	int existed = std::filesystem::exists(f);

    exit = sqlite3_open("example.db", &DB);

    if (exit) {
        std::cerr << "Error opening DB " << sqlite3_errmsg(DB) << '\n';
        return -1;
    } else {
        std::cout << "Opened database successfully!" << '\n';
    }

	if (!existed) {
		create_database(DB);
	}

    sqlite3_close(DB);
    return 0;
}
