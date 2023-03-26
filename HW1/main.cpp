#include <iostream>
#include <vector>
#include <map>
#include "parse_tables.h"
#include "validations.h"
#include "argparse.h"


int main(int argc, const char **argv) {
  auto cmd_arguments = ParseCmdLineOptions(argc, argv);

  std::string actor_name;
  std::string name_basics_path;
  std::string akas_path;
  std::string basics_path;
  std::string principals_path;
  std::string reviews_path;

  if (!ValidateAndStore(cmd_arguments, "name", actor_name) ||
      !ValidateAndStore(cmd_arguments, "names_basics_path", name_basics_path) ||
      !ValidateAndStore(cmd_arguments, "titles_akas_path", akas_path) ||
      !ValidateAndStore(cmd_arguments, "titles_basics_path", basics_path) ||
      !ValidateAndStore(cmd_arguments, "titles_principals_path", principals_path) ||
      !ValidateAndStore(cmd_arguments, "titles_reviews_path", reviews_path)) {
    std::cerr << "Invalid arguments" << std::endl;
    return 1;
  }

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
