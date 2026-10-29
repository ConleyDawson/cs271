// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

// I/O handling: this program illustrates
// low-level handling of the screen and
// keyboard devices, as follows.

// The program runs an infinite loop that
// listens to the keyboard input. When a key
// is pressed (any key), the program
// blackens the screen, i.e. writes “black” in
// every pixel; the screen should remain
// fully black as long as the key is pressed.
// When no key is pressed, the program
// clears the screen, i.e. writes "white" in
// every pixel; the screen should remain
// fully clear as long as no key is pressed.
// Implementation note: your program may
// blacken and clear the screen's pixels in
// any spatial/visual order, as long as
// pressing a key continuously for long
// enough results in a fully blackened
// screen, and not pressing any key for long
// enough results in a fully cleared screen.

// Store the address in the screen we are working on in R0
@SCREEN
D=A
@R0
M=D

// Main program loop
(PROGRAM_LOOP)
// Get the keyboard
@KBD
D=M

// Check keyboard
@KBD
D=M
// If no key is pressed (value = 0), draw white
@DRAW_WHITE
D;JEQ

// otherwise draw black
@R0
A=M
M=-1

// then continue
@CONTINUE
0;JMP

(DRAW_WHITE)
// Draw white
@R0
A=M
M=0

(CONTINUE)
// Move to next section of screen
@R0
M=M+1

// make sure we aren't outside the screen range
// Get our current position
@R0
D=M
// Store it in R1
@R1
M=D
// Get the keyboard address
@KBD
D=A
// Get the difference
@R1
D=M-D
// If not 0, loop again
@PROGRAM_LOOP
D;JNE

// otherwise reset to start of screen
@SCREEN
D=A
@R0
M=D

@PROGRAM_LOOP
0;JMP