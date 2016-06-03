# clipsum

A commandline Ipsum generator 

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

**Directly copying text to mac clipboard**

```
clipsum -t fr -s 10 | pbcopy
```

## Available texts

```
Available texts:
----------------
 * lorem            Lorem ipsum (default)
 * en               English text
 * nl               Dutch text
 * fr               French text
 * de               German text
 * es               Spanish text
```
