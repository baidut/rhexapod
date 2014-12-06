QtDebugger
==========

基于Qt5的上位机


在windows下安装Qt5的步骤
------------------------

1. 在Qt project网站下下载：http://qt-project.org/downloads  
1. 下载Qt 5.3.1 for Windows 32-bit (MinGW 4.8.2, OpenGL, 735 MB)安装很容易，这里就不浪费纸张了。

在linux下安装Qt5的步骤
------------------------

1. 到官网http://qt-project.org/downloads或者ftp://ftp.qt-project.org/上下载Qt的源码包， linux下有自带的gcc，不像windows那么麻烦，还得安装minGW。
1. 到终端中，先执行sudo apt-get install build-essential安装g++和make或者直接执行sudo apt-get install g++ 
1. 进入源码包所在的目录，使用tar xvzf 命令解压下载的Qt源码包。
1. 这一步很关键，执行sudo apt-get install libX11-dev libXext-dev libXtst-dev命令安装这三个软件。Ubuntu在安装时默认不装的。
1. 进入解压后的目录，在终端运行./configure,然后选择安装类型，输入O表示开源版。然后输入yes表示接受GPL协议。此时开始进行配置产生makefile文件。
1. configure完成后，接着运行make，等待编译Qt。这个过程会比较漫长。
1. 当make完成后，运行一下sudo make install。
1. 到这一步，Qt算是安装完成了。接下来配置环境变量，改一下用户环境变量就行了。具体方法是：sudo gedit .profile。然后在后面加上
PATH=/usr/local/Trolltech/Qt-4.8.1/bin:$PATH
export PATH

上面的步骤虽然繁杂，但有助于理解底层需要的构建，如果你希望能像在windows下的快速地安装，可以通过安装Qt Creator可以方便地安装Qt环境，但是需要注意的是安装好后还需要安装g++和GL库才能进行编译。

`sudo apt-get install libgl1-mesa-dev`
