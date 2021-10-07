---

This report was generated for **zekaiz2** using **422b57d9036bc434bd86d43be898e4e5ebfed09d** (latest commit as of **October 4th 2021, 11:59 pm**)

---




## Score: 125/126 (99.21%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part2.cpp -o .objs/tests/tests_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1.cpp -o .objs/tests/tests_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part2_extra.cpp -o .objs/tests/test_part2_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1_extra.cpp -o .objs/tests/tests_part1_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests_part2.o .objs/tests/tests_part1.o .objs/tests/test_part2_extra.o .objs/tests/tests_part1_extra.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [5/5] - List::reverse

- **Points**: 5 / 5





### ✓ - [5/5] - List::reverseNth #1

- **Points**: 5 / 5





### ✓ - [5/5] - List::reverseNth #2

- **Points**: 5 / 5





### ✓ - [10/10] - List::merge

- **Points**: 10 / 10

```
==95== Memcheck, a memory error detector
==95== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==95== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==95== Command: ./test -r xml "List::merge"
==95== 
==95== 
==95== HEAP SUMMARY:
==95==     in use at exit: 16 bytes in 1 blocks
==95==   total heap usage: 243,424 allocs, 243,423 frees, 79,522,321 bytes allocated
==95== 
==95== LEAK SUMMARY:
==95==    definitely lost: 0 bytes in 0 blocks
==95==    indirectly lost: 0 bytes in 0 blocks
==95==      possibly lost: 0 bytes in 0 blocks
==95==    still reachable: 16 bytes in 1 blocks
==95==         suppressed: 0 bytes in 0 blocks
==95== Reachable blocks (those to which a pointer was found) are not shown.
==95== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==95== 
==95== For counts of detected and suppressed errors, rerun with: -v
==95== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #1

- **Points**: 2 / 2

```
==97== Memcheck, a memory error detector
==97== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==97== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==97== Command: ./test -r xml "List::sort\ simple\ #1"
==97== 
==97== 
==97== HEAP SUMMARY:
==97==     in use at exit: 0 bytes in 0 blocks
==97==   total heap usage: 2,317 allocs, 2,317 frees, 281,032 bytes allocated
==97== 
==97== All heap blocks were freed -- no leaks are possible
==97== 
==97== For counts of detected and suppressed errors, rerun with: -v
==97== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #2

- **Points**: 2 / 2

```
==99== Memcheck, a memory error detector
==99== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==99== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==99== Command: ./test -r xml "List::sort\ simple\ #2"
==99== 
==99== 
==99== HEAP SUMMARY:
==99==     in use at exit: 0 bytes in 0 blocks
==99==   total heap usage: 2,317 allocs, 2,317 frees, 281,080 bytes allocated
==99== 
==99== All heap blocks were freed -- no leaks are possible
==99== 
==99== For counts of detected and suppressed errors, rerun with: -v
==99== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::sort #1

- **Points**: 5 / 5





### ✓ - [5/5] - List::sort #2

- **Points**: 5 / 5





### ✓ - [1/1] - List::insertFront size

- **Points**: 1 / 1

```
==103== Memcheck, a memory error detector
==103== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==103== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==103== Command: ./test -r xml "List::insertFront\ size"
==103== 
==103== 
==103== HEAP SUMMARY:
==103==     in use at exit: 0 bytes in 0 blocks
==103==   total heap usage: 2,462 allocs, 2,462 frees, 285,632 bytes allocated
==103== 
==103== All heap blocks were freed -- no leaks are possible
==103== 
==103== For counts of detected and suppressed errors, rerun with: -v
==103== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::insertBack size

- **Points**: 2 / 2

```
==105== Memcheck, a memory error detector
==105== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==105== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==105== Command: ./test -r xml "List::insertBack\ size"
==105== 
==105== 
==105== HEAP SUMMARY:
==105==     in use at exit: 0 bytes in 0 blocks
==105==   total heap usage: 2,462 allocs, 2,462 frees, 285,632 bytes allocated
==105== 
==105== All heap blocks were freed -- no leaks are possible
==105== 
==105== For counts of detected and suppressed errors, rerun with: -v
==105== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents

- **Points**: 4 / 4

```
==107== Memcheck, a memory error detector
==107== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==107== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==107== Command: ./test -r xml "List::insert\ contents"
==107== 
==107== 
==107== HEAP SUMMARY:
==107==     in use at exit: 0 bytes in 0 blocks
==107==   total heap usage: 2,458 allocs, 2,458 frees, 285,536 bytes allocated
==107== 
==107== All heap blocks were freed -- no leaks are possible
==107== 
==107== For counts of detected and suppressed errors, rerun with: -v
==107== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::triplerotate basic

- **Points**: 5 / 5

```
==109== Memcheck, a memory error detector
==109== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==109== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==109== Command: ./test -r xml "List::triplerotate\ basic"
==109== 
==109== 
==109== HEAP SUMMARY:
==109==     in use at exit: 0 bytes in 0 blocks
==109==   total heap usage: 2,466 allocs, 2,466 frees, 285,824 bytes allocated
==109== 
==109== All heap blocks were freed -- no leaks are possible
==109== 
==109== For counts of detected and suppressed errors, rerun with: -v
==109== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - List::triplerotate simple

- **Points**: 10 / 10

```
==111== Memcheck, a memory error detector
==111== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==111== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==111== Command: ./test -r xml "List::triplerotate\ simple"
==111== 
==111== 
==111== HEAP SUMMARY:
==111==     in use at exit: 0 bytes in 0 blocks
==111==   total heap usage: 2,470 allocs, 2,470 frees, 285,920 bytes allocated
==111== 
==111== All heap blocks were freed -- no leaks are possible
==111== 
==111== For counts of detected and suppressed errors, rerun with: -v
==111== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split simple

- **Points**: 5 / 5

```
==113== Memcheck, a memory error detector
==113== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==113== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==113== Command: ./test -r xml "List::split\ simple"
==113== 
==113== 
==113== HEAP SUMMARY:
==113==     in use at exit: 0 bytes in 0 blocks
==113==   total heap usage: 2,320 allocs, 2,320 frees, 281,104 bytes allocated
==113== 
==113== All heap blocks were freed -- no leaks are possible
==113== 
==113== For counts of detected and suppressed errors, rerun with: -v
==113== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split images

- **Points**: 5 / 5





### ✓ - [3/3] - List::_destroy empty list

- **Points**: 3 / 3

```
==116== Memcheck, a memory error detector
==116== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==116== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==116== Command: ./test -r xml "List::_destroy\ empty\ list"
==116== 
==116== 
==116== HEAP SUMMARY:
==116==     in use at exit: 0 bytes in 0 blocks
==116==   total heap usage: 2,470 allocs, 2,470 frees, 286,464 bytes allocated
==116== 
==116== All heap blocks were freed -- no leaks are possible
==116== 
==116== For counts of detected and suppressed errors, rerun with: -v
==116== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::begin() returns an iterator to the front of the list

- **Points**: 1 / 1

```
==118== Memcheck, a memory error detector
==118== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==118== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==118== Command: ./test -r xml "List::begin()\ returns\ an\ iterator\ to\ the\ front\ of\ the\ list"
==118== 
==118== 
==118== HEAP SUMMARY:
==118==     in use at exit: 0 bytes in 0 blocks
==118==   total heap usage: 2,474 allocs, 2,474 frees, 290,800 bytes allocated
==118== 
==118== All heap blocks were freed -- no leaks are possible
==118== 
==118== For counts of detected and suppressed errors, rerun with: -v
==118== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (pre-increment)

- **Points**: 1 / 1

```
==120== Memcheck, a memory error detector
==120== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==120== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==120== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (pre-increment)"
==120== 
==120== 
==120== HEAP SUMMARY:
==120==     in use at exit: 0 bytes in 0 blocks
==120==   total heap usage: 2,474 allocs, 2,474 frees, 293,200 bytes allocated
==120== 
==120== All heap blocks were freed -- no leaks are possible
==120== 
==120== For counts of detected and suppressed errors, rerun with: -v
==120== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (post-increment)

- **Points**: 1 / 1

```
==122== Memcheck, a memory error detector
==122== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==122== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==122== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (post-increment)"
==122== 
==122== 
==122== HEAP SUMMARY:
==122==     in use at exit: 0 bytes in 0 blocks
==122==   total heap usage: 2,474 allocs, 2,474 frees, 293,200 bytes allocated
==122== 
==122== All heap blocks were freed -- no leaks are possible
==122== 
==122== For counts of detected and suppressed errors, rerun with: -v
==122== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==124== Memcheck, a memory error detector
==124== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==124== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==124== Command: ./test -r xml "List::ListIterator::operator++\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==124== 
==124== 
==124== HEAP SUMMARY:
==124==     in use at exit: 0 bytes in 0 blocks
==124==   total heap usage: 2,474 allocs, 2,474 frees, 295,600 bytes allocated
==124== 
==124== All heap blocks were freed -- no leaks are possible
==124== 
==124== For counts of detected and suppressed errors, rerun with: -v
==124== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- moves the iterator backwards

- **Points**: 1 / 1

```
==126== Memcheck, a memory error detector
==126== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==126== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==126== Command: ./test -r xml "List::ListIterator::operator--\ moves\ the\ iterator\ backwards"
==126== 
==126== 
==126== HEAP SUMMARY:
==126==     in use at exit: 0 bytes in 0 blocks
==126==   total heap usage: 2,474 allocs, 2,474 frees, 290,800 bytes allocated
==126== 
==126== All heap blocks were freed -- no leaks are possible
==126== 
==126== For counts of detected and suppressed errors, rerun with: -v
==126== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==128== Memcheck, a memory error detector
==128== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==128== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==128== Command: ./test -r xml "List::ListIterator::operator--\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==128== 
==128== 
==128== HEAP SUMMARY:
==128==     in use at exit: 0 bytes in 0 blocks
==128==   total heap usage: 2,474 allocs, 2,474 frees, 295,600 bytes allocated
==128== 
==128== All heap blocks were freed -- no leaks are possible
==128== 
==128== For counts of detected and suppressed errors, rerun with: -v
==128== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is reached

- **Points**: 1 / 1

```
==130== Memcheck, a memory error detector
==130== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==130== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==130== Command: ./test -r xml "List::ListIterator::end\ is\ reached"
==130== 
==130== 
==130== HEAP SUMMARY:
==130==     in use at exit: 0 bytes in 0 blocks
==130==   total heap usage: 2,467 allocs, 2,467 frees, 288,232 bytes allocated
==130== 
==130== All heap blocks were freed -- no leaks are possible
==130== 
==130== For counts of detected and suppressed errors, rerun with: -v
==130== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is not ::begin in a non-empty list

- **Points**: 1 / 1

```
==132== Memcheck, a memory error detector
==132== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==132== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==132== Command: ./test -r xml "List::ListIterator::end\ is\ not\ ::begin\ in\ a\ non-empty\ list"
==132== 
==132== 
==132== HEAP SUMMARY:
==132==     in use at exit: 0 bytes in 0 blocks
==132==   total heap usage: 2,467 allocs, 2,467 frees, 290,632 bytes allocated
==132== 
==132== All heap blocks were freed -- no leaks are possible
==132== 
==132== For counts of detected and suppressed errors, rerun with: -v
==132== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::reverse simple

- **Points**: 4 / 4

```
==134== Memcheck, a memory error detector
==134== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==134== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==134== Command: ./test -r xml "List::reverse\ simple"
==134== 
==134== 
==134== HEAP SUMMARY:
==134==     in use at exit: 0 bytes in 0 blocks
==134==   total heap usage: 2,323 allocs, 2,323 frees, 281,212 bytes allocated
==134== 
==134== All heap blocks were freed -- no leaks are possible
==134== 
==134== For counts of detected and suppressed errors, rerun with: -v
==134== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::reverse edge cases

- **Points**: 2 / 2

```
==136== Memcheck, a memory error detector
==136== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==136== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==136== Command: ./test -r xml "List::reverse\ edge\ cases"
==136== 
==136== 
==136== HEAP SUMMARY:
==136==     in use at exit: 0 bytes in 0 blocks
==136==   total heap usage: 2,468 allocs, 2,468 frees, 285,912 bytes allocated
==136== 
==136== All heap blocks were freed -- no leaks are possible
==136== 
==136== For counts of detected and suppressed errors, rerun with: -v
==136== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::reverseNth #3

- **Points**: 5 / 5

```
==138== Memcheck, a memory error detector
==138== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==138== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==138== Command: ./test -r xml "List::reverseNth\ #3"
==138== 
==138== 
==138== HEAP SUMMARY:
==138==     in use at exit: 0 bytes in 0 blocks
==138==   total heap usage: 2,329 allocs, 2,329 frees, 281,392 bytes allocated
==138== 
==138== All heap blocks were freed -- no leaks are possible
==138== 
==138== For counts of detected and suppressed errors, rerun with: -v
==138== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::merge #2

- **Points**: 5 / 5

```
==140== Memcheck, a memory error detector
==140== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==140== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==140== Command: ./test -r xml "List::merge\ #2"
==140== 
==140== 
==140== HEAP SUMMARY:
==140==     in use at exit: 16 bytes in 1 blocks
==140==   total heap usage: 2,359 allocs, 2,358 frees, 283,184 bytes allocated
==140== 
==140== LEAK SUMMARY:
==140==    definitely lost: 0 bytes in 0 blocks
==140==    indirectly lost: 0 bytes in 0 blocks
==140==      possibly lost: 0 bytes in 0 blocks
==140==    still reachable: 16 bytes in 1 blocks
==140==         suppressed: 0 bytes in 0 blocks
==140== Reachable blocks (those to which a pointer was found) are not shown.
==140== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==140== 
==140== For counts of detected and suppressed errors, rerun with: -v
==140== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #3

- **Points**: 2 / 2

```
==142== Memcheck, a memory error detector
==142== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==142== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==142== Command: ./test -r xml "List::sort\ simple\ #3"
==142== 
==142== 
==142== HEAP SUMMARY:
==142==     in use at exit: 0 bytes in 0 blocks
==142==   total heap usage: 2,320 allocs, 2,320 frees, 281,144 bytes allocated
==142== 
==142== All heap blocks were freed -- no leaks are possible
==142== 
==142== For counts of detected and suppressed errors, rerun with: -v
==142== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List Complex

- **Points**: 2 / 2

```
==144== Memcheck, a memory error detector
==144== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==144== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==144== Command: ./test -r xml "List\ Complex"
==144== 
==144== 
==144== HEAP SUMMARY:
==144==     in use at exit: 0 bytes in 0 blocks
==144==   total heap usage: 2,325 allocs, 2,325 frees, 281,264 bytes allocated
==144== 
==144== All heap blocks were freed -- no leaks are possible
==144== 
==144== For counts of detected and suppressed errors, rerun with: -v
==144== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents #2

- **Points**: 4 / 4

```
==146== Memcheck, a memory error detector
==146== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==146== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==146== Command: ./test -r xml "List::insert\ contents\ #2"
==146== 
==146== 
==146== HEAP SUMMARY:
==146==     in use at exit: 0 bytes in 0 blocks
==146==   total heap usage: 2,473 allocs, 2,473 frees, 286,032 bytes allocated
==146== 
==146== All heap blocks were freed -- no leaks are possible
==146== 
==146== For counts of detected and suppressed errors, rerun with: -v
==146== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split edge cases

- **Points**: 5 / 5

```
==148== Memcheck, a memory error detector
==148== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==148== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==148== Command: ./test -r xml "List::split\ edge\ cases"
==148== 
==148== 
==148== HEAP SUMMARY:
==148==     in use at exit: 0 bytes in 0 blocks
==148==   total heap usage: 2,463 allocs, 2,463 frees, 285,696 bytes allocated
==148== 
==148== All heap blocks were freed -- no leaks are possible
==148== 
==148== For counts of detected and suppressed errors, rerun with: -v
==148== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::triplerotate edge

- **Points**: 2 / 2

```
==150== Memcheck, a memory error detector
==150== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==150== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==150== Command: ./test -r xml "List::triplerotate\ edge"
==150== 
==150== 
==150== HEAP SUMMARY:
==150==     in use at exit: 0 bytes in 0 blocks
==150==   total heap usage: 2,470 allocs, 2,470 frees, 285,960 bytes allocated
==150== 
==150== All heap blocks were freed -- no leaks are possible
==150== 
==150== For counts of detected and suppressed errors, rerun with: -v
==150== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::triplerotate hard

- **Points**: 2 / 2

```
==152== Memcheck, a memory error detector
==152== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==152== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==152== Command: ./test -r xml "List::triplerotate\ hard"
==152== 
==152== 
==152== HEAP SUMMARY:
==152==     in use at exit: 0 bytes in 0 blocks
==152==   total heap usage: 2,475 allocs, 2,475 frees, 286,080 bytes allocated
==152== 
==152== All heap blocks were freed -- no leaks are possible
==152== 
==152== For counts of detected and suppressed errors, rerun with: -v
==152== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - List::triplerotate image

- **Points**: 10 / 10





### ✗ - [0/1] - List::ListIterator::operator-- from end

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


---