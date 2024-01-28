# Building the game

## Table of contents

- [Linux](#linux)
- [Nintendo Switch](#nintendo-switch)
- [Wii](#wii)

## Linux

### Dependencies

You will need to install a few dependencies (apart from the usual programs like git, gcc, ...).

To build the game you will need:

- SDL2
- SDL2-image
- SDL2-mixer

### Building

1. First, clone the repository and enter the folder named `alpheida`.

```bash
git clone https://github.com/TotoooDev/alpheida.git && cd alpheida
```

2. You can now build the game with `make`.
3. After the compilation is over, the final game is located in the `bin` directory. You can launch it with `./alpheida`.

## Nintendo Switch

### Dependencies

Apart from the [develoment environment](https://devkitpro.org/wiki/Getting_Started), you will need to install Glad:

```bash
sudo dkp-pacman -Syu switch-glad
```

### Building

1. First, clone the repository and enter the folder named `alpheida`.

```bash
git clone https://github.com/TotoooDev/alpheida.git && cd alpheida
```

2. You can now build the game.

```bash
make switch
```

3. After the compilation is over, the final hombrew is located in the `bin` directory, with a `.nro` extension.
4. There are three ways to play the game:
    - By putting the `.nro` file in your SD card by hand.
    - You can start the NetLoader by pressing Y on the Homebrew Menu, editing the `scripts/switch_debug_netloader.sh` file and replacing the IP adress by the one of your console and launching this command: `./scripts/switch_debug_netloader.sh`.
    - You can edit the `scripts/switch_install.sh` file and replacing the IP adress by the one of your console, launch an ftp homebrew (like [ftpd pro](https://github.com/mtheall/ftpd) or [sys-ftpd](https://github.com/cathery/sys-ftpd)) and lauching this command: `./scripts/switch_install.sh`.

## Wii

Comming soon...
