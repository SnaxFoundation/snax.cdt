#! /bin/bash

NAME=$1
CDT_PREFIX=${PREFIX}/${SUBPREFIX}
mkdir -p ${PREFIX}/bin/
mkdir -p ${PREFIX}/lib/cmake/${PROJECT}
mkdir -p ${CDT_PREFIX}/bin 
mkdir -p ${CDT_PREFIX}/include
mkdir -p ${CDT_PREFIX}/lib/cmake/${PROJECT}
mkdir -p ${CDT_PREFIX}/cmake
mkdir -p ${CDT_PREFIX}/scripts
mkdir -p ${CDT_PREFIX}/licenses

#echo "${PREFIX} ** ${SUBPREFIX} ** ${CDT_PREFIX}"

# install binaries 
cp -R ${BUILD_DIR}/bin/* ${CDT_PREFIX}/bin 
cp -R ${BUILD_DIR}/licenses/* ${CDT_PREFIX}/licenses

# install cmake modules
sed "s/_PREFIX_/\/${SPREFIX}/g" ${BUILD_DIR}/modules/SnaxCDTMacrosPackage.cmake &> ${CDT_PREFIX}/lib/cmake/${PROJECT}/SnaxCDTMacros.cmake
sed "s/_PREFIX_/\/${SPREFIX}/g" ${BUILD_DIR}/modules/SnaxWasmToolchainPackage.cmake &> ${CDT_PREFIX}/lib/cmake/${PROJECT}/SnaxWasmToolchain.cmake
sed "s/_PREFIX_/\/${SPREFIX}\/${SSUBPREFIX}/g" ${BUILD_DIR}/modules/${PROJECT}-config.cmake.package &> ${CDT_PREFIX}/lib/cmake/${PROJECT}/${PROJECT}-config.cmake

# install scripts
cp -R ${BUILD_DIR}/scripts/* ${CDT_PREFIX}/scripts 

# install misc.
cp ${BUILD_DIR}/snax.imports ${CDT_PREFIX}

# install wasm includes
cp -R ${BUILD_DIR}/include/* ${CDT_PREFIX}/include

# install wasm libs
cp ${BUILD_DIR}/lib/*.a ${CDT_PREFIX}/lib

# make symlinks
pushd ${PREFIX}/lib/cmake/${PROJECT} &> /dev/null
ln -sf ../../../${SUBPREFIX}/lib/cmake/${PROJECT}/${PROJECT}-config.cmake ${PROJECT}-config.cmake
ln -sf ../../../${SUBPREFIX}/lib/cmake/${PROJECT}/SnaxWasmToolchain.cmake SnaxWasmToolchain.cmake
ln -sf ../../../${SUBPREFIX}/lib/cmake/${PROJECT}/SnaxCDTMacros.cmake SnaxCDTMacros.cmake
popd &> /dev/null

create_symlink() {
   pushd ${PREFIX}/bin &> /dev/null
   ln -sf ../${SUBPREFIX}/bin/$1 $2
   popd &> /dev/null
}

create_symlink "snax-cc snax-cc"
create_symlink "snax-cpp snax-cpp"
create_symlink "snax-ld snax-ld"
create_symlink "snax-pp snax-pp"
create_symlink "snax-init snax-init"
create_symlink "snax-abigen snax-abigen"
create_symlink "snax-wasm2wast snax-wasm2wast"
create_symlink "snax-wast2wasm snax-wast2wasm"

tar -cvzf $NAME ./${PREFIX}/*
rm -r ${PREFIX}
