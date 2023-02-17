#include <string>
#include <fstream>
#include <sstream>

int main() {

	std::ofstream ofs("moreData.cpp", std::ios::out);
	std::ifstream ifs("LEVELDATA.txt");

	while (ifs.good()) {
		std::string line;
		std::string bonusLine;
		std::string word;

		getline(ifs, line);
		ofs << "Level* = new Level(\"" << line << "\", \"";

		getline(ifs, line);
		ofs << line << "\", \"";

		getline(ifs, line);
		ofs << line << "\", ";

		getline(ifs, line);
		if (line == "vehicle") ofs << "true,\n{";
		else ofs << "false,\n{";

		getline(ifs, line);
		std::istringstream iss(line);
		while (iss >> word) {
			ofs << word << ", ";
		}
		ofs << "}, {";
		getline(ifs, bonusLine);
		getline(ifs, line);
		std::istringstream is3(line);
		while (is3 >> word) {
			ofs << word << ", ";
		}
		ofs << "},\n{";

		std::istringstream is2(bonusLine);
		while (is2 >> word) {
			ofs << word << ", ";
		}
		ofs << "},\n{}, {});\n\n";

		getline(ifs, line);

	}
}