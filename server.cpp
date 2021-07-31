#include <httplib.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
using namespace httplib;

int player_number, player_number_counter=0; string plt_str, check_enter_flag = "0";
class Player {
public:
	int x, y;
  Player(int player_name) {
          if (player_name == 1) { x = 0; y = 0;  }
          else if (player_name == 2) { x = 0; y = 10;  }
					else if (player_name == 3) { x = 10; y = 0;  }
					else if (player_name == 4) { x = 10; y = 10;  }
  }
};

class Game {
public:
	int map[11][11];
	Player n1 = Player(1);
	Player n2 = Player(2);
	Player n3 = Player(3);
	Player n4 = Player(4);
  Game(int num) {
		//MAP
		for(int i=0; i < 11; i++)
			for(int j=0; j < 11; j++)
				map[i][j] = 0;
  	if (num == 2) {
			map[0][0] = 1;
			map[0][10] = 2;
		}
		else if (num == 3) {
			map[0][0] = 1;
			map[0][10] = 2;
			map[10][0] = 3;
		}
		else if (num == 4) {
			map[0][0] = 1;
			map[0][10] = 2;
			map[10][0] = 3;
			map[10][10] = 4;
		}
  }
	string show_map() {
		string out = "";
		for(int i=0; i < 11; i++) {
			for(int j=0; j < 11; j++) {
				string str; stringstream s;
				s << map[i][j];
				s >> str;
				out += str;
			}
		}
		return out;
	}
	void move_down(int n) {
		if (n == 1) {
			map[(n1.x)+1][n1.y] = 1;
			map[n1.x][n1.y] = 0;
			n1.x += 1;
		}
		else if (n == 2) {
			map[(n2.x)+1][n2.y] = 2;
			map[n2.x][n2.y] = 0;
			n2.x += 1;
		}
		else if (n == 3 ) {
			map[(n3.x)+1][n3.y] = 3;
			map[n3.x][n3.y] = 0;
			n3.x += 1;
		}
		else if (n == 4) {
			map[(n3.x)+1][n3.y] = 4;
			map[n3.x][n3.y] = 0;
			n3.x += 1;
		}
	}
	void move_up(int n) {
		if (n == 1) {
			map[(n1.x)-1][n1.y] = 1;
			map[n1.x][n1.y] = 0;
			n1.x -= 1;
		}
		else if (n == 2) {
			map[(n2.x)-1][n2.y] = 2;
			map[n2.x][n2.y] = 0;
			n2.x -= 1;
		}
		else if (n == 3 ) {
			map[(n3.x)-1][n3.y] = 3;
			map[n3.x][n3.y] = 0;
			n3.x -= 1;
		}
		else if (n == 4) {
			map[(n3.x)-1][n3.y] = 4;
			map[n3.x][n3.y] = 0;
			n3.x -= 1;
		}
	}
	void move_left(int n) {
		if (n == 1) {
			map[n1.x][(n1.y)-1] = 1;
			map[n1.x][n1.y] = 0;
			n1.y -= 1;
		}
		else if (n == 2) {
			map[n2.x][(n2.y)-1] = 2;
			map[n2.x][n2.y] = 0;
			n2.y -= 1;
		}
		else if (n == 3 ) {
			map[n3.x][(n3.y)-1] = 3;
			map[n3.x][n3.y] = 0;
			n3.y -= 1;
		}
		else if (n == 4) {
			map[n4.x][(n4.y)-1] = 4;
			map[n4.x][n4.y] = 0;
			n4.y -= 1;
		}
	}
	void move_right(int n) {
		if (n == 1) {
			map[n1.x][(n1.y)+1] = 1;
			map[n1.x][n1.y] = 0;
			n1.y += 1;
		}
		else if (n == 2) {
			map[n2.x][(n2.y)+1] = 2;
			map[n2.x][n2.y] = 0;
			n2.y -= 1;
		}
		else if (n == 3 ) {
			map[n3.x][(n3.y)+1] = 3;
			map[n3.x][n3.y] = 0;
			n3.y += 1;
		}
		else if (n == 4) {
			map[n4.x][(n4.y)+1] = 4;
			map[n4.x][n4.y] = 0;
			n4.y += 1;
		}
	}
	bool check_down(int n) {
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
	bool check_up(int n) {
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
	bool check_right(int n) {
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
	bool check_left(int n) {
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
	void vert_wall(int x, int y) {
		map[x][y] = 5;
		map[x+1][y] = 5;
		map[x-1][y] = 5;
	}
	void horiz_wall(int x, int y) {
		map[x][y] = 6;
		map[x][y+1] = 6;
		map[x][y-1] = 6;
	}
	bool check_vert_wall(int x, int y) {
		if (map[x][y] != 0 || map[x+1][y] != 0 || map[x-1][y] != 0 || x == 0 || x == 10 || x == 5 || y == 5
				|| x == 4 || x == 6)
			return false;
		return true;
	}
	bool check_horiz_wall(int x, int y) {
		if (map[x][y] != 0 || map[x][y+1] != 0 || map[x][y-1] != 0 || y == 0 || y == 10 || x == 5 || y == 5
		|| y == 4 || y == 6)
			return false;
		return true;
	}
	bool check_for_winner() {
		if (map[5][5] != 0)
			return true;
		return false;
	}
	string winner() {
		if (map[5][5] == 1)
			return "1";
		else if (map[5][5] == 2)
			return "2";
		else if (map[5][5] == 3)
			return "3";
		else if (map[5][5] == 4)
			return "4";
	}
};

int main(void)
{
	Server svr;
	int player_turn = 1;
	stringstream ss;
	ss << player_turn;
	ss >> plt_str;

	cout << "Number of Players: ";
	cin >> player_number;
	Game game_obj(player_number);
	svr.Get("check_turn", [&](const Request &, Response &res) {
		res.set_content(plt_str, "text/plain");
	});

	//SEND MAP TO CLIENT
	svr.Get("/map", [&](const Request &, Response &res) {
		string map_string;
		map_string = game_obj.show_map();
		res.set_content(map_string, "text/plain");
	});
	svr.Get("/win", [&](const Request &req, Response &res) {
		if (game_obj.check_for_winner()) {
			string winner = game_obj.winner();
			res.set_content(winner, "text/plain");
		} else res.set_content("0", "text/plain");
	});
	svr.Post("/player_name", [&](const Request &req, Response &res) {
		if (player_number_counter < player_number) {
			player_number_counter += 1;
			res.set_content("[+]your name is listed in server", "text/plain");
		} else res.set_content("THIS SERVER IS FULL! YOU CAN'T PLAY!", "text/plain");
	});
	svr.Post("/move_down", [&](const Request &req, Response &res) {
		if (plt_str != req.body) {
			res.set_content("PLAYER NUMBER " + plt_str + " SHOULD CHOOSE. NOT YOU!", "text/plain");
		}else {
			//check if the move is ok
			if (game_obj.check_down(player_turn)) {
				game_obj.move_down(player_turn);
				string map_string;
				map_string = game_obj.show_map();
				res.set_content(map_string, "text/plain");
				//update turn
				if (player_turn == player_number) player_turn = 1;
				else player_turn++;
				plt_str = to_string(player_turn);
			} else res.set_content("YOU CAN'T MOVE TO DOWN!", "text/plain");
		}
	});
	svr.Post("/move_up", [&](const Request &req, Response &res) {
		if (plt_str != req.body) {
			res.set_content("PLAYER NUMBER " + plt_str + " SHOULD CHOOSE. NOT YOU!", "text/plain");
		}else {
			//check if the move is ok
			if (game_obj.check_up(player_turn)) {
	 			game_obj.move_up(player_turn);
				string map_string;
				map_string = game_obj.show_map();
				res.set_content(map_string, "text/plain");
				//update turn
				if (player_turn == player_number) player_turn = 1;
				else player_turn++;
				plt_str = to_string(player_turn);
			} else res.set_content("YOU CNA'T MOVE TO UP!" , "text/plain");
		}
	});
	svr.Post("/move_left", [&](const Request &req, Response &res) {
		if (plt_str != req.body) {
			res.set_content("PLAYER NUMBER " + plt_str + " SHOULD CHOOSE. NOT YOU!", "text/plain");
		}else {
			//check if the move is ok
			if (game_obj.check_left(player_turn)) {
				game_obj.move_left(player_turn);
				string map_string;
				map_string = game_obj.show_map();
				res.set_content(map_string, "text/plain");
				//update turn
				if (player_turn == player_number) player_turn = 1;
				else player_turn++;
				plt_str = to_string(player_turn);
			} else res.set_content("YOU CAN'T MOVE TO LEFT", "text/plain");
		}
	});
	svr.Post("/move_right", [&](const Request &req, Response &res) {
		if (plt_str != req.body) {
			res.set_content("PLAYER NUMBER " + plt_str + " SHOULD CHOOSE. NOT YOU!", "text/plain");
		}else {
			//check if the move is ok
			if (game_obj.check_right(player_turn)) {
				game_obj.move_right(player_turn);
				string map_string;
				map_string = game_obj.show_map();
				res.set_content(map_string, "text/plain");
				//update turn
				if (player_turn == player_number) player_turn = 1;
				else player_turn++;
				plt_str = to_string(player_turn);
			}	else res.set_content("YOU CAN'T MOVE TO RIGHT", "text/plain");
		}
	});


	svr.Post("/vert_wall", [&](const Request &req, Response &res) {
		if (plt_str != req.body.substr(0,1)) {
			res.set_content("PLAYER NUMBER " + plt_str + " SHOULD CHOOSE. NOT YOU!", "text/plain");
		}else {
			int x = stoi(req.body.substr(1,3));
			int y = stoi(req.body.substr(8,req.body.length()));
			cout << x << endl;
			cout << y << endl;
			// check if we can do that or not
			if (game_obj.check_vert_wall(x,y)) {
				game_obj.vert_wall(x, y);
				string map_string;
				map_string = game_obj.show_map();
				res.set_content(map_string, "text/plain");
				//update turn
				if (player_turn == player_number) player_turn = 1;
				else player_turn++;
				plt_str = to_string(player_turn);
			} else res.set_content("YOU CAN'T PUT VERTICAL WALL AT THERE", "text/plain");
		}
	});
	svr.Post("/horiz_wall", [&](const Request &req, Response &res) {
		if (plt_str != req.body.substr(0,1)) {
			res.set_content("PLAYER NUMBER " + plt_str + " SHOULD CHOOSE. NOT YOU!", "text/plain");
		}else {
			int x = stoi(req.body.substr(1,3));
			int y = stoi(req.body.substr(8,req.body.length()));
			// check if we can do that or not
			if (game_obj.check_horiz_wall(x,y)) {
				game_obj.horiz_wall(x, y);
				string map_string;
				map_string = game_obj.show_map();
				res.set_content(map_string, "text/plain");
				//update turn
				if (player_turn == player_number) player_turn = 1;
				else player_turn++;
				plt_str = to_string(player_turn);
			} else res.set_content("YOU CAN'T PUT HORIZENTAL WALL AT THERE", "text/plain");
		}
	});

	svr.listen("127.0.0.1", 8080);
}
