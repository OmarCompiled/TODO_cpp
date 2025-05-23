#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "task.hpp"

Task::Task(const std::string description) : description(description), done(false) {}

void 
Task::print() {
	printf("- ");
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
	printf("\033[92m");
	std::cout << "<== TODO ==>" << std::endl;
	printf("\033[0m");
	for(Task task : tasks) {
		task.print();	
	}
	std::cout << std::endl;
	printf("\033[92m");
	std::cout << "<== Options ==>" << std::endl;
	printf("\033[0m");
	for(std::string option : options) {
		printf("- ");
		std::cout << option << std::endl;
	}
	std::cout << "-> ";
}
