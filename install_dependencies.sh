#! /bin/sh

#OpenCV installed via zip file hosted on Github

printf "Installing dependencies for Gestro\n"

PP_ROOT=$(pwd)
MIN_CMAKE="3.21"
CV_VERSION="69357b1e88680658a07cffde7678a4d697469f03"

# Makes use of snippet from: https://stackoverflow.com/a/3278427 for
# cleanly checking git commits of dependencies
UPSTREAM=${1:-'@{u}'}

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

cd ..

## Download cppTimer
printf "Downloading cppTimer ..."
if [ ! -d "cppTimer_src" ]; then
  printf "\n"
  git clone https://github.com/berndporr/cppTimer.git cppTimer_src || exit 1
  cd cppTimer_src
  cmake .
  make
  sudo make install
  cd ..
else
  cd cppTimer_src
  LOCAL=$(git rev-parse @)
  REMOTE=$(git rev-parse "$UPSTREAM")
  if [ $LOCAL = $REMOTE ]; then
    printf " skipped\n"
  else
    printf " downloading update\n"
    make clean
    git pull origin HEAD
    cmake .
    make
    sudo make install
  fi
  cd ..
  LOCAL=""
  REMOTE=""
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
  make || exit 1
  cd ..
else
  printf " skipped\n"
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