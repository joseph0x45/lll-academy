#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"
#include "file.h"
#include "parse.h"

void print_usage(char *argv[]) {
  printf("Usage: %s -n -f <database file>\n", argv[0]);
  printf("\t -n - create new database file\n");
  printf("\t -f - (required) path to database file\n");
  return;
}

int main(int argc, char *argv[]) {
  bool new_file = false;
  char *file_path = NULL;
  int c;
  int db_fd = -1;
  struct dbheader_t *header = NULL;
  while ((c = getopt(argc, argv, "nf:")) != -1) {
    switch (c) {
    case 'n':
      new_file = true;
      break;
    case 'f':
      file_path = optarg;
      break;
    case '?':
      printf("Unknown argument: %c\n", c);
      break;
    default:
      return -1;
    }
  }

  if (file_path == NULL) {
    printf("No file path was specified\n");
    print_usage(argv);
    return -1;
  }

  if (new_file) {
    db_fd = create_db_file(file_path);
    if (db_fd == STATUS_ERROR) {
      printf("Unable to create database file\n");
      close(db_fd);
      return -1;
    }
    if (create_db_header(db_fd, &header) == STATUS_ERROR) {
      printf("Failed to create database header\n");
      close(db_fd);
      free(header);
      return -1;
    }
    if (output_file(db_fd, header, NULL) == STATUS_ERROR) {
      printf("Failed to write database header\n");
      free(header);
      close(db_fd);
      return -1;
    }
  } else {
    db_fd = open_db_file(file_path);
    if (db_fd == STATUS_ERROR) {
      printf("Unable to open database file\n");
      return -1;
    }
    if (validate_db_header(db_fd, &header) == STATUS_ERROR) {
      printf("Invalid database header\n");
      close(db_fd);
      return -1;
    }
  }

  printf("New file: %d\n", new_file);
  printf("Filepath: %s\n", file_path);
  return 0;
}
