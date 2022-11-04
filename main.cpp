#include <iostream>
#include <cctype>
#include <string> //stoi dlya obrabotki oshibok
#include <fstream>

using namespace std;

char alphabet[]{"abcdefghijklmnopqrstuvwxyz"};

int countLatin(const char* source, int maxstrlen);

int main() {

	ifstream countingRows("C:/vremennoe/chars.txt");
	string row;
	int rcount(0);
	bool iferr(false);
	ofstream out("C:/vremennoe/chars_log.txt");
	if (out.is_open()) {

		if (countingRows.is_open()) {

			while (getline(countingRows, row)) {

				if (row.empty() == false)rcount++;

			}

		}
		else {

			cout << "Can't reach the file" << endl;
			out << "Can't reach the file" << endl;

		}
		countingRows.close();
		if (rcount != 0) {

			ifstream file("C:/vremennoe/chars.txt");
			int maxnum;

			if (file.is_open()) {

				int temp(0);

				while (getline(file, row)) {

					if (temp == 0) {
						cout << "Max num: " << row << endl;
						out << "Max num: " << row << endl<<endl;
						if (row.find('.') != row.npos || row.find(',') != row.npos) {

							iferr = true;
							cout << "First value must be integer" << endl;
							out << "First value must be integer" << endl;
							break;

						}

						try {

							maxnum = stoi(row);

						}
						catch (exception) {

							cout << "First value must be integer" << endl;
							out << "First value must be integer" << endl;
							iferr = true;
							break;

						}

						if (maxnum > 10000) {

							cout << "First value must be less than 10001" << endl;
							out << "First value must be less than 10001" << endl;
							iferr = true;
							break;

						}

					}
					else {

						if (row.empty() == false) {

							int temp0 = row.length();
							if (temp0 > maxnum) {

								cout << temp << ": " << "Too many symbols in a row" << endl;
								out <<temp<<": "<< "Too many symbols in a row" << endl;
								iferr = true;
								break;

							}
							char* curr = new char[temp0 + 1];

							for (int i = 0; i < temp0 + 1; i++) {

								if (i != temp0) {

									curr[i] = row[i];

								}
								else {
									curr[i] = '\0';
								}

							}
							cout << temp << ": " << countLatin(curr, maxnum * 26) << " unique latin symbols" << endl;
							out << temp << ": " << "Row: " << row << endl;
							out << countLatin(curr, maxnum * 26) << " unique latin symbols" << endl << endl;;
						}

					}

					temp++;
				}
				if (temp == 1) {

					cout << "File must have string rows" << endl;
					out << "File must have string rows" << endl;

				}
			}
			else {

				cout << "Can't reach the file" << endl;
				out << "Can't reach the file" << endl;

			}

		}
		else {

			cout << "File is empty" << endl;
			out << "File is empty" << endl;

		}

	}
	else {

		cout << "Can't reach log file" << endl;

	}
	
	std::system("pause");
	return 0;

}

int countLatin(const char* source, int maxstrlen) {

	int temp(0), number(0);
	bool state(true), state1(false);
	
	char* vremennoe = new char[maxstrlen * 26];

	for (int u = 0; u < maxstrlen * 26; u++) {

		vremennoe[u] = '1';

	}

	while (source[temp]!='\0') {

		for (int i = 0; i < 26; i++) {

			if ((char)tolower(source[temp]) == (char)tolower(alphabet[i])) {

				state1 = true;

				for (int k = 0; k < 26; k++) {

					if ((char)tolower(source[temp]) == (char)tolower(vremennoe[k])) {

						state = false;
						break;

					}

				}

			}

		}

		if (state&&state1) {

			vremennoe[number] = (char)tolower(source[temp]);
			number++;
		}

		state = true;
		state1 = false;
		temp++;

	}

	return number;
}

