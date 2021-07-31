#include <httplib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Corridor.h"

using namespace std;
using namespace httplib;


Player::Player(int player_name) {
    if (player_name == 1) { this->x = 0; this->y = 0;  }
    else if (player_name == 2) { this->x = 0; this->y = 10;  }
    else if (player_name == 3) { this->x = 10; this->y = 0;  }
    else if (player_name == 4) { this->x = 10; this->y = 10;  }
}

Player::~Player() {}

Game::Game(int num) {
    //MAP
    for(int i=0; i < 11; i++)
        for(int j=0; j < 11; j++)
            this->map[i][j] = 0;
    if (num == 2) {
        this->map[0][0] = 1;
        this->map[0][10] = 2;
    }
    else if (num == 3) {
        this->map[0][0] = 1;
        this->map[0][10] = 2;
        this->map[10][0] = 3;
    }
    else if (num == 4) {
        this->map[0][0] = 1;
        this->map[0][10] = 2;
        this->map[10][0] = 3;
        this->map[10][10] = 4;
    }
}
string Game::show_map() {
    string out = "";
    for(int i=0; i < 11; i++) {
        for(int j=0; j < 11; j++) {
            string str; stringstream s;
            s << this->map[i][j];
            s >> str;
            out += str;
        }
    }
    return out;
}

void Game::move_down(int n) {
    if (n == 1) {
        this->map[(this->n1.x)+1][this->n1.y] = 1;
        this->map[this->n1.x][this->n1.y] = 0;
        this->n1.x += 1;
    }
    else if (n == 2) {
        this->map[(this->n2.x)+1][this->n2.y] = 2;
        this->map[this->n2.x][this->n2.y] = 0;
        this->n2.x += 1;
    }
    else if (n == 3 ) {
        this->map[(this->n3.x)+1][this->n3.y] = 3;
        this->map[this->n3.x][this->n3.y] = 0;
        this->n3.x += 1;
    }
    else if (n == 4) {
        this->map[(this->n3.x)+1][this->n3.y] = 4;
        this->map[this->n3.x][this->n3.y] = 0;
        this->n3.x += 1;
    }
}
void Game::move_up(int n) {
    if (n == 1) {
        this->map[(this->n1.x)-1][this->n1.y] = 1;
        this->map[this->n1.x][this->n1.y] = 0;
        this->n1.x -= 1;
    }
    else if (n == 2) {
        this->map[(this->n2.x)-1][this->n2.y] = 2;
        this->map[this->n2.x][this->n2.y] = 0;
        this->n2.x -= 1;
    }
    else if (n == 3 ) {
        this->map[(this->n3.x)-1][this->n3.y] = 3;
        this->map[this->n3.x][this->n3.y] = 0;
        this->n3.x -= 1;
    }
    else if (n == 4) {
        this->map[(this->n3.x)-1][this->n3.y] = 4;
        this->map[this->n3.x][this->n3.y] = 0;
        this->n3.x -= 1;
    }
}
void Game::move_left(int n) {
    if (n == 1) {
        this->map[this->n1.x][(this->n1.y)-1] = 1;
        this->map[this->n1.x][this->n1.y] = 0;
        this->n1.y -= 1;
    }
    else if (n == 2) {
        this->map[this->n2.x][(this->n2.y)-1] = 2;
        this->map[this->n2.x][this->n2.y] = 0;
        this->n2.y -= 1;
    }
    else if (n == 3 ) {
        this->map[this->n3.x][(this->n3.y)-1] = 3;
        this->map[this->n3.x][this->n3.y] = 0;
        this->n3.y -= 1;
    }
    else if (n == 4) {
        this->map[this->n4.x][(this->n4.y)-1] = 4;
        this->map[this->n4.x][this->n4.y] = 0;
        this->n4.y -= 1;
    }
}
void Game::move_right(int n) {
    if (n == 1) {
        this->map[this->n1.x][(this->n1.y)+1] = 1;
        this->map[this->n1.x][this->n1.y] = 0;
        this->n1.y += 1;
    }
    else if (n == 2) {
        this->map[this->n2.x][(this->n2.y)+1] = 2;
        this->map[this->n2.x][this->n2.y] = 0;
        this->n2.y -= 1;
    }
    else if (n == 3 ) {
        this->map[this->n3.x][(this->n3.y)+1] = 3;
        this->map[n3.x][this->n3.y] = 0;
        this->n3.y += 1;
    }
    else if (n == 4) {
        this->map[this->n4.x][(this->n4.y)+1] = 4;
        this->map[this->n4.x][this->n4.y] = 0;
        this->n4.y += 1;
    }
}

bool Game::check_down(int n) {
    if (n == 1) {
        if ( map[(n1.x)+1][n1.y] != 0 || n1.x == 10)
            return false;
        return true;
    }
    else if (n == 2) {
        if ( map[(n2.x)+1][n2.y] != 0 || n2.x == 10)
            return false;
        return true;
    }
    else if (n == 3) {
        if ( map[(n3.x)+1][n3.y] != 0 || n3.x == 10)
            return false;
        return true;
    }
    else if (n == 4) {
        if ( map[(n4.x)+1][n4.y] != 0 || n4.x == 10)
            return false;
        return true;
    }
}
bool Game::check_up(int n) {
    if (n == 1) {
        if ( map[(n1.x)-1][n1.y] != 0 || n1.x == 0 )
            return false;
        return true;
    }
    else if (n == 2) {
        if ( map[(n2.x)-1][n2.y] != 0 || n2.x == 0 )
            return false;
        return true;
    }
    else if (n == 3) {
        if ( map[(n3.x)-1][n3.y] != 0 || n3.x == 0 )
            return false;
        return true;
    }
    else if (n == 4) {
        if ( map[(n4.x)-1][n4.y] != 0 || n4.x == 0 )
            return false;
        return true;
    }
}
bool Game::check_right(int n) {
    if (n == 1) {
        if ( map[n1.x][(n1.y)+1] != 0 || n1.y == 10)
            return false;
        return true;
    }
    else if (n == 2) {
        if ( map[n2.x][(n2.y)+1] != 0 || n2.y == 10)
            return false;
        return true;
    }
    else if (n == 3) {
        if ( map[n3.x][(n3.y)+1] != 0 || n3.y == 10)
            return false;
        return true;
    }
    else if (n == 4) {
        if ( map[n4.x][(n4.y)+1] != 0 || n4.y == 10)
            return false;
        return true;
    }
}
bool Game::check_left(int n) {
    if (n == 1) {
        if ( map[n1.x][(n1.y)-1] != 0 || n1.y == 0)
            return false;
        return true;
    }
    else if (n == 2) {
        if ( map[n2.x][(n2.y)-1] != 0 || n2.y == 0)
            return false;
        return true;
    }
    else if (n == 3) {
        if ( map[n3.x][(n3.y)-1] != 0 || n3.y == 0)
            return false;
        return true;
    }
    else if (n == 4) {
        if ( map[n4.x][(n4.y)-1] != 0 || n4.y == 0)
            return false;
        return true;
    }
}

void Game::vert_wall(int x, int y) {
    map[x][y] = 5;
    map[x+1][y] = 5;
    map[x-1][y] = 5;
}
void Game::horiz_wall(int x, int y) {
    map[x][y] = 6;
    map[x][y+1] = 6;
    map[x][y-1] = 6;
}

bool Game::check_vert_wall(int x, int y) {
    if (map[x][y] != 0 || map[x+1][y] != 0 || map[x-1][y] != 0 || x == 0 || x == 10 || x == 5 || y == 5
            || x == 4 || x == 6)
        return false;
    return true;
}
bool Game::check_horiz_wall(int x, int y) {
    if (map[x][y] != 0 || map[x][y+1] != 0 || map[x][y-1] != 0 || y == 0 || y == 10 || x == 5 || y == 5
    || y == 4 || y == 6)
        return false;
    return true;
}

bool Game::check_for_winner() {
    if (map[5][5] != 0)
        return true;
    return false;
}
string Game::winner() {
    if (map[5][5] == 1)
        return "1";
    else if (map[5][5] == 2)
        return "2";
    else if (map[5][5] == 3)
        return "3";
    else if (map[5][5] == 4)
        return "4";
}

Game::~Game() {}

