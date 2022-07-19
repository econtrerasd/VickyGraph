# VickyGraph
Graphics Library for Foenix 256 Line of Computers (Foenix U/U+, FMX) 
The library has been designed for & compiled with Calypsi

https://www.calypsi.cc/

# INSTALLING

Please Download the whole ZIP file and uncompress it in your computer.
Provided that you already have Calypsi installed and configured you can compile the demo by typing the following command on the root directory:

make grfdemo.pgz 

The whole ZIP contains file is based on the “Hello World for c256U” provided by @hth313, so it already has the Foenix C256 board support
I gotta admit that I moved a few .h files to make it easier to compile my version, since I'm compiling in windows and some commands like change directory in the Makefile were just not working as expected.

The actual magic of this library resides in two files:

vickyGraph.h
vickyGraph.c

Those are the ones you need to add to your projects.
There is also a PDF manual for the library, it's still a work in progress but should get you up to speed on its usage.

DISCLAIMER: Every attempt has been made to release a bug free library and optimized as best of my abilities, but I'm sure something might be improved, bugs uncovered, etc.. Any suggestion / request is welcome as I intend on adding more stuff to this library to help people start using more their Foenix computers

# PORTING 
I believe it should be fairly easy to port this library for the 68000 based Foenix computers, but until I get one of those I have not made any effort to port this library, but feel free to give it a try
