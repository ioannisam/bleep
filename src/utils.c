#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void input(int argc, char* argv[], float* frequency, float* duration, float* amplitude, char** partiture) {
  
  int opt;
  int partiture_flag = 0;
  static struct option long_options[] = {
    {"partiture", required_argument, 0, 'p'},
    {0, 0, 0, 0}
  };

  while ((opt = getopt_long(argc, argv, "f:d:a:p:", long_options, NULL)) != -1) {
    switch (opt) {
      case 'f':
        if (partiture_flag) {
          fprintf(stderr, "Error: -p or --partiture flag is exclusive and cannot be used with other flags.\n");
          exit(1);
        }
        *frequency = atof(optarg);
        break;
      case 'd':
        if (partiture_flag) {
          fprintf(stderr, "Error: -p or --partiture flag is exclusive and cannot be used with other flags.\n");
          exit(1);
        }
        *duration = atof(optarg);
        break;
      case 'a':
        if (partiture_flag) {
          fprintf(stderr, "Error: -p or --partiture flag is exclusive and cannot be used with other flags.\n");
          exit(1);
        }
        *amplitude = atof(optarg);
        break;
      case 'p':
        if (*frequency != 440.0 || *duration != 1000.0 || *amplitude != 0.5) {
          fprintf(stderr, "Error: -p or --partiture flag is exclusive and cannot be used with other flags.\n");
          exit(1);
        }
        *partiture = optarg;
        partiture_flag = 1;
        break;
      default:
        fprintf(stderr, "Usage: %s -f <frequency> -d <duration_ms> -a <amplitude> [--partiture <file>]\n", argv[0]);
        exit(1);
    }
  }
}