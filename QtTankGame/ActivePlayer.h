#ifndef ACTIVEPLAYER_H
#define ACTIVEPLAYER_H

class ActivePlayer
{

    static int active;

public:

    ActivePlayer(int num = 1)
    {
        active = num;
    }

    int getActive()
    {
        return active;
    }

    void swap()
    {
        if (active == 1)
            active = 2;
        else
            active = 1;
    }

};


#endif // ACTIVEPLAYER_H
