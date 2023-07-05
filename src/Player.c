#include"Player.h"
char getPlayerch(int id)
{
    switch (id)
    {
    case 1:
        return 'Q';
        break;
    case 2:
        return 'A';
        break;
    case 3:
        return 'S';
        break;
    case 4:
        return 'J';
        break;
    default:
        break;
    }
}