# Snax.CDT (Contract Development Toolkit)

### Documentation

[EOS 1.6.0 Smart Contract API docs](https://eosio.github.io/eosio.cdt/1.6.0/modules.html)

In order to compile against current master, you should write smart contracts according to the latest (1.6.0 at the moment) specification.

### Binary Releases
Snax.CDT currently supports manual build for Mac OS X, Linux x86_64.

**If you have previously installed Snax.CDT, please run the `uninstall` script (it is in the directory where you cloned Snax.CDT) before downloading and using the binary releases.**

### Guided Installation (Building from Scratch)
```sh
$ git clone --recursive https://github.com/SnaxFoundation/snax.cdt
$ cd snax.cdt
$ ./build.sh
$ sudo ./install.sh
```

### Installed Tools
---
* snax-cpp
* snax-cc
* snax-ld
* snax-init
* snax-abidiff
* snax-wasm2wast
* snax-wast2wasm
* snax-ranlib
* snax-ar
* snax-objdump
* snax-readelf
