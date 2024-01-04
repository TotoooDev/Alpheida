# Alpheida 0.1.2

Alpheida is a game written entirely in C with minimal depedencies, for multiple platforms.

It is available on:
- Linux computers
- Switch

## Building

### Depedencies

Apart from the development environment, you'll need a few depedencies.

## Linux

- SDL2
- SDL2-image
- SDL2-mixer

## Switch

- SDL2
- SDL2-image
- SDL2-mixer

### Building the executable

You can use the Makefil to build the game, and specify the platform you want to build for: 
- `make` builds for Linux
- `make switch` builds for Switch

## Playing on Switch

Some scripts are provided to install and debug the game:
- `./scripts/switch_debug_netloader.sh` sends the homebrew via the netloader (press Y on the homebrew menu then execute the script).
- `./scripts/switch_install.sh` sends the homebrew via FTP (you need to have [sys-ftpd](https://github.com/cathery/sys-ftpd) installed or launch [ftpd-pro first](https://github.com/mtheall/ftpd)).

You can also manually copy the homebrew file (Alpheida.nro) yourself in the `switch` directory of your SD card.
