#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#include "task.hpp"
#include "files.hpp"

int
main(int argc, char* argv[]) {
	std::vector<Task> tasks;
	if(argc > 2 && !strcmp(argv[1], "add")) {
		for(int i = 2; i < argc; i++) {
			Task new_task(argv[i]);
			tasks.push_back(new_task);
		}
		save_to_file(tasks);
		exit(0);
	} else {
		while(true) {
			std::vector<std::string> options{"add", "delete", "cross", "exit"};
			tasks = get_from_file();
			draw(tasks, options);
			getchar();
		}
	}
}	

