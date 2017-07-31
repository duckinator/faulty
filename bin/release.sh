#!/bin/bash

rm -rf release
mkdir -p release/faulty-linux release/faulty-windows

cp -r maps tiles build/linux-x86_64/faulty       release/faulty-linux
cp -r maps tiles build/windows-x86_64/faulty.exe release/faulty-windows

cd release

tar cfv faulty-linux.tar  faulty-linux
zip -r faulty-windows.zip faulty-windows

