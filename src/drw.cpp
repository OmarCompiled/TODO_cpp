#include <iostream>
#include <vector>

#include "../include/task.hpp"

void
clr_screen() {
	std::cout << "\033[H\033[J";
}

void
draw(std::vector<Task> tasks) {
	clr_screen();

	std::cout << "Tasks:" << std::endl;

	for(Task t : tasks) {
		t.print();
	}

	std::cout << std::endl;
	std::cout << "Options:" << std::endl;
}
