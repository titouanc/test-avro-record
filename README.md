# Testing record file writer with avro-c

This repo contains a handful of variants of a tiny program that creates
a fresh record, and write it to a file.

## Running the tests

```bash
make
```

## Naming conventions

Each test has a name of the form `test-R<record_format>-<values_format>.c`.

#### The record format chars are:

* `n`: a nullable field (ie `{"type": ["null", "double"]}`)
* `i`: a double or integer field (ie `{"type": ["long", "double"]}`)
* `v`: a double field (ie `{"type": double"}`)

#### The values format chars are:

* `v`: a value is put into the record
* `n`: an explicit `avro_null()` is put into the record
* `x`: the field is not set in the record

Examples:

* `test-Rnn-vx.c`: A record with 2 nullable fields. We put a value in the first field
* `test-Rvv-vv.c`: A records with 2 fields. We put a value in each one
