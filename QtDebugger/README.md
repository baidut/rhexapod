QtDebugger
==========

����Qt5����λ��


��windows�°�װQt5�Ĳ���
------------------------

1. ��Qt project��վ�����أ�http://qt-project.org/downloads  
1. ����Qt 5.3.1 for Windows 32-bit (MinGW 4.8.2, OpenGL, 735 MB)��װ�����ף�����Ͳ��˷�ֽ���ˡ�

��linux�°�װQt5�Ĳ���
------------------------

1. ������http://qt-project.org/downloads����ftp://ftp.qt-project.org/������Qt��Դ����� linux�����Դ���gcc������windows��ô�鷳�����ð�װminGW��
1. ���ն��У���ִ��sudo apt-get install build-essential��װg++��make����ֱ��ִ��sudo apt-get install g++ 
1. ����Դ������ڵ�Ŀ¼��ʹ��tar xvzf �����ѹ���ص�QtԴ�����
1. ��һ���ܹؼ���ִ��sudo apt-get install libX11-dev libXext-dev libXtst-dev���װ�����������Ubuntu�ڰ�װʱĬ�ϲ�װ�ġ�
1. �����ѹ���Ŀ¼�����ն�����./configure,Ȼ��ѡ��װ���ͣ�����O��ʾ��Դ�档Ȼ������yes��ʾ����GPLЭ�顣��ʱ��ʼ�������ò���makefile�ļ���
1. configure��ɺ󣬽�������make���ȴ�����Qt��������̻�Ƚ�������
1. ��make��ɺ�����һ��sudo make install��
1. ����һ����Qt���ǰ�װ����ˡ����������û�����������һ���û��������������ˡ����巽���ǣ�sudo gedit .profile��Ȼ���ں������
PATH=/usr/local/Trolltech/Qt-4.8.1/bin:$PATH
export PATH

����Ĳ�����Ȼ���ӣ������������ײ���Ҫ�Ĺ����������ϣ��������windows�µĿ��ٵذ�װ������ͨ����װQt Creator���Է���ذ�װQt������������Ҫע����ǰ�װ�ú���Ҫ��װg++��GL����ܽ��б��롣

`sudo apt-get install libgl1-mesa-dev`
