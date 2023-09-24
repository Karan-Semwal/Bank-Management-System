#! /bin/sh

build_dir="./build"
bin_dir="./bin"

if [ -d $build_dir ]
then
    rm -rf build
fi

if [ -d $bin_dir ]
then
    rm -rf bin
fi

mkdir build
mkdir bin
clear
echo "Cleaned!"
