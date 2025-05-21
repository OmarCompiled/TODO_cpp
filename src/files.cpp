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

std::vector<Task>
get_from_file() {
	std::ifstream tasks_file(".tasks");

	std::vector<Task> tasks;
	std::string task_descriptor;

	while(getline(tasks_file, task_descriptor)) {
		Task new_task(task_descriptor);
		tasks.push_back(new_task);
	}

	return tasks;
}
