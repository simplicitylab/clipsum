# CLIpsum

A CLI Lorem Ipsum (or text in other languages) generator. It main focus is generating text for multiple languages, ideal if you build things that are multilingual.

## Platforms

* Linux
* OSX

*In principle any platform with a C++ compiler that supports C++11 should work.*

## Installation from source

Clone the repository and run the following command in your terminal

```
make
make install
```

## Usage

```
clipsum [OPTION...] CLI Lipsum generator - written by Glenn De Backer <glenn@simplicity.be>

-l, --list-text         List available texts
-t, --text text-name    Text to use a source (default lorem ipsum)
-w, --words number      Extract words
-s, --sentences number  Extract sentences
-h, --help              Print help
```

## Examples

**Generating lorem ipsum text of 10 sentences**

```
clipsum -t lorem -s 10
```

**Generating lorem ipsum text of 50 words**

```
clipsum -t lorem -w 50
```

**Generating dutch text of 20 sentences**

```
clipsum -t nl -s 20
```

**Directly copying generated text to OSX clipboard**

```
clipsum -t fr -s 10 | pbcopy
```

## Available texts

```
* lorem            Lorem ipsum (default)
* en               English text
* nl               Dutch text
* fr               French text
* de               German text
* es               Spanish text
* pt               Portuguese text
* it               Italian text
* ru               Russian text
* se               Swedish text
* no               Norwegian text
```

## Running tests

```
make test
```

If all is correct you should see the following output

```
===============================================================================
All tests passed (2 assertions in 2 test cases)
```

## Uninstall

```
make uninstall
```

## License

GPLv2 - see LICENSE
