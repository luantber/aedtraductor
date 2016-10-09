#ifndef PAR_H
#define PAR_H

typedef int cor;
class Par
{
public:
    Par(){

    }

    Par(cor x1, cor y2) {
        x = x1;
        y = y2;
    }
    cor x,y;
};

#endif
