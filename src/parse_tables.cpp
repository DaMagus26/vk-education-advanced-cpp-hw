#include "parse_tables.h"
#include "string_actions.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>

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