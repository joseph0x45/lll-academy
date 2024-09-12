#include <fcntl.h>
#include <stdio.h>

int main() {
  int fd = open("./something", O_RDONLY);
  if (fd == -1) {
    perror("open");
    return -1;
  }
}
