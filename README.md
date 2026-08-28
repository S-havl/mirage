<p align="center">
  <img src="icon/mirage.png" alt="MIRAGE Logo" width="140"/>
</p>

<h1 align="center">MIRAGE</h1>

<p align="center">
  <b>Convert text into binary</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/version-v5.0.1-blue" alt="Version">
  <img src="https://img.shields.io/badge/license-GPLv3-green" alt="License">
</p>

---

## Overview

**MIRAGE** is a lightweight utility designed to convert plain text into binary representation.  
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
   git clone https://github.com/S-havl/mirage.git
   cd mirage
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
./mirage
```

**On Windows:**
```cmd
mirage.exe
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
