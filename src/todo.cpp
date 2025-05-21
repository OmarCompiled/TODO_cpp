#include <iostream>
#include <string>
#include <string.h>
#include <vector>

#include "task.hpp"
#include "files.hpp"

int
main(int argc, char* argv[]) {
	std::vector<Task> tasks;
	Task task1("hello");
	tasks.push_back(task1);
	save_to_file(tasks);
}
