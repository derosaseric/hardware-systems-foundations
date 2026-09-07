# Bit Tools

Bit Tools is a command-line utility written in C for exploring
8-bit binary values and common bit manipulation operations.

## Features

- Display an 8-bit value in decimal and binary
- Inspect an individual bit
- Set a bit
- Clear a bit
- Toggle a bit
- Validate number, menu, and bit-position input

## Supported Range

Bit Tools currently operates on values from 0 through 255 and
bit positions 0 through 7.

## Build

From the repository root:

```bash
gcc -Wall -Wextra -Wpedantic \
    projects/bit-tools/src/main.c \
    -o projects/bit-tools/build/bit-tools
```

## Run

```bash
./projects/bit-tools/build/bit-tools
```

## Example

```text
Enter a number (0-255): 42
Choose an operation:
1. Inspect bit
2. Set bit
3. Clear bit
4. Toggle bit

Selection: 2

Enter bit position (0-7): 4

Original:
Decimal: 42
Binary: 00101010

Result:
Decimal: 58
Binary: 00111010
```

## Concepts Practiced
- Binary representation
- Bit positions and bit masks
- Bitwise AND, OR, XOR, and NOT
- Left and right shifts
- Functions
- Input validation
- `switch` statements
