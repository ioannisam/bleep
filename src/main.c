#include "../include/utils.h"
#include "../include/audio.h"

#include <stddef.h>

int main(int argc, char* argv[]) {
  
  float frequency = 440.0;
  float duration  = 1000.0;
  float amplitude = 0.5;
  char* partiture = NULL;

  input(argc, argv, &frequency, &duration, &amplitude, &partiture);

  if (partiture) {
    read_score(partiture);
  } else {
    play_note(frequency, duration/1000.0, amplitude);
  }

  return 0;
}