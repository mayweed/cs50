# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?
pneumonoultramicroscopicsilicovolcanoconiosis is a word invented by the president of
the National Puzzlers' League as a synonym for the disease known as silicosis. It is
the longest word in the english language published in a dictionary, the Oxford
English Dictionary, which defines it as "an artificial long word said to mean a lung
disease caused by inhaling very fine ash and sand dust". (cf wikipedia)

## According to its man page, what does `getrusage` do?

Its declaration is: int getrusage(int who, struct rusage \*usage);
It returns resource usage measures for who which can be one of the following:

RUSAGE_SELF Return resource usage statistics for the calling process,
which is the sum of resources used by all threads in the
process.

RUSAGE_CHILDREN Return resource usage statistics for all children of the
calling process that have terminated and been waited for.
These statistics will include the resources used by
grandchildren, and further removed descendants, if all of the
intervening descendants waited on their terminated children.

RUSAGE_THREAD (since Linux 2.6.26) Return resource usage statistics for the calling thread.  The
_GNU_SOURCE feature test macro must be defined (before
including any header file) in order to obtain the definition
of this constant from <sys/resource.h>.

## Per that same man page, how many members are in a variable of type `struct rusage`?

struct rusage got 16 members tow of which are struct.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

TODO

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

TODO

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

TODO

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

TODO
