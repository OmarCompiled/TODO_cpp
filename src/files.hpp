#ifndef FILES_HPP
#define FILES_HPP

void
save_to_file(std::vector<Task> tasks);

void
delete_from_file(std::vector<std::string> tasks);

std::vector<Task>
get_from_file();

#endif
