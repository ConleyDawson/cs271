// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
// The algorithm is based on repetitive addition.

// Multiplication: in the Hack computer,
// the top 16 RAM words (RAM[0]...RAM[15])
// are also referred to as RO...R15.

// With this terminology in mind, this
// program computes the value RO*R1 and
// stores the result in R2.

// The program assumes that R0>=0, R1>=0,
// and RO*R1<32768. Your program need not
// test these conditions, but rather assume
// that they hold.

// Initialize R2 to 0
@R2
M=0
// Jump to end if the second number is 0
@R1
D=M
@INFINITE_LOOP
D;JEQ
(ADD_NEXT)
// Load the new number into D
@R2
D=M
// Add the first number to D into D
@0
D=D+M
// Put it into R2
@R2
M=D
// Subtract the second number by 1
@R1
M=M-1
// If the second number > 0, repeat
D=M
@ADD_NEXT
D;JGT
(INFINITE_LOOP)
@INFINITE_LOOP
0;JMP
