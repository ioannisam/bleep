# Bleep CLI

**Author**: Ioannis Michalainas

**Date**: January 2025

## Description
This project program plays a single sine note using the *ALSA* library. Inspired by the *beep* command-line utility.

## Prerequisites

To compile and run this program, you will need:
- A C compiler (e.g., `gcc`)
- Make
- The ALSA library (`libasound2-dev` on Debian-based systems)

## Installation

1. Clone this repo

```bash
git clone https://github.com/ioannisam/bleep.git
```
2. Navigate to the project

```bash
cd bleep
```

3. Compile the project

```bash
make
```

3. Run the binary

```bash
./bin/bleep -f {f} -d {d} -a {a}
```

Where **{f}** is the frequency of the note in Hz, **{d}** the duration in milliseconds and **{a}** the amplitude in the range [0..1].

### Example

To play a *440 Hz* note for *1000 milliseconds* with an amplitude of *0.5*:

```bash
./bin/bleep -f 440 -d 1000 -a 0.5
```

### Default Values

If no command-line arguments are provided, the program will use the following default values:
- Frequency: 440 Hz
- Duration: 1000 milliseconds
- Amplitude: 0.5

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.