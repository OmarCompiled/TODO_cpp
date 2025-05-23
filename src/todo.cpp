#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unistd.h>

#include "task.hpp"
#include "files.hpp"

void
tokenize(std::vector<std::string>* tokens, const std::string string) {
	std::stringstream stream(string);
	std::string temp;
	while(std::getline(stream, temp, ' ')) {
		tokens->push_back(temp);
	}
}

int
main(int argc, char* argv[]) {
	std::vector<Task> tasks;
	if(argc > 2 && !strcmp(argv[1], "add")) {
		for(int i = 2; i < argc; i++) {
			Task new_task(argv[i]);
			tasks.push_back(new_task);
		}
		save_to_file(tasks);
	} else if(argc > 2 && !strcmp(argv[1], "delete")) {
		std::vector<std::string> tasks_to_delete;
		for(int i = 2; i < argc; i++) {
			tasks_to_delete.push_back(argv[i]);
		}	
		delete_from_file(tasks_to_delete);
	} else {
		while(true) {		
			std::vector<std::string> options{"add", "delete", "exit"};
			tasks = get_from_file();
			
			draw(tasks, options);

			std::vector<std::string> tokens;
			std::string command;
			std::getline(std::cin, command);
			tokenize(&tokens, command);

			if(tokens[0] == "add") {
				std::cout << "add is still under construction!";
				fflush(stdout);
				sleep(1);
			} else if(tokens[0] == "delete") {
							
			} else if(tokens[0] == "cross") {
			
			} else if(tokens[0] == "exit") {
				exit(0);
			} else {
				std::cerr << "!! Unkown option: " << tokens[0];
				fflush(stdout);
				sleep(1);
			}
		}
	}

	return 0;
}	

