#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "./include/task.hpp"
#include "./include/drw.hpp"

int
main(int argc, char ** argv)
{
	std::vector<Task> tasks;
	Task task1("Say Hello");
	Task task2("This is a test");

	tasks.push_back(task1);
	tasks.push_back(task2);
	
	while(true) {
		draw(tasks);
	}
}
