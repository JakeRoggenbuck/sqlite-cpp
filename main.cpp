#include <iostream>
#include <sqlite3.h>

int main(int argc, char** argv) {
	sqlite3* DB;
	int exit;

	exit = sqlite3_open("example.db", &DB);

	if (exit) {
		std::cerr << "Error opening DB " << sqlite3_errmsg(DB) << '\n';
		return -1;
	} else {
		std::cout << "Opened database successfully!" << '\n';
	}

	sqlite3_close(DB);
	return 0;
}
