# MIRAGE

![100% Human Code](https://img.shields.io/badge/Code-100%25_Human-9D4EDD?style=flat-square&labelColor=000000)
![Zero Vibe Coding](https://img.shields.io/badge/Vibe_Coding-Zero-9D4EDD?style=flat-square&labelColor=000000)
![100% Human Code](https://img.shields.io/badge/Engineering-Deliberate-9D4EDD?style=flat-square&labelColor=000000)
![Zero Vibe Coding](https://img.shields.io/badge/AI_Assistance-None-9D4EDD?style=flat-square&labelColor=000000)

**Current Version:** v5.0.1

MIRAGE is an offensive hacking framework covering all stages of the offensive methodology, written purely in C (Under development).

The focus of this project is to require absolutely zero dependencies, be easy to compile, easy to execute, and easy to use with just the necessary amount of abstractions to keep the user's workflow smooth, fast, and effective.

Every module created for this framework is designed to be 100% utilitarian and ergonomic, featuring a sleek minimalist aesthetic so that no tool or entered command is merely decorative. Absolutely everything serves a concrete, practical purpose.

>[!WARNING]
> This project is built for professional, ethical, and utilitarian use cases; any use intended to cause harm or unethically exploit systems is strictly prohibited and illegal.

## Output Example
```
╔════════════════════════════════════════════════════════════╗
║                                                            ║
║   ███╗   ███╗██╗██████╗  █████╗  ██████╗ ███████╗          ║
║   ████╗ ████║██║██╔══██╗██╔══██╗██╔════╝ ██╔════╝          ║
║   ██╔████╔██║██║██████╔╝███████║██║  ███╗█████╗            ║
║   ██║╚██╔╝██║██║██╔══██╗██╔══██║██║   ██║██╔══╝            ║
║   ██║ ╚═╝ ██║██║██║  ██║██║  ██║╚██████╔╝███████╗          ║
║   ╚═╝     ╚═╝╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝          ║
║                                                            ║
║   [*] Offensive Hacking Framework                          ║
║   [*] Loaded Modules: 1                                    ║           
╚════════════════════════════════════════════════════════════╝
mirage >
```

## Key Features
- A core built with a simple and direct state machine for the CLI interface.
- Basic commands alongside a help utility to inspect available commands at the root or within any module.
- Clean, efficient, and modular internal architecture allowing modules to be easily added or removed as needed.
- Modules completely decoupled from the core and interface, enabling each tool to be developed independently with only a single entry point function required.
- An initial ARP Man-in-the-Middle (MITM) attack module to test the complete framework workflow.

## Project Architecture
```
.
├── images/             # Test images, screenshots, etc.
├── include/            # Header files used in the source code
├── modules/            # Location of routes and modules
├── src/                # Framework source code
│   ├── console/        # Console-only utilities (SAC)
│   ├── core/           # Framework workflow core (State Machine)
│   └── modules/        # Module workflow core (Module registration)
├── LICENSE             # Project license
├── Makefile            # Project build automation
└── README.md           # Project documentation
```

## Prerequisites & Dependencies
- gcc
- make

## Build & Run
```
git clone https://github.com/S-havl/mirage.git
cd mirage
make clean && make
make run
```
>[!TIP]
> Once inside the interactive prompt, run `help` to inspect available commands at the root or within any active module.

# License

GNU General Public License v3.0
