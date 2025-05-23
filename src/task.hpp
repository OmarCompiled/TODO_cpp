#ifndef TASK_HPP
#define TASK_HPP

typedef struct Task {
	std::string description;
	bool done;

	Task(const std::string description);
	
	void
	print();

	void
	toggle_status();

} Task;

void
clear_screen();

void
draw(std::vector<Task> tasks, std::vector<std::string> options);

#endif
