// Launch configurations
// "Safi Quadri" ../data/name.basics.tsv ../data/title.akas.tsv ../data/title.basics.tsv ../data/title.principals.tsv ../data/title.ratings.tsv

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <map>
#include <chrono>
#include <iterator>


template<class Out>
void SplitString(const std::string &str, Out os, const char sep = '\t') {
  typedef std::string::const_iterator iter;
  auto not_sep = [sep](const char c) { return c != sep; };
  auto is_sep = [sep](const char c) { return c == sep; };

  iter i = str.begin();
  while (i != str.end()) {
    i = std::find_if(i, str.end(), not_sep);
    iter j = std::find_if(i, str.end(), is_sep);
    if (i != str.end()) {
      *os++ = std::string(i, j);
    }
    i = j;
  }
}

std::string FindActorId(const std::string &name, const std::string &path) {
  std::ifstream input(path);
  if (!input) {
    std::cerr << "Invalid path: " << path << std::endl;
    return "";
  }

  std::string line;
  getline(input, line);
  while (getline(input, line)) {
    if (line.find(name)) {
      std::vector<std::string> columns;
      SplitString(line, std::back_inserter(columns));
      if (columns[1] == name) {
        return columns[0];
      }
    }
  }
  input.close();
  return "";
}

void FindAllMoviesWithActor(const std::string &nconst, const std::string &path, std::map<std::string, std::string> &titles) {
  if (nconst.empty()) {
    return;
  }

  std::ifstream input(path);
  if (!input) {
    std::cerr << "Invalid path: " << path << std::endl;
    return;
  }

  std::string line;
  getline(input, line);
  while (getline(input, line)) {
    if (line.find(nconst) != std::string::npos) {
      std::vector<std::string> columns;
      SplitString(line, std::back_inserter(columns));
      if (columns[2] == nconst && (columns[3] == "actor" || columns[3] == "actress")) {
        titles.insert({columns[0], ""});
      }
    }
  }
  input.close();
}

void DropUnratedMovies(std::map<std::string, std::string>& titles, const std::string &path) {
  if (titles.empty()) {
    return;
  }

  std::ifstream input(path);
  if (!input) {
    std::cerr << "Invalid path: " << path << std::endl;
    return;
  }

  std::string line;
  getline(input, line);
  while (getline(input, line)) {
    std::vector<std::string> columns;
    SplitString(line, std::back_inserter(columns));
    if (titles.find(columns[0]) == titles.end() || std::stoi(columns[2]) < 1000) {
      titles.erase(columns[0]);
    }
  }
  input.close();
}

void DropIrrelevantMovies(std::map<std::string, std::string>& titles, const std::string &path) {
  if (titles.empty()) {
    return;
  }

  std::ifstream input(path);
  if (!input) {
    std::cerr << "Invalid path: " << path << std::endl;
    return;
  }

  std::string line;
  getline(input, line);
  while (getline(input, line)) {

    std::vector<std::string> columns;
    SplitString(line, std::back_inserter(columns));
    if (titles.find(columns[0]) != titles.end()) {
      if (!(columns[1] == "movie" || columns[1] == "tvMovie") || columns[4] == "1") {
        titles.erase(columns[0]);
      } else {
        titles[columns[0]] = columns[2];
      }
    }
  }
  input.close();
}

void GetLocalizedTitleNames(std::map<std::string, std::string>& titles, const std::string &path) {
  if (titles.empty()) {
    return;
  }

  std::ifstream input(path);
  if (!input) {
    std::cerr << "Invalid path: " << path << std::endl;
    return;
  }

  std::string line;
  getline(input, line);
  while (getline(input, line)) {

    std::vector<std::string> columns;
    SplitString(line, std::back_inserter(columns));
    if (titles.find(columns[0]) != titles.end()) {
      if (columns[3] == "RU") {
        titles[columns[0]] = columns[2];
      }
    }
  }
  input.close();
}

int main(int argc, char **argv) {
  std::string actor_name = argv[1];
  std::string name_basics_path = argv[2];
  std::string akas_path = argv[3];
  std::string basics_path = argv[4];
  std::string principals_path = argv[5];
  std::string reviews_path = argv[6];

  std::string nconst = FindActorId(actor_name, name_basics_path);

  if (nconst.empty()) {
    std::cout << "Unknown actor: " << actor_name << std::endl;
    return 0;
  }

  std::map<std::string, std::string> titles;
  FindAllMoviesWithActor(nconst, principals_path, titles);
  DropUnratedMovies(titles, reviews_path);
  DropIrrelevantMovies(titles, basics_path);
  GetLocalizedTitleNames(titles, akas_path);

  if (titles.empty()) {
    std::cout << "There are no relevant movies, which starred " << actor_name << std::endl;
  } else {
    for (const auto& x: titles) {
      std::cout << x.second << std::endl;
    }
  }
}
