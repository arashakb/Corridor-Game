#include <httplib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Corridor.h"
using namespace std;
using namespace httplib;

int player_number, player_number_counter=0; string plt_str, check_enter_flag = "0";

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

	//SEND MAP TO THE CLIENT .......
	svr.Get("/map", [&](const Request &, Response &res) {
		if (player_number_counter == player_number) {
			string map_string;
			map_string = game_obj.show_map();
			res.set_content(map_string, "text/plain");
		} else res.set_content("WAIT FOR OTHER PLAYERS TO JOIN THE GAME!", "text/plain");
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
		if (player_number_counter == player_number) {
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
		} else res.set_content("WAIT FOR OTHER PLAYERS TO JOIN THE GAME!", "text/plain");
	});
	svr.Post("/move_up", [&](const Request &req, Response &res) {
		if (player_number_counter == player_number) {
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
		} else res.set_content("WAIT FOR OTHER PLAYERS TO JOIN THE GAME!", "text/plain");
	});
	svr.Post("/move_left", [&](const Request &req, Response &res) {
		if (player_number_counter == player_number) {
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
		}else res.set_content("WAIT FOR OTHER PLAYERS TO JOIN THE GAME!", "text/plain");
	});
	svr.Post("/move_right", [&](const Request &req, Response &res) {
		if (player_number_counter == player_number) {
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
		}else res.set_content("WAIT FOR OTHER PLAYERS TO JOIN THE GAME!", "text/plain");
	});

	svr.Post("/vert_wall", [&](const Request &req, Response &res) {
		if (player_number_counter == player_number) {
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
		}else res.set_content("WAIT FOR OTHER PLAYERS TO JOIN THE GAME!", "text/plain");
	});
	svr.Post("/horiz_wall", [&](const Request &req, Response &res) {
		if (player_number_counter == player_number) {
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
		}else res.set_content("WAIT FOR OTHER PLAYERS TO JOIN THE GAME!", "text/plain");
	});

	svr.listen("127.0.0.1", 8080);
}
