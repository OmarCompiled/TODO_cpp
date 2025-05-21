#include <iostream>
#include <stdio.h>
#include <string>

#include "task.hpp"

Task::Task(const std::string description) : description(description), done(false) {}

void 
Task::print() {
	done == true ? 1 : printf("\033[91m");
	printf("-[%1c] ", (done == true ? ' ' : 'x'));
	printf("\033[0m");
	std::cout << description << std::endl;
}

void Task::mark_complete() {
	done = true;
}
