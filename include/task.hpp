#ifndef TASK_HPP
#define TASK_HPP

#include <string>

typedef struct Task {
	std::string description;
	bool done;
	char status;

	Task(const std::string description);
	void print();

} Task;

#endif
