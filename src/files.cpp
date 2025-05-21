#include <iostream>
#include <fstream>
#include <vector>

#include "task.hpp"
#include "files.hpp"

void
save_to_file(std::vector<Task> tasks) {
	std::ofstream tasks_file(".tasks", std::ios::app); 

	for(Task t : tasks) {
		tasks_file << t.description << "\n";
	}

	tasks_file.close();
}
