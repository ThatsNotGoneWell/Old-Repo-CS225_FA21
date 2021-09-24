


## Score: 0/14 (0.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c exercises.cpp -o .objs/exercises.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/basic.cpp -o .objs/tests/basic.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/exercises.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/basic.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✗ - [0/1] - sumDigits

- **Points**: 0 / 1


```
Original: sumDigits(1) == 1
Expanded: -1 == 1
Original: sumDigits(243) == 9
Expanded: -1 == 9

```


### ✗ - [0/1] - triangle

- **Points**: 0 / 1


```
Original: triangle(0) == 0
Expanded: -1 == 0
Original: triangle(3) == 6
Expanded: -1 == 6

```


### ✗ - [0/3] - sum

- **Points**: 0 / 3


```
Original: QuackFun::sum(s) == 136
Expanded: 0 == 136

```


### ✗ - [0/3] - isBalanced

- **Points**: 0 / 3


```
Original: stack<char>::_CS225_ctor_count == 1
Expanded: 0 == 1
Original: QuackFun::isBalanced(stringToQueue(s)) == false
Expanded: true == false

```


### ✗ - [0/3] - scramble 17

- **Points**: 0 / 3


```
FAIL: See output above
```


### ✗ - [0/3] - scramble 9

- **Points**: 0 / 3


```
FAIL: See output above
```


---

This report was generated for **zekaiz2** using **402fa718bf7b792481ca53c3b0c306832f7f40e3** (latest commit as of **September 24th 2021, 9:36 am**)
