# Snax.CDT (Contract Development Toolkit)

### Binary Releases
Snax.CDT currently supports Mac OS X brew, Linux x86_64 Debian packages, and Linux x86_64 RPM packages.

**If you have previously installed Snax.CDT, please run the `uninstall` script (it is in the directory where you cloned Snax.CDT) before downloading and using the binary releases.**

#### Mac OS X Brew Install
```sh
$ brew tap snax/snax.cdt
$ brew install snax.cdt
```
#### Mac OS X Brew Uninstall
```sh
$ brew remove snax.cdt
```
#### Debian Package Install
```sh
$ wget https://github.com/snax/snax.cdt/releases/download/v1.6.1/snax.cdt_1.6.1-1_amd64.deb
$ sudo apt install ./snax.cdt_1.6.1-1_amd64.deb
```
#### Debian Package Uninstall
```sh
$ sudo apt remove snax.cdt
```

#### Fedora RPM Package Install
```sh
$ wget https://github.com/snax/snax.cdt/releases/download/v1.6.1/snax.cdt-1.6.1-1.fedora-x86_64.rpm
$ sudo yum install ./snax.cdt-1.6.1-1.fedora-x86_64.rpm
```

#### Fedora RPM Package Uninstall
```sh
$ sudo yum remove snax.cdt
```

#### Centos RPM Package Install
```sh
$ wget https://github.com/snax/snax.cdt/releases/download/v1.6.1/snax.cdt-1.6.1-1.centos-x86_64.rpm
$ sudo yum install ./snax.cdt-1.6.1-1.centos-x86_64.rpm
```

#### Centos RPM Package Uninstall
```sh
$ sudo yum remove snax.cdt
```

### Guided Installation (Building from Scratch)
```sh
$ git clone --recursive https://github.com/snax/snax.cdt
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
