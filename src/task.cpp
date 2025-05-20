#include <iostream>
#include <stdio.h>

#include "../include/task.hpp"

Task::Task(const std::string description) : description(description), done(false), status(' ') {}

void
Task::print() {
	printf("-[%1c] ", status);
	std::cout << description << std::endl;
}

