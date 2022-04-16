#! /bin/sh

#OpenCV installed via zip file hosted on Github

printf "Installing dependencies for Gestro\n"

PP_ROOT=$(pwd)
MIN_CMAKE="3.21"
CV_VERSION="4.5.5"

## Check for correct version of CMake
if ! cmake --version >/dev/null 2>&1; then
  printf "CMake is not installed, please install version 3.21 or higher\n"
  printf "Perhaps run:\n"
  printf "    pip3 install cmake\n"
  printf "You may also need to add the pip install directory to your PATH:\n"
  printf "    PATH=\$PATH:~/.local/bin\n"
  exit 1
fi

CMAKE_VERSION=$(echo "$(cmake --version)" | awk -F'[. ]' '/[0-9]*\.[0-9]*\.[0-9]*$/ {print $3"."$4}')

if [ ! "$(printf '%s\n' "$MIN_CMAKE" "$CMAKE_VERSION" | sort -V | head -n1)" = "$MIN_CMAKE" ]; then
  printf "CMake version too low; $CMAKE_VERSION found and ${MIN_CMAKE} needed\n"
  exit 1
fi

printf "Downloading IIR Filter"
if [ ! -d "iir" ]; then
  printf "\n"
  wget "https://github.com/berndporr/iir1/archive/refs/tags/1.9.1.zip" || exit 1
  unzip -q 1.9.1.zip
  mv "iir1-1.9.1" iir
  cd iir
  cmake . || exit 1
  make
  sudo make install
  cd ..
else
  printf " skipped\n"
fi

## Download OpenCV code
printf "Downloading OpenCV ..."
if [ ! -d "opencv_src" ]; then
  printf "\n"
  wget "https://github.com/opencv/opencv/archive/$CV_VERSION.zip" || exit 1
  unzip -q $CV_VERSION
  mv "opencv-$CV_VERSION" opencv_src
else
  printf " skipped\n"
fi

## Build OpenCV
printf "Building OpenCV ..."
if [ ! -d "opencv_build" ]; then
  printf "\n"
  mkdir -p opencv_build
  cd opencv_build
  cmake -DCMAKE_BUILD_TYPE=Release ../opencv_src || exit 1
  make -j$(nproc) || exit 1
  cd ..
  rm "$CV_VERSION.zip"
  rm -r opencv_src
else
  printf " skipped\n"
  rm "$CV_VERSION.zip"
fi

OS="$(uname -s)"

case $OS in
*"Linux"*)
  # Install QT5 for the User Interface
  printf "Installing qt5-default\n"
  sudo apt install -y qt5-default

  # Install XLL libraries in order to control the display
  printf "Installing X11 client side development dependencies"
  sudo apt-get install -y libx11-dev

  # Install linux sound control libraries
  printf "Install alsa/asoundlib library"
  sudo apt-get install libasound2-dev

  # For unit testing
  printf "Installing unit testing dependencies\n"
  sudo apt install libboost-dev libboost-all-dev -y
  
  ;;
*)
  printf "Failed to install dependencies\n"
  exit 1
  ;;
esac

## Reset directory to project root
cd $PP_ROOT

printf "\nSuccessfully installed dependencies\n"