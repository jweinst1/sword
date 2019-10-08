# Sword

*A Fast Data Mining C Library for Python*

## Intro

`sword` is a Python C Extension for making data mining and data searching super fast. It's designed to 
give you amazing performance in the comfort and simplicity of Python. `sword` offers a wide array of tools
to parse and search tabular data, csv, xml, and much more.

### Status

`sword` is still in the active development phase. It currently supports some CSV functionality. More detailed
and rich features will be released in coming patch releases.


## Functions

`sword` currently provides the following functions:



#### `csv_read_row`:

This function reads a single CSV row from a string, and returns a tuple containing:

* The list containing the row elements.
* The remaining unread string.

*Example:*

```py
>>> import sword
>>> sword.csv_read_row("54.7,32.6,54.7\n")
([b'54.7', b'32.6', b'54.7'], b'\n')
```

#### `csv_count_rows`:

Counts the number of rows in a CSV-string

*Exmaple:*

```py
>>> import sword
>>> sword.csv_count_rows("1,2\n3,4\n5,5,5,5\n")
3
```


#### `csv_count_cols`:

Counts the number of columns in a CSv-string

*Example:*

```py
>>> import sword
>>> sword.csv_count_cols("1,2,3,4\n")
4
```