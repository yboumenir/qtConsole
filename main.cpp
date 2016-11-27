//#include "qt_key.h"
#include "console_reader.h"
#include <QCoreApplication>
#include <iostream>
struct keys{
    enum pressed{
        up = 0,
        down,
        left,
        right
    };
    int key_pressed = 0;
}keys;

bool got_arrow = false;
void gotKey(char T){
//    std::cout << T << std::endl;
    if(T == '[')
    {
        // we have another letter coming
        got_arrow = true;
    }
    if(got_arrow){
        switch (T) {
        case 'A':
            keys.key_pressed = keys::pressed::up;
            std::cout << "pressed up" << std::endl;
            got_arrow = false;
            break;
        case 'B':
            keys.key_pressed = keys::pressed::down;
            std::cout << "pressed down" << std::endl;
            got_arrow = false;
            break;
        case 'D':
            keys.key_pressed = keys::pressed::left;
            std::cout << "pressed left" << std::endl;
            got_arrow = false;
            break;
        case 'C':
            keys.key_pressed = keys::pressed::right;
            std::cout << "pressed right" << std::endl;
            got_arrow = false;
            break;
        default:
            break;
        }
    }
}


#include <QTimer>
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    ConsoleReader con;
    con.start();

    QTimer *timer = new QTimer;

    // check if key state is saved
    qApp->connect(timer,&QTimer::timeout,[](){
        std::cout << "timer ran out";
        std::cout << "key num is " << keys.key_pressed << std::endl;
    });

    // msec
    timer->start(1000);

    qApp->connect(&con,&ConsoleReader::KeyPressed,&gotKey);

    return app.exec();
}

