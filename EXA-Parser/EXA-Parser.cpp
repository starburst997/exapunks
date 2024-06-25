// I like to keep one-off simple program in one file
// Might clean this up eventually...
#include <map>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <ostream>
#include <string>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;
using namespace std;

const int CYCLE_N = 6;
const int SIZE_N = 4;
const int ACTIVITY_N = 8;

// Types
enum Stats : int32_t {
	Cycles = 0,
	Size = 1,
	Activity = 2
};

struct GIF {
	fs::path name;
	fs::file_time_type time;
};

struct EXA {
	string name;
	string source;
	bool local;
};

struct Solution {
	string id;
	string name;

	// Not in file format?
	int wins;
	int draws;
	int losses;

	int cycles;
	int size;
	int activity;
	fs::path path;

	vector<EXA> exas;
};

struct Info {
	string id;
	string description;
	string title;
	string path;
};

// Vars
int maxChars = 0;
map<string, Solution> solutions;
map<string, Info> dataMap;
map<string, fs::path> gifMap;
vector<string> levels = { };
vector<string> battles = { };
vector<string> bonus = { };
vector<GIF> gifs = { };

// Utils
string readString(ifstream& stream) {
	int32_t i;
	stream.read(reinterpret_cast<char*>(&i), sizeof(i));
	
	char* buffer = new char[i + 1];
	buffer[i] = 0; // nul terminated

	stream.read(buffer, i);

	return buffer;
}

void writeNum(ofstream& stream, int n, int max) {
	string str = to_string(n);

	stream << str;
	for (int j = 0; j < max - str.length(); j++) stream << ' ';
}

bool compareTime(const GIF& a, const GIF& b)
{
	return a.time < b.time;
}

// Parse Saves (.solution) / GIFs specified in arguments and create the repo's file
// TODO: Include leaderboard as well?
int main(int argc, char* argv[])
{
	cout << "Usage: [script_name]" << endl;
	cout << "    or [script_name] saves_dir gifs_dir descriptions_dir output_dir data.txt" << endl;

	fs::path pathSaves = "../temp/saves";
	if (argc >= 2) pathSaves = argv[1];
	cout << "Save directory: " << pathSaves;
	if (fs::is_directory(pathSaves)) {
		cout << endl;
	} else {
		cout << " invalid!" << endl << endl;
		return 1;
	}

	fs::path pathGIFs = "../temp/gifs";
	if (argc >= 3) pathGIFs = argv[2];
	cout << "GIFs directory: " << pathGIFs;
	if (fs::is_directory(pathGIFs)) {
		cout << endl;
	} else {
		cout << " invalid!" << endl << endl;
		return 1;
	}

	fs::path pathDescriptions = "../temp/descriptions";
	if (argc >= 4) pathDescriptions = argv[3];
	cout << "Descriptions directory: " << pathDescriptions;
	if (fs::is_directory(pathDescriptions)) {
		cout << endl;
	} else {
		cout << " invalid!" << endl << endl;
		return 1;
	}

	fs::path pathOutput = "..";
	if (argc >= 5) pathOutput = argv[4];
	cout << "Output directory: " << pathOutput;
	if (fs::is_directory(pathOutput)) {
		cout << endl;
	} else {
		cout << " invalid!" << endl << endl;
		return 1;
	}

	fs::path pathData = "data.txt";
	if (argc >= 6) pathData = argv[5];
	ifstream dataStream(pathData);
	cout << "Data file: " << pathData;
	if (dataStream) {
		cout << endl;
	} else {
		cout << " invalid!" << endl << endl;
		return 1;
	}

	cout << endl;

	// Loop all gifs, they are badly named, so instead assume they were saved in order (sort by time)
	cout << "Parse GIFs:" << endl;

	for (const auto& entry : fs::directory_iterator(pathGIFs)) {
		gifs.push_back({ entry.path(), fs::last_write_time(entry.path()) });

		cout << "    " << entry.path() << endl;
	}

	sort(gifs.begin(), gifs.end(), compareTime);

	// Create hash map / array
	cout << endl << "Parse data.txt:" << endl;

	int globalCounter = 0;
	int solutionCounter = 1;
	int battleCounter = 1;
	int bonusCounter = 1;
	string line;
	while (getline(dataStream, line)) {
		int i1 = line.find(',');
		if (i1 == string::npos) continue;

		int i2 = line.find(',', i1 + 1);
		if (i2 == string::npos) continue;

		string id = line.substr(0, i1);
		string description = line.substr(i1 + 1, i2 - i1 - 1) + ".txt";
		string title = line.substr(i2 + 1);

		bool isBattle = description.rfind("battle-", 0) == 0;
		int counter = isBattle ? battleCounter++ : solutionCounter++;
		bool isBonus = description.rfind("bonus-", 0) == 0;
		counter = isBonus ? bonusCounter++ : counter;

		// Create path based on title
		string path = ((counter < 10) ? ("0" + to_string(counter)) : to_string(counter)) + '-';
		char last = ' ';
		for (int i = 0; i < title.length(); i++) {
			char c = title[i];
			if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
				path += c;
				last = c;
			}
			else if (c >= 'A' && c <= 'Z') {
				path += c + 0x20;
				last = c;
			}
			else if ((c == ' ' || c == '-') && last != '-') {
				path += '-';
				last = '-';
			}
		}

		cout << "    " << id << ": " << title;
		if (globalCounter < gifs.size()) {
			gifMap[id] = gifs[globalCounter].name;
		}
		Info info = { id, description, title, path };

		int total = 1 + 5 + title.length() + 12 + path.length() + 1;
		if (total > maxChars) maxChars = total;

		dataMap[id] = info;

		if (isBattle) 
			battles.push_back(id);
		else if (isBonus)
			bonus.push_back(id);
		else
			levels.push_back(id);

		globalCounter++;
	}
	cout << endl;

	// Loop all saves, overwrite if cycles is better
	cout << endl << "Parse saves:" << endl;

	for (const auto& entry : fs::directory_iterator(pathSaves)) {
		ifstream solutionStream(entry.path(), ios::binary);
		if (!solutionStream) continue;

		int32_t i;
		solutionStream.read(reinterpret_cast<char*>(&i), sizeof(i));

		// Will probably change if there is new version
		if (i != 0x3F0) continue;

		string id = readString(solutionStream);
		string name = readString(solutionStream);

		int32_t unknown1;
		solutionStream.read(reinterpret_cast<char*>(&unknown1), sizeof(i));

		int32_t unknown2;
		solutionStream.read(reinterpret_cast<char*>(&unknown2), sizeof(i));

		// Stats
		solutionStream.read(reinterpret_cast<char*>(&i), sizeof(i));

		int cycles = 0, size = 0, activity = 0;
		for (int j = 0; j < i; j++) {
			int32_t type, value;
			solutionStream.read(reinterpret_cast<char*>(&type), sizeof(type));
			solutionStream.read(reinterpret_cast<char*>(&value), sizeof(value));

			switch ((Stats) type) {
			case Cycles:
				cycles = value;
				break;
			case Size:
				size = value;
				break;
			case Activity:
				activity = value;
				break;
			}
		}
		solutionStream.read(reinterpret_cast<char*>(&i), sizeof(i));

		Solution solution = {
			id,
			name,
			0, 
			0,
			0,
			cycles,
			size,
			activity,
			entry.path()
		};
		// TODO: Battle data not saved in the file format?
		if (find(battles.begin(), battles.end(), id) != battles.end())
			solution.wins = 100;

		if (solution.cycles == 0 && solution.wins == 0)
			continue;

		for (int j = 0; j < i; j++) {
			solutionStream.ignore(); // Magic 0xA
			
			string name = readString(solutionStream);
			string source = readString(solutionStream);

			bool collapsed = solutionStream.get() > 0;
			bool local = solutionStream.get() > 0;

			solutionStream.seekg(100, ios::cur); // Skip Bitmap

			solution.exas.push_back({
				name,
				source,
				local
			});
		}

		// Only replace if cycles are lower
		if (solutions.find(id) != solutions.end()) {
			Solution old = solutions[id];
			if (old.cycles > solution.cycles) {
				cout << "  + " << id << ": " << name << endl;
				solutions[id] = solution;
			}
			else {
				cout << "  - " << id << ": " << name << endl;
			}
		} else {
			cout << "    " << id << ": " << name << endl;
			solutions[id] = solution;
		}
	}

	// Alright, now we can create the files / directories as needed
	// Clear all previous files
	cout << endl << "Clear previous files:" << endl;

	fs::path pathOutputSolutions = pathOutput / "solutions";
	if (fs::is_directory(pathOutputSolutions)) {
		fs::remove_all(pathOutputSolutions);
		cout << "    Clearing 'solutions' directory" << endl;
	}
	else {
		cout << "    No 'solutions' directory found" << endl;
	}

	fs::path pathOutputBattles = pathOutput / "battles";
	if (fs::is_directory(pathOutputBattles)) {
		fs::remove_all(pathOutputBattles);
		cout << "    Clearing 'battles' directory" << endl;
	}
	else {
		cout << "    No 'battles' directory found" << endl;
	}

	fs::path pathOutputBonus = pathOutput / "bonus";
	if (fs::is_directory(pathOutputBonus)) {
		fs::remove_all(pathOutputBonus);
		cout << "    Clearing 'bonus' directory" << endl;
	}
	else {
		cout << "    No 'bonus' directory found" << endl;
	}

	cout << endl << "Create files:" << endl;

	// Create README
	fs::path pathReadme = pathOutput / "README.md";
	ifstream readmeStream(pathReadme);
	if (!readmeStream) {
		cout << "    README not found, create new one" << endl;

		ofstream readmeOut(pathReadme);
		readmeOut << "# EXAPUNKS" << endl << endl << "<!-- EXA_START -->" << endl << "<!-- EXA_END -->" << endl;
		readmeOut.close();

		readmeStream.open(pathReadme);
	}
	else {
		cout << "    README found!" << endl;
	}

	// Find magic comment to insert table
	fs::path pathReadmeTemp = pathOutput / "README.md.temp";
	ofstream readmeOut(pathReadmeTemp);

	bool skip = false;
	while (getline(readmeStream, line)) {
		if (line == "<!-- EXA_START -->") {
			readmeOut << line << endl;
			skip = true;

			// Print solutions
			readmeOut << "#### Levels" << endl;
			readmeOut << "| Level";
			for (int i = 0; i < maxChars - 5 + 1 + 4; i++) readmeOut << ' ';
			readmeOut << "| Cycles | Size | Activity |" << endl;

			readmeOut << "|";
			for (int i = 0; i < maxChars + 2 + 4; i++) readmeOut << '-';
			readmeOut << "|--------|------|----------|" << endl;

			for (int i = 0; i < levels.size(); i++) {
				Info info = dataMap[levels[i]];
				const auto& solutionEntry = solutions.find(levels[i]);
				if (solutionEntry == solutions.end()) {
					readmeOut << "| " << to_string(i + 1) << ": " << info.title << " | N/A | N/A | N/A |" << endl;
				} else {
					readmeOut << "| [" << to_string(i + 1) << ": " << info.title << "](solutions/" << info.path << ") ";

					Solution solution = solutionEntry->second;
					readmeOut << "| ";
					writeNum(readmeOut, solution.cycles, CYCLE_N);
					readmeOut << " | ";
					writeNum(readmeOut, solution.size, SIZE_N);
					readmeOut << " | ";
					writeNum(readmeOut, solution.activity, ACTIVITY_N);
					readmeOut << " |" << endl;
				}
			}

			// Print battle solutions
			readmeOut << "#### Battles" << endl;
			for (int i = 0; i < battles.size(); i++) {
				Info info = dataMap[battles[i]];

				const auto& solutionEntry = solutions.find(battles[i]);
				if (solutionEntry == solutions.end()) {
					readmeOut << " * " << to_string(i + 1) << ": " << info.title << "- N/A" << endl;
				} else {
					readmeOut << " * [" << to_string(i + 1) << ": " << info.title << "](battles/" << info.path << ")" << endl;
				}
			}
			// readmeOut << endl << "| Battle";
			// for (int i = 0; i < maxChars - 5 + 3; i++) readmeOut << ' ';
			// readmeOut << "| Wins | Draws | Losses | Rating |" << endl;
			//
			// readmeOut << "|";
			// for (int i = 0; i < maxChars + 2 + 3; i++) readmeOut << '-';
			// readmeOut << "|------|-------|--------|--------|" << endl;
			//
			// for (int i = 0; i < battles.size(); i++) {
			// 	Info info = dataMap[battles[i]];
			//
			// 	const auto& solutionEntry = solutions.find(battles[i]);
			// 	if (solutionEntry == solutions.end()) {
			// 		readmeOut << "| " << to_string(i + 1) << ": " << info.title << " | N/A | N/A | N/A |" << endl;
			// 	} else {
			// 		readmeOut << "| [" << to_string(i + 1) << ": " << info.title << "](battles/" << info.path << ") ";
			//
			// 		Solution solution = solutionEntry->second;
			//
			// 		readmeOut << "| ";
			// 		writeNum(readmeOut, solution.wins, 4);
			// 		readmeOut << " | ";
			// 		writeNum(readmeOut, solution.draws, 5);
			// 		readmeOut << " | ";
			// 		writeNum(readmeOut, solution.losses, 6);
			// 		readmeOut << " | S+     |" << endl;
			// 	}
			// }

			// Print bonus
			readmeOut << "#### Bonus" << endl;
			readmeOut << endl << "| Bonus campaign level";
			for (int i = 0; i < maxChars - 5 + 1 + 4; i++) readmeOut << ' ';
			readmeOut << "| Cycles | Size | Activity |" << endl;

			readmeOut << "|";
			for (int i = 0; i < maxChars + 2 + 4; i++) readmeOut << '-';
			readmeOut << "|--------|------|----------|" << endl;

			for (int i = 0; i < bonus.size(); i++) {
				Info info = dataMap[bonus[i]];

				const auto& solutionEntry = solutions.find(bonus[i]);
				if (solutionEntry == solutions.end()) {
					readmeOut << "| " << to_string(i + 1) << ": " << info.title << " | N/A | N/A | N/A |" << endl;
				} else {
					readmeOut << "| [" << to_string(i + 1) << ": " << info.title << "](bonus/" << info.path << ") ";

					Solution solution = solutionEntry->second;
					readmeOut << "| ";
					writeNum(readmeOut, solution.cycles, CYCLE_N);
					readmeOut << " | ";
					writeNum(readmeOut, solution.size, SIZE_N);
					readmeOut << " | ";
					writeNum(readmeOut, solution.activity, ACTIVITY_N);
					readmeOut << " |" << endl;
				}
			}
		}
		else if (line == "<!-- EXA_END -->") {
			readmeOut << line << endl;
			skip = false;
		}
		else if (!skip) {
			readmeOut << line << endl;
		}
	}

	// Replace README
	readmeStream.close();
	readmeOut.close();
	remove(pathReadme);
	rename(pathReadmeTemp, pathReadme);

	// Create solutions folder
	fs::create_directories(pathOutputSolutions);

	cout << endl << "  Making solutions:" << endl;

	for (int i = 0; i < levels.size(); i++) {
		Info info = dataMap[levels[i]];
		const auto& solutionEntry = solutions.find(levels[i]);
		if (solutionEntry == solutions.end()) {
			cout << "Solution not found for " << info.id << " - skipping..." << endl;
			continue;
		}
		Solution solution = solutionEntry->second;
		cerr << solution.name << " " << solution.cycles << " " << solution.id << " " << levels[i] << endl;

		fs::create_directories(pathOutputSolutions / info.path);
		ofstream readmeOut(pathOutputSolutions / info.path / "README.md");

		readmeOut << "# " << to_string(i + 1) << ": " << info.title << endl << endl;

		// Copy GIF
		const auto& gifEntry = gifMap.find(info.id);
		if (gifEntry == gifMap.end()) {
			cout << "GIF not found for solution ID " << info.id << " - " << info.title << endl;
			cout << "Please export all your GIFs into the gifs folder and make sure that their creation timestamps are in the right order!" << endl;
			return 1;
		}
		const fs::path& gifPath = gifEntry->second;
		fs::copy(gifPath, pathOutputSolutions / info.path / gifPath.filename());
		readmeOut << "<div align=\"center\"><img src=\"" << gifPath.filename().string() << "\" /></div>" << endl << endl;

		// Read description files
		ifstream descriptionStream(pathDescriptions / info.description);
		if (descriptionStream) {
			readmeOut << "## Instructions" << endl;
			while (getline(descriptionStream, line)) {
				readmeOut << "> " << line << endl;
			}
			readmeOut << endl;
		}

		readmeOut << "## Solution" << endl << endl;

		// Add source as well
		for (int j = 0; j < solution.exas.size(); j++) {
			EXA exa = solution.exas[j];
			readmeOut << "### [" << exa.name << "](" << exa.name << ".exa) (" << (exa.local ? "local" : "global") << ")" << endl;
			readmeOut << "```asm" << endl;
			readmeOut << exa.source << endl;
			readmeOut << "```" << endl << endl;

			// Generate file as well
			ofstream exaOut(pathOutputSolutions / info.path / (exa.name + ".exa"));
			exaOut << exa.source;
		}

		// Copy OG file save as well
		fs::copy(solution.path, pathOutputSolutions / info.path / solution.path.filename());

		// Add score
		readmeOut << "#### Results" << endl;
		readmeOut << "| Cycles | Size | Activity |" << endl;
		readmeOut << "|--------|------|----------|" << endl;
		readmeOut << "| ";
		writeNum(readmeOut, solution.cycles, CYCLE_N);
		readmeOut << " | ";
		writeNum(readmeOut, solution.size, SIZE_N);
		readmeOut << " | ";
		writeNum(readmeOut, solution.activity, ACTIVITY_N);
		readmeOut << " |" << endl;

		cout << info.id << " - " << info.title << " - " << gifEntry->second << endl;
	}

	// Create battles folder
	fs::create_directories(pathOutputBattles);

	cout << endl << "  Making battles:" << endl;

	for (int i = 0; i < battles.size(); i++) {
		Info info = dataMap[battles[i]];
		const auto& solutionEntry = solutions.find(battles[i]);
		if (solutionEntry == solutions.end()) {
			cout << "Solution not found for " << info.id << " - skipping..." << endl;
			continue;
		}
		Solution solution = solutionEntry->second;

		fs::create_directories(pathOutputBattles / info.path);
		ofstream readmeOut(pathOutputBattles / info.path / "README.md");

		readmeOut << "# " << to_string(i + 1) << ": " << info.title << endl << endl;

		// Copy GIF
		const auto& gifEntry = gifMap.find(info.id);
		if (gifEntry == gifMap.end()) {
			cout << "GIF not found for battle ID " << info.id << " - " << info.title << endl << endl;
			cout << "Please export all your GIFs into the gifs folder and make sure that their creation timestamps are in the right order!" << endl;
			return 1;
		}
		const fs::path& gifPath = gifEntry->second;
		fs::copy(gifPath, pathOutputBattles / info.path / gifPath.filename());
		readmeOut << "<div align=\"center\"><img src=\"" << gifPath.filename().string() << "\" /></div>" << endl << endl;

		// Read description files
		ifstream descriptionStream(pathDescriptions / info.description);
		if (descriptionStream) {
			readmeOut << "## Instructions" << endl;
			while (getline(descriptionStream, line)) {
				readmeOut << "> " << line << endl;
			}
			readmeOut << endl;
		}

		readmeOut << "## Solution" << endl << endl;

		// Add source as well
		for (int j = 0; j < solution.exas.size(); j++) {
			EXA exa = solution.exas[j];
			readmeOut << "### [" << exa.name << "](" << exa.name << ".exa) (" << (exa.local ? "local" : "global") << ")" << endl;
			readmeOut << "```asm" << endl;
			readmeOut << exa.source << endl;
			readmeOut << "```" << endl << endl;

			// Generate file as well
			ofstream exaOut(pathOutputBattles / info.path / (exa.name + ".exa"));
			exaOut << exa.source;
		}

		// Copy OG file save as well
		fs::copy(solution.path, pathOutputBattles / info.path / solution.path.filename());

		cout << info.id << " - " << info.title << " - " << gifEntry->second << endl;
	}

	// Create bonus folder
	fs::create_directories(pathOutputBonus);

	cout << endl << "  Making bonus:" << endl;

	for (int i = 0; i < bonus.size(); i++) {
		Info info = dataMap[bonus[i]];
		const auto& solutionEntry = solutions.find(bonus[i]);
		if (solutionEntry == solutions.end()) {
			cout << "Solution not found for " << info.id << " - skipping..." << endl;
			continue;
		}
		Solution solution = solutionEntry->second;

		fs::create_directories(pathOutputBonus / info.path);
		ofstream readmeOut(pathOutputBonus / info.path / "README.md");

		readmeOut << "# " << to_string(i + 1) << ": " << info.title << endl << endl;

		// Copy GIF
		const auto& gifEntry = gifMap.find(info.id);
		if (gifEntry == gifMap.end()) {
			cout << "GIF not found for bonus ID " << info.id << " - " << info.title << endl << endl;
			cout << "Please export all your GIFs into the gifs folder and make sure that their creation timestamps are in the right order!" << endl;
			return 1;
		}
		const fs::path& gifPath = gifEntry->second;
		fs::copy(gifPath, pathOutputBonus / info.path / gifPath.filename());
		readmeOut << "<div align=\"center\"><img src=\"" << gifPath.filename().string() << "\" /></div>" << endl << endl;

		// Read description files
		ifstream descriptionStream(pathDescriptions / info.description);
		if (descriptionStream) {
			readmeOut << "## Instructions" << endl;
			while (getline(descriptionStream, line)) {
				readmeOut << "> " << line << endl;
			}
			readmeOut << endl;
		}

		readmeOut << "## Solution" << endl << endl;

		// Add source as well
		for (int j = 0; j < solution.exas.size(); j++) {
			EXA exa = solution.exas[j];
			readmeOut << "### [" << exa.name << "](" << exa.name << ".exa) (" << (exa.local ? "local" : "global") << ")" << endl;
			readmeOut << "```asm" << endl;
			readmeOut << exa.source << endl;
			readmeOut << "```" << endl << endl;

			// Generate file as well
			ofstream exaOut(pathOutputBonus / info.path / (exa.name + ".exa"));
			exaOut << exa.source;
		}

		// Copy OG file save as well
		fs::copy(solution.path, pathOutputBonus / info.path / solution.path.filename());

		// Add score
		readmeOut << "#### Results" << endl;
		readmeOut << "| Cycles | Size | Activity |" << endl;
		readmeOut << "|--------|------|----------|" << endl;
		readmeOut << "| ";
		writeNum(readmeOut, solution.cycles, CYCLE_N);
		readmeOut << " | ";
		writeNum(readmeOut, solution.size, SIZE_N);
		readmeOut << " | ";
		writeNum(readmeOut, solution.activity, ACTIVITY_N);
		readmeOut << " |" << endl;

		cout << info.id << " - " << info.title << " - " << gifEntry->second << endl;
	}
}
