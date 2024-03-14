# Create target directory if does not exist
if [ ! -d ./target ]; then
    mkdir ./target
fi

# Clear target directory
rm -rf ./target/*

# Compile app into .exe
g++ ./src/*.cpp -o ./target/app.exe

# Run app
./target/app.exe