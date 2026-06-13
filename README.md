<p align="center">
  <img src="icon/ttoBinary.png" alt="TTOBINARY Logo" width="140"/>
</p>

<h1 align="center">TTOBINARY</h1>

<p align="center">
  <b>Convert text into binary</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/version-v4.0.0-blue" alt="Version">
  <img src="https://img.shields.io/badge/license-GPLv3-green" alt="License">
</p>

---

## Overview

**TTOBINARY** is a lightweight utility designed to convert plain text into binary representation.  
It is built to be simple, fast, and easy to use for educational or technical purposes.


## Features

- Convert any text into binary format
- Fast and lightweight execution
- Simple and beginner-friendly usage
- Easily extendable for additional encoding formats


## Installation

### Prerequisites
Make sure you have a C compiler (`gcc`) and `make` configured in your environment.

### Building from Source
The `Makefile` automatically detects your operating system and builds the appropriate binary (including the application icon on Windows).

1. Clone the repository:
   ```bash
   git clone [https://github.com/S-havl/ttobinary.git](https://github.com/S-havl/ttobinary.git)
   cd ttobinary
   ```

2. Compile the project:
   - **On Linux:**
     ```bash
     make
     ```
   - **On Windows (MinGW / MSYS2):**
     ```bash
     mingw32-make
     ```


## Usage

Once compiled, run the generated executable directly from your terminal.

**On Linux:**
```bash
./ttoBinary
```

**On Windows:**
```cmd
ttoBinary.exe
```

### Interactive Example

When running the application, simply input your text and press `Enter`:

```text
Text: Hello World
0100100001100101011011000110110001101111
0101011101101111011100100110110001100100

-----------------------------------------------------------
Output File: message.txt (Generated automatically)
Stored in the same directory for external processing/reuse.
```
