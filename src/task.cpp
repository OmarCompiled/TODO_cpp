#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "task.hpp"

Task::Task(const std::string description) : description(description), done(false) {}

void 
Task::print() {
	done == true ? 1 : printf("\033[91m");
	printf("-[%1c] ", (done == true ? ' ' : 'x'));
	printf("\033[0m");
	std::cout << description << std::endl;
}

void
Task::toggle_status() {
	done = (done == true ? false : true);
}

void
clear_screen() {
	std::cout << "\033[H\033[J";
}

void
draw(std::vector<Task> tasks, std::vector<std::string> options) {
	clear_screen();
	std::cout << "<== TODO ==>" << std::endl;
	for(Task task : tasks) {
		task.print();	
	}
	std::cout << "\nOptions:" << std::endl;
	for(int i = 0; i < options.size(); i++) {
		std::cout << i+1 << "- " << options[i] << std::endl;
	}
	std::cout << "-> ";
}
