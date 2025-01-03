#ifndef SOURCE_H
#define SOURCE_H

#include <string.h>
#include <stdlib.h>

typedef struct {
	char *path;
	int lines;
	char **lines_data;
	
	// Metadata elements
	char* title;
} mardown_file;

typedef struct {
	char *project_path;
	char *dir_paths[5];
} project;

project create_project(char *project_name);
project load_project(char *project_path);
void unload_project(project *ptr_proj);

#endif
