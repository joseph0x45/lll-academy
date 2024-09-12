#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
  unsigned short version;
  unsigned short employees;
  unsigned int filesize;
} database_header_t;

int write_db(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 0;
  }
  int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
  if (fd == -1) {
    perror("open");
    return -1;
  }
  char *mydata = "Hello file\n";
  int written = write(fd, mydata, strlen(mydata));
  printf("Written %d bytes\n", written);
  close(fd);
  return 0;
}

int main(int argc, char *argv[]) {
  database_header_t head = {0};
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 0;
  }
  int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
  if (fd == -1) {
    perror("open");
    return -1;
  }

  if (read(fd, &head, sizeof(database_header_t)) != sizeof(database_header_t)) {
    perror("read");
    close(fd);
    return -1;
  };
  printf("Version %d\n", head.version);
  printf("Employees %d\n", head.employees);
  printf("Size %d\n", head.filesize);
  return 0;
}
