#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unistd.h>

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

void
delete_from_file(std::vector<std::string> tasks) {
	std::vector<std::string> temp;
	std::ifstream tasks_file_read(".tasks");
	std::string task_descriptor;
	while(getline(tasks_file_read, task_descriptor)) {
		temp.push_back(task_descriptor);
	}
	tasks_file_read.close();	
	for(std::string name : tasks) {
		auto task = std::find(temp.begin(), temp.end(), name);
		if(task != temp.end()){
			temp.erase(task);
		} else {
			std::cerr << "This task does not exist." << std::endl;
			fflush(stdout);
			sleep(1);
		}
	}
	remove(".tasks");
	std::ofstream tasks_file_write(".tasks", std::ios::app);
	for(std::string task : temp) {
		tasks_file_write << task << "\n";
	}
	tasks_file_write.close();
}
