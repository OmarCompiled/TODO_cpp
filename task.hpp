#ifndef TASK_HPP
#define TASK_HPP

typedef struct Task {
	std::string description;
	bool done;

	Task(const std::string description);
	
	void
	print();

	void
	mark_complete();

} Task;

#endif
