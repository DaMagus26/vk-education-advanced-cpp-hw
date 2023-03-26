#pragma once
#include <string>
#include <map>

std::string FindActorId(const std::string &name, const std::string &path);

void FindAllMoviesWithActor(const std::string &nconst, const std::string &path, std::map<std::string, std::string> &titles);

void DropUnratedMovies(std::map<std::string, std::string>& titles, const std::string &path);

void DropIrrelevantMovies(std::map<std::string, std::string>& titles, const std::string &path);

void GetLocalizedTitleNames(std::map<std::string, std::string>& titles, const std::string &path);