export ARCH=arm64
export CROSS_COMPILE=/home/knoth06/aarch64-linux-android-4.9/bin/aarch64-linux-android-
mkdir output
make -C $(pwd) O=output  zeroflte_02_defconfig
make -j64 -C $(pwd) O=output
