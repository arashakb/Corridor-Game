#include "httplib.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace httplib;


class Player
{
public:
    int x;
    int y;
    Player(int player_name);
    ~Player();
};

class Game
{
private:
    int map[11][11];
    Player n1 = Player(1);
	Player n2 = Player(2);
	Player n3 = Player(3);
	Player n4 = Player(4);
public:
    Game(int num);
    string show_map();
    void move_down(int n);
    void move_up(int n);
    void move_left(int n);
    void move_right(int n);
    bool check_down(int n);
    bool check_up(int n);
    bool check_left(int n);
    bool check_right(int n);
    void vert_wall(int x, int y);
    void horiz_wall(int x, int y);
    bool check_vert_wall(int x, int y);
    bool check_horiz_wall(int x, int y);
    bool check_for_winner();
    string winner();
    ~Game();
};





