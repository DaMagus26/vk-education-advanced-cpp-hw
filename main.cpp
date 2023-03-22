#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <set>
#include <chrono>
#include <iterator>


//const std::filesystem::path data_path = "../data/title.basics.tsv";
struct Movie {
  std::string tconst;
  std::string language;
  std::string title_name;
  explicit Movie(std::string tconst) : tconst(std::move(tconst)) {};
  bool operator< (const Movie &x) const {
    return tconst < x.tconst;
  }
};

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
  std::cout << "No matches found for \"" << name << "\"" << std::endl;
  input.close();
  return "";
}

void FindAllMoviesWithActor(const std::string &nconst, const std::string &path, std::set<Movie> &titles) {
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
  auto start = std::chrono::high_resolution_clock::now();
  int counter = 0;
  while (getline(input, line)) {
    if (line.find(nconst) != std::string::npos) {
      std::vector<std::string> columns;
      SplitString(line, std::back_inserter(columns));
      if (columns[2] == nconst && (columns[3] == "actor" || columns[3] == "actress")) {
        titles.insert(Movie(columns[0]));
      }
    }

    counter++;
    if (counter % 10000000 == 0) {
      auto stop = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
      std::cout << counter << " rows (" << static_cast<double>(duration.count()) / 1000 << " seconds, speed: " << 10000000000.0 / duration.count() << " rows/sec)" << std::endl;
      start = stop;
    }
  }
  input.close();
}

void DropUnratedMovies(const std::vector<Movie>& titles, const std::string &path) {
  if (titles.empty()) {
    return;
  }

  std::ifstream input(path);
  if (!input) {
    std::cerr << "Invalid path: " << path << std::endl;
    return;
  }

  std::cout << "Starting \"DropUnratedMovies\"" << std::endl;
  std::string line;
  getline(input, line);
  auto start = std::chrono::high_resolution_clock::now();
  int counter = 0;
  while (getline(input, line)) {
//    if (line.find(nconst) != std::string::npos) {
//    std::vector<std::string> columns;
//    SplitString(line, std::back_inserter(columns));
//    if (columns[2] == nconst && (columns[3] == "actor" || columns[3] == "actress")) {
//      titles.insert(Movie(columns[0]));
//    }
//    }

    counter++;
    if (counter % 10000000 == 0) {
      auto stop = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
      std::cout << counter << " rows (" << static_cast<double>(duration.count()) / 1000 << " seconds, speed: " << 10000000000.0 / duration.count() << " rows/sec)" << std::endl;
      start = stop;
    }
  }
  input.close();
}

void DropIrrelevantMovies(const std::vector<Movie>& titles, const std::string &path) {}

void GetLocalizedTitleNames(const std::vector<Movie>& titles, const std::string &path) {}

int main(int argc, char **argv) {
  std::string actor_name = argv[1];
  std::string name_basics_path = argv[2];
  std::string akas_path = argv[3];
  std::string basics_path = argv[4];
//  std::string crew_path = argv[5];
//  std::string episode_path = argv[6];
  std::string principals_path = argv[7];
  std::string reviews_path = argv[8];

  std::string nconst = FindActorId(actor_name, name_basics_path); // "nm0642253"
  std::set<Movie> titles;
  FindAllMoviesWithActor(nconst, principals_path, titles);
  for (const auto& x: titles) {
    std::cout << x.tconst << " ";
  }
}
