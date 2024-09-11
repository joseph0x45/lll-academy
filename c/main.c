#include <stdbool.h>
#include <stdio.h>

#define MAX_EMPLOYEES

typedef struct __attribute__((__packed__)) {
  int id;
  char firstname[64];
  char lastname[64];
  float income;
  bool ismanager;
} packed_employee;

typedef struct {
  int id;
  char firstname[64];
  char lastname[64];
  float income;
  bool ismanager;
} non_packed_employee;

struct Employee {
  char name[100];
  int age;
};

int main() {

  struct Employee emp = {.age = 42, .name = "Steve"};

  printf("Size of not packed struct %lu\n", sizeof(non_packed_employee));
  printf("Size of packed struct %lu\n", sizeof(packed_employee));
  return 0;
}
