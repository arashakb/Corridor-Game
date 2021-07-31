#include <httplib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int flag = 0;

int main(void) {
	int player_name;
	string pl_str;
	httplib::Client cli("localhost",8080);
	//SENDING PLAYER NUMBER TO SERVER...
	cout << "[+]WELCOME TO THE GAME.\nWHAT IS YOUR PLAYER NUMBER?(1 OR 2 OR 3 OR 4) " ;
	cin >> player_name;
	stringstream ss;
	ss << player_name;
	ss >> pl_str;
	auto h = cli.Post("/player_name", pl_str, "text/plain");
	cout << h->body << endl;
	if (h->body.substr(0,1) == "T")
		return 0;
	cout << "Enter 1 to start the game ";
	int s; cin >> s;
	if (s == 1) {
		int choose = 100, flag = 0;
		while (choose != 7) {
				auto win = cli.Get("/win");
				if (win->body != "0") {
					cout << "THE WINNER IS " + win->body << endl;
					break;
				}
				auto exit = cli.Get("/exit");
				if (exit->body == "1") {
					cout << "SORRY, SOMEONE QUIT THE GAME!" << endl;
					break;
				}
				cout << "\t0.SEE THE UPDATED MAP\n\t1. Move down\n\t2. Move up\n\t3. Move left\n\t4. Move right\n\t5. Vertical Wall\n\t6. Horizental Wall\n\t7. Leave The Game" << endl;
				cout <<"- - - - - - - - - - - - - - - - - - - " << endl;
				cin.ignore();
				cout << "ENTER YOUR CHOICE: " ;
				cin >> choose ;
				if (choose == 0) {
					auto res = cli.Get("/map");
					if (res->body[0] != 'W') {
						cout << "UPDATED MAP: " << endl;
						int t = 0;
						for (int i = 0; i < 11; i++) {
							for (int j = 0; j < 11; j++)
									cout << res->body[t++] << " ";
							cout << endl;
						}
						cout <<"- - - - - - - - - - - - - - - - - - - " << endl;
					}else cout <<  "ERROR: " << res->body << endl;
				}
				else if (choose == 1) {
					auto res = cli.Post("/move_down", pl_str, "text/plain");
					if (res->body[0] != 'P' && res->body[0] != 'Y' && res->body[0] != 'W') {
						cout << "UPDATED MAP: " << endl;
						int t = 0;
						for (int i = 0; i < 11; i++) {
							for (int j = 0; j < 11; j++)
									cout << res->body[t++] << " ";
							cout << endl;
						}
						cout <<"- - - - - - - - - - - - - - - - - - - " << endl;
					} else cout <<  "ERROR: " << res->body << endl;
				}
				else if (choose == 2) {
						auto res = cli.Post("/move_up", pl_str, "text/plain");
						if (res->body[0] != 'P' && res->body[0] != 'Y' && res->body[0] != 'W') {
							cout << "UPDATED MAP: " << endl;
							int t = 0;
							for (int i = 0; i < 11; i++) {
								for (int j = 0; j < 11; j++)
										cout << res->body[t++] << " ";
								cout << endl;
							}
							cout <<"- - - - - - - - - - - - - - - - - - - " << endl;
						} else cout <<  "ERROR: " << res->body << endl;
				}
				else if (choose == 3) {
					auto res = cli.Post("/move_left", pl_str, "text/plain");
					if (res->body[0] != 'P' && res->body[0] != 'Y' && res->body[0] != 'W') {
						cout << "UPDATED MAP: " << endl;
						int t = 0;
						for (int i = 0; i < 11; i++) {
							for (int j = 0; j < 11; j++)
									cout << res->body[t++] << " ";
							cout << endl;
						}
						cout <<"- - - - - - - - - - - - - - - - - - - " << endl;
					} else cout <<  "ERROR: " << res->body << endl;
				}
				else if (choose == 4) {
					auto res = cli.Post("/move_right", pl_str, "text/plain");
					if (res->body[0] != 'P' && res->body[0] != 'Y' && res->body[0] != 'W') {
						cout << "UPDATED MAP: " << endl;
						int t = 0;
						for (int i = 0; i < 11; i++) {
							for (int j = 0; j < 11; j++)
									cout << res->body[t++] << " ";
							cout << endl;
						}
						cout <<"- - - - - - - - - - - - - - - - - - - " << endl;
					} else cout << "ERROR: " << res->body << endl;
				}
				else if (choose == 5) {
					int x, y;
					cout << "ENTER X,Y FOR THE CENTER OF YOUR VERTICAL LINE" << endl;
					cout << "X: " ; cin >> x; cout << "Y: " ; cin >> y;
					string str = pl_str + to_string(x) + "      " + to_string(y);
					auto wall = cli.Post("/vert_wall", str, "text/plain");
					if (wall->body[0] != 'P' && wall->body[0] != 'Y' && wall->body[0] != 'W') {
						cout << "UPDATED MAP: " << endl;
						int t = 0;
						for (int i = 0; i < 11; i++) {
							for (int j = 0; j < 11; j++)
									cout << wall->body[t++] << " ";
							cout << endl;
						}
						cout <<"- - - - - - - - - - - - - - - - - - - " << endl;
					} else cout <<  "ERROR: " << wall->body << endl;
				}
				else if (choose == 6) {
					int x, y;
					cout << "ENTER X,Y FOR THE CENTER OF YOUR HORIZENTAL LINE" << endl;
					cout << "X: " ; cin >> x; cout << "Y: " ; cin >> y;
					string str = pl_str + to_string(x) + "      " + to_string(y);
					auto wall = cli.Post("/horiz_wall", str, "text/plain");
					if (wall->body[0] != 'P' && wall->body[0] != 'Y' && wall->body[0] != 'W') {
						cout << "UPDATED MAP: " << endl;
						int t = 0;
						for (int i = 0; i < 11; i++) {
							for (int j = 0; j < 11; j++)
									cout << wall->body[t++] << " ";
							cout << endl;
						}
						cout <<"- - - - - - - - - - - - - - - - - - - " << endl;
					} else cout <<  "ERROR: " << wall->body << endl;
				}
				else if (choose == 7) {
					cli.Get("/someone_exited");
				}
				else 
					cout << "INVALID INPUT!" << endl;
		}
	}
}
