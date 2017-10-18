# Enigma
Simple simulation of an Enigma machine

## Install
To install and build the project, run the following commands:

```
git clone https://github.com/johnny90/enigma.git
cd enigma
make
```

To run the testsuite, in this directory run:

```
./tests.py
```

## Usage
The program can be used to encode a stream of capital letters from stdin by
providing configuration files for rotors and plugboard:

```
./enigma [FILES]
```

There are sample rotor configuration files in rotors/
and plugboard configuration files in plugboards/
