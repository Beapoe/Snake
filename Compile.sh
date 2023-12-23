cd /data/data/com.termux/files/home/C++/Project/Snake
cmake -S /data/data/com.termux/files/home/C++/Project/Snake -B /data/data/com.termux/files/home/C++/Project/Snake/build
cd build
make
mv Snake /data/data/com.termux/files/home/C++/Project/Executable
echo "编译成功"
