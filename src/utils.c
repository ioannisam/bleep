#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void input(int argc, char *argv[], float *frequency, float *duration, float *amplitude) {
  
  int opt;
  while ((opt = getopt(argc, argv, "f:d:a:")) != -1) {
    switch (opt) {
      case 'f':
        *frequency = atof(optarg);
        break;
      case 'd':
        *duration = atof(optarg);
        break;
      case 'a':
        *amplitude = atof(optarg);
        break;
      default:
        fprintf(stderr, "Usage: %s -f <frequency> -d <duration_ms> -a <amplitude>\n", argv[0]);
        exit(1);
    }
  }
}