#ifndef TEST_H
#define TEST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ptread.h>
#include "cJSON.h"

#define MAXSTR 1024
#define MAXBUF 1024<<2

struct bots_config
{
  char user[MAXSTR];
  char cmd[MAXSTR];
  char bots[MAXSTR];
  int pthread;
};
struct bots_config config;
void init_config(struct bots_config* cnf );

#endif
