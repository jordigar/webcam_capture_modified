# webcam_capture
Just webcam capture

## Tips
https://wiki.archlinux.org/index.php/webcam_setup

http://www.linuxintro.org/wiki/Set_up_a_Webcam_with_Linux

First you need to install "libopencv-dev" using the terminal.

After download the repository, in the terminal you need to compile, create the executable and execute it, below there are the command lines:

cd webcam_capture
mkdir build
cd build
cmake ..
make
./webcam_capture

If you add another USB camera for use it add 1 after webcam_capture:

./webcam_capture 1

For working with both cameras at same time you can open two terminals and execute it independent.
