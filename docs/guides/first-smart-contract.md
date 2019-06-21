### Building your first smart contract
```c++
#include <snax/snax.hpp>
#include <snax/name.hpp>

class [[snax::contract]] hello : public snax::contract {
   public:
      using snax::contract::contract;

      [[snax::action]]
      void hi(snax::name nm) {
         snax::print_f("Hello, %\n", nm);
      }
};
```

- Navigate to the hello folder in examples (./examples/hello).
- You should then see the hello.cpp file
- Now run the compiler
```sh
$ snax-cpp -abigen hello.cpp -o hello.wasm
```
- Or with CMake
```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```
This will generate two files:
* The compiled binary wasm (hello.wasm)
* The generated ABI file (hello.abi)
