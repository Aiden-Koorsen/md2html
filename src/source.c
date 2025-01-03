#include <source.h>
#include <stdio.h>
#include <sys/stat.h>

#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#else
#endif

project create_project(char *project_name) {
	project result;

	char buffer[400];
 
#ifdef __linux__
	getcwd(buffer, 400);
#elif _WIN32
	GetCurrentDirectory(400, buffer);
#else
#endif
		
	if (buffer != NULL && project_name != NULL) {
		result.project_path = malloc(strlen(buffer) + 1);
		strcpy(result.project_path, buffer);

		// Allocate new folder and name
		char *new_project_path = realloc(result.project_path, strlen(result.project_path) + strlen(project_name) + 3);

		if (new_project_path == NULL) {
			printf("Error -- Failed to allocate memory for project path");
			exit(-1);
		}
			
		result.project_path = new_project_path;
		
		strcat(result.project_path, "/");
		strcat(result.project_path, project_name);
		strcat(result.project_path, "/");
		result.project_path[strlen(result.project_path)] = '\0';

		if (result.project_path == NULL) {
			printf("Error -- Failed to allocate memory to project name\n");
			exit(-1);
		}
		
#ifdef __linux__
		mkdir(result.project_path, 0777);
#elif _WIN32
			mkdir(result.project_path);
#else
#endif

		result.dir_paths[0] = malloc(strlen(result.project_path) + strlen("/build/") + 1);
		result.dir_paths[1] = malloc(strlen(result.project_path) + strlen("/static/") + 1);
		result.dir_paths[2] = malloc(strlen(result.project_path) + strlen("/styles/") + 1);
		result.dir_paths[3] = malloc(strlen(result.project_path) + strlen("/pages/") + 1);
		result.dir_paths[4] = malloc(strlen(result.project_path) + strlen("/components/") + 1);

		if (result.dir_paths[0] != NULL) {
			strcpy(result.dir_paths[0], result.project_path);
			strcat(result.dir_paths[0], "/build/");
			result.dir_paths[0][strlen(result.dir_paths[0])] = '\0';
		}

		if (result.dir_paths[1] != NULL) {
			strcpy(result.dir_paths[1], result.project_path);
			strcat(result.dir_paths[1], "/static/");
			result.dir_paths[1][strlen(result.dir_paths[1])] = '\0';
		}

		if (result.dir_paths[2] != NULL) {
			strcpy(result.dir_paths[2], result.project_path);
			strcat(result.dir_paths[2], "/styles/");
			result.dir_paths[2][strlen(result.dir_paths[2])] = '\0';
		}

		if (result.dir_paths[3] != NULL) {
			strcpy(result.dir_paths[3], result.project_path);
			strcat(result.dir_paths[3], "/pages/");
			result.dir_paths[3][strlen(result.dir_paths[3])] = '\0';
		}

		if (result.dir_paths[4] != NULL) {
			strcpy(result.dir_paths[4], result.project_path);
			strcat(result.dir_paths[4], "/components/");
			result.dir_paths[4][strlen(result.dir_paths[4])] = '\0';
		}
		
		// Create all needed folders
#ifdef __linux__
			for (int i = 0; i < 4; i++)
				mkdir(result.dir_paths[i], 0777);
#elif _WIN32
		for (int i = 0; i < 4; i++)
			mkdir(result.dir_paths[i]);
#else
#endif
	}
	
	return result;
}

project load_project(char *project_path) {
	printf("Loading project\n");
	
	project result;

	result.project_path = malloc(strlen(project_path) + 1);
	strcpy(result.project_path, project_path);

	if (result.project_path != NULL) {
		result.dir_paths[0] = malloc(strlen(result.project_path) + strlen("/build/") + 1);
		result.dir_paths[1] = malloc(strlen(result.project_path) + strlen("/static/") + 1);
		result.dir_paths[2] = malloc(strlen(result.project_path) + strlen("/styles/") + 1);
		result.dir_paths[3] = malloc(strlen(result.project_path) + strlen("/pages/") + 1);
		result.dir_paths[4] = malloc(strlen(result.project_path) + strlen("/components/") + 1);

		if (result.dir_paths[0] != NULL) {
			strcpy(result.dir_paths[0], result.project_path);
			strcat(result.dir_paths[0], "/build/");
			result.dir_paths[0][strlen(result.dir_paths[0])] = '\0';
		}

		if (result.dir_paths[1] != NULL) {
			strcpy(result.dir_paths[1], result.project_path);
			strcat(result.dir_paths[1], "/static/");
			result.dir_paths[1][strlen(result.dir_paths[1])] = '\0';
		}

		if (result.dir_paths[2] != NULL) {
			strcpy(result.dir_paths[2], result.project_path);
			strcat(result.dir_paths[2], "/styles/");
			result.dir_paths[2][strlen(result.dir_paths[2])] = '\0';
		}

		if (result.dir_paths[3] != NULL) {
			strcpy(result.dir_paths[3], result.project_path);
			strcat(result.dir_paths[3], "/pages/");
			result.dir_paths[3][strlen(result.dir_paths[3])] = '\0';
		}

		if (result.dir_paths[4] != NULL) {
			strcpy(result.dir_paths[4], result.project_path);
			strcat(result.dir_paths[4], "/components/");
			result.dir_paths[4][strlen(result.dir_paths[4])] = '\0';
		}
	}

	for (int i = 0; i < 5; i++)
		printf("%s\n", result.dir_paths[i]);
	
	return result;
}

void unload_project(project *ptr_proj) {
	free(ptr_proj->project_path);
	
	for (int i = 0; i < 5; i++)
		free(ptr_proj->dir_paths[i]);
}
