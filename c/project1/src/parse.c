#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "common.h"
#include "parse.h"

#define CURRENT_VERSION 0x1

void list_employees(struct dbheader_t *header, struct employee_t *employees) {}

int add_employee(struct dbheader_t *header, struct employee_t *employees,
                 char *addstring) {}

int read_employees(int fd, struct dbheader_t *header,
                   struct employee_t **employeesOut) {}

int output_file(int fd, struct dbheader_t *header,
                struct employee_t *employees) {
  if (fd < 0) {
    printf("Invalid file descriptor\n");
    return STATUS_ERROR;
  }
  header->version = htons(header->version);
  header->count = htons(header->count);
  header->magic = htonl(header->magic);
  header->filesize = htonl(header->filesize);
  lseek(fd, 0, SEEK_SET);
  write(fd, header, sizeof(struct dbheader_t));

  return STATUS_SUCCESS;
}

int validate_db_header(int fd, struct dbheader_t **headerOut) {
  if (fd < 0) {
    printf("Got invalid file descriptor %d\n", fd);
    return STATUS_ERROR;
  }
  struct dbheader_t *header = calloc(1, sizeof(struct dbheader_t));
  if (header == NULL) {
    perror("calloc");
    return STATUS_ERROR;
  }
  if (read(fd, header, sizeof(struct dbheader_t)) !=
      sizeof(struct dbheader_t)) {
    perror("read");
    free(header);
    return STATUS_ERROR;
  }
  header->version = ntohs(header->version);
  header->count = ntohs(header->count);
  header->magic = ntohl(header->magic);
  header->filesize = ntohl(header->filesize);
  if (header->version != CURRENT_VERSION) {
    printf("Improper version: Found %d Expected %d\n", header->version,
           CURRENT_VERSION);
    free(header);
    return STATUS_ERROR;
  }
  if (header->magic != HEADER_MAGIC) {
    printf("Invalid magic number\n");
    free(header);
    return STATUS_ERROR;
  }
  struct stat db_stat = {0};
  if (fstat(fd, &db_stat) == -1) {
    perror("fstat");
    free(header);
    return STATUS_ERROR;
  }
  if (header->filesize != db_stat.st_size) {
    printf("Corrupted database\n");
    free(header);
    return STATUS_ERROR;
  }
  return STATUS_SUCCESS;
}

int create_db_header(int fd, struct dbheader_t **headerOut) {
  struct dbheader_t *header = calloc(1, sizeof(struct dbheader_t));
  if (header == NULL) {
    perror("calloc");
    return STATUS_ERROR;
  }
  header->version = CURRENT_VERSION;
  header->count = 0;
  header->magic = HEADER_MAGIC;
  header->filesize = sizeof(struct dbheader_t);
  *headerOut = header;
  return STATUS_SUCCESS;
}
