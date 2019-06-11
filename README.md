# infix2postfix
This set of tools allows you to convert arithmetic expressions from computer-friendly postfix notation to human-friendly infix notation.

## Building
Simply run `make` and let a gcc compiler do all the magic.

## Usage
This tool comes with two apps. Both of them can be used in two ways. By passing one or more expressions as command-line arguments, or by using the standard input.

If you are passing expressions as command-line arguments, you're adviced to conclude them with single quotes `''` to prevent your shell from evaluating them.

If you are using the standard input, the program will terminated once it reads `EOF` signal.

Keep in mind, that none of these applications verify the input sanity. Passing incorrect arguments will result in undefined behaviour (most possibly a SIGSEGV).

### infix2postfix
Converts expressions from infix to postfix format.

Example of the usage in interactive mode:
**input:**
```
./infix2postfix
a+b
a+b^c
a*b/(c-d)^e
```
**output:**
```
ab+
abc^+
ab*cd-e^/
```

Example of usage with command-line arguments:
**input:**
```
./infix2postfix a+b '(b+a)*c' 'a/(b*(c-x))^d'
```
**output:**
```
ab+
ba+c*
abcx-*d^/
```

### postfix2infix
Converts expressions from postfix to infix format. Input methods are identical as above.

There will be additional, unnecessary brackets generated in an output. This serves a purpose that an output is always correct, since additional brackets does not actually change an expression outcome.

Example of usage in interactive mode:
**input:**
```
xy+
ab*cd+*e-
```
**output:**
```
(x+y)
(((a^b)*(c+d))-e)
```