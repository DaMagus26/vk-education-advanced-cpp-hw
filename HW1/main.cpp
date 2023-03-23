#include <iostream>
#include <vector>
#include <map>
#include <boost/program_options.hpp>
#include "parse_tables.h"
#include "validations.h"


int main(int argc, char **argv) {

  po::options_description desc("Allowed options");
  desc.add_options()
      ("help", "produce help message")
      ("name", po::value<std::string>(), "Name of the actor, that one is trying to find info about")
      ("names_basics_path", po::value<std::string>(),
          "Path to file, containing general information about people")
      ("titles_akas_path", po::value<std::string>(),
          "Path to file, containing aliases for the titles")
      ("titles_basics_path", po::value<std::string>(),
       "Path to file, containing basic information about the titles")
      ("titles_principals_path", po::value<std::string>(),
       "Path to file, containing information about principals of the titles")
      ("titles_reviews_path", po::value<std::string>(),
       "Path to file, containing information about ratings of the title");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  std::string actor_name;
  std::string name_basics_path;
  std::string akas_path;
  std::string basics_path;
  std::string principals_path;
  std::string reviews_path;

  if (!ValidateAndStore(vm, "name", actor_name)) {
    return 0;
  }

  if (!ValidateAndStore(vm, "names_basics_path", name_basics_path)) {
    return 0;
  }

  if (!ValidateAndStore(vm, "titles_akas_path", akas_path)) {
    return 0;
  }

  if (!ValidateAndStore(vm, "titles_basics_path", basics_path)) {
    return 0;
  }

  if (!ValidateAndStore(vm, "titles_principals_path", principals_path)) {
    return 0;
  }

  if (!ValidateAndStore(vm, "titles_reviews_path", reviews_path)) {
    return 0;
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
