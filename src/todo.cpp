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
  } else if(argc == 2 && !strcmp(argv[1], "list")) {
    tasks = get_from_file();
    std::cout << std::endl;
    for(Task task : tasks) {
      task.print();
    }
    std::cout << std::endl;
  }	else if(argc == 1) {
    while(true) {		
      std::vector<std::string> options{"add", "delete", "exit"};
      tasks = get_from_file();
      
      draw(tasks, options);
      
      std::vector<std::string> tokens;
      std::string command;
      std::getline(std::cin, command);
      tokenize(&tokens, command);
      
      bool not_singleton = tokens.size() > 1;
      if(tokens[0] == "add" && not_singleton) {
	std::string new_tasks_description = "";
	for(int i = 1; i < tokens.size(); i++) {
	  new_tasks_description += tokens[i];
	  if(i != tokens.size() - 1) {
	    new_tasks_description += " ";
	  }
	}
	Task new_task(new_tasks_description);
	tasks = {new_task};
	save_to_file(tasks);
      } else if(tokens[0] == "delete" && not_singleton) {
	std::string deleted_task_description = "";
	std::vector<std::string> deleted_task;
	for(int i = 1; i < tokens.size(); i++) {
	  deleted_task_description += tokens[i];
	  if(i != tokens.size() - 1) {
	    deleted_task_description += " ";
	  }
	}
	deleted_task = {deleted_task_description};
	delete_from_file(deleted_task);
      } else if(tokens[0] == "delete" && !not_singleton) {
	remove(".tasks");
	tasks = {};
	
	
	save_to_file(tasks);
      }	else if(tokens[0] == "exit") {
	exit(0);
      } else {
	std::cerr << "!! Unkown option: " << tokens[0];
	fflush(stdout);
	sleep(1);
      }
    }
  } else {
    std::cerr << "!! Unkown option: " << argv[1] << std::endl;
    fflush(stdout);
		sleep(1);
  }
  
  return 0;
}	

