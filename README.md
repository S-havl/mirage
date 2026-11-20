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

## Contributing

The primary way to contribute to Mirage is by developing modules for the framework in accordance with this guide.

Mirage is built around four core principles: zero external dependencies, minimalism, complete functionality, and ergonomics. All contributed modules must align with this philosophy and maintain consistency across the codebase.

> Authorized Use Notice: Mirage is intended for security research, network diagnostics, and authorized testing environments. Only run or test modules against systems and networks you own or have explicit permission to assess.

### Requirements and Environment

To keep the framework self-contained and free of external dependencies, Mirage relies on standard Linux build tooling:

- `gcc`: C compiler used to build the framework and its modules.
- `make`: Build automation tool used to compile the project and apply formatting rules.
- Linux environment: Mirage targets Linux natively. Cross-compilation for Windows is not currently implemented, though contributions adding cross-compilation support or Windows-compatible modules are welcome.

### Code Style and Conventions

- Formatting: You may design your module's internal engineering and architecture as you see fit, provided you run `make format` before finishing so your code matches the repository's formatting standard.
- Code hygiene: Avoid compiler warnings, validate system and socket calls, and clean up allocated resources or file descriptors on both success and error paths.
- Console colors: CLI and TUI output must use the color definitions in `include/console/console.h` so every module remains visually consistent with the rest of Mirage.
- Log prefixes: Standard output and status messages must strictly use these prefixes:
  - `[*]`: Info / status
  - `[+]`: Success
  - `[-]`: Error / failure
  - `[!]`: Warning / alert
  - `[?]`: Prompt / question
- Entry point: You are free to organize your module directory—including local documentation or helper files—as long as the module's entry-point function is not named `main` and takes `void` while returning `void`.

### Module Layout

Place your module under `modules/` using the following directory structure:
```
modules/
└── <category>/
    └── <subcategory>/
        └── <module_name>/
            └── <module_source>.c
```

Example:

modules/net/spoof/arp_mitm/arp_mitm.c

### Registering Your Module

To expose your module within Mirage, declare its entry-point function and register it in `src/modules/modules.c`:
```c
// In src/modules/modules.c
// Declare the module entry point with `extern` (must take `void` and return `void`).
extern void arp_mitm(void);

static module_descriptor_t registered_modules[] = {
    {
        .module_name = "net/spoof/arp_mitm",
        .module_function = arp_mitm
    }
};
```

### Workflow and Pre-Submission Checklist

1. Create a focused branch from the main development branch for your feature or fix.
2. Implement the module following Mirage's conventions and keep commits clear and scoped.
3. Run `make format` and verify that the project builds cleanly with `make`.
4. Submit a Pull Request explaining what the module does, how you tested it, and any limitations.

Quick checklist before submitting:
- [ ] No external dependencies added.
- [ ] Placed under `modules/<category>/<subcategory>/<module_name>/` with a non-`main` `void fn(void)` entry point.
- [ ] Registered in `src/modules/modules.c` and compiled with `make`.
- [ ] Formatted with `make format` with clean resource handling.
- [ ] Uses `include/console/console.h` colors and `[*]`, `[+]`, `[-]`, `[!]`, `[?]` log prefixes.

# License

GNU General Public License v3.0
