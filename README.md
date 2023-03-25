# Домашнее задание №1 по курсу "Углубленное программирование на C++"
Выполнил: Овакимян Михаил Алексеевич \
Группа: ML-11 \
Вариант №7

## Текст задания
Вывести русские названия (при наличии) всех фильмов, в которых играл актер, имя которого переданно в
аргументах командной строки.

Программа не должна брать в расчет фильмы для взрослых, и, если в варианте используется рейтинг, не должна учитывать
рейтинг фильмов с числом оценок меньше 1000.


## Запуск программы
Для запуска программы у себя выполните следующие шаги:

1. Клонируйте репозиторий в свою директорию:
```shell
git clone https://github.com/DaMagus26/vk-education-advanced-cpp-hw1.git
```
2. Убедитесь, что у вас загружены данные о кинокартинах с [сайта IMDB](https://datasets.imdbws.com/). Каждую таблицу можно скачать командой:
```shell
wget https://datasets.imdbws.com/title.basics.tsv.gz
```
Полученные файлы нужно распаковать
```shell
gunzip title.basics.tsv
```
3. Программа использует библиотеку Boost и сборщик CMake. Убедитесь, что она у вас загружена. Скачать библиотеку на Linux/Mac можно командой
```shell
brew install boost
brew install cmake
```
или
```shell
sudo apt-get install libboost-all-dev
sudo apt-get install cmake
```
4. Соберите приложение. Для этого выполните следующие команды:
```shell
mkdir build
cd build
cmake ..
cmake --build .
```
5. Запустите программу. Исполняемый файл находится в директории build. Программа принимает на вход 6 именованных аргументов
   - **--name**: имя актера, фильмографию которого вы хотите найти
   - **--names_basics_path**: таблица с данными об именах (names.basics.tsv)
   - **--titles_akas_path**: таблица с данными о локализации картин (titles.akas.tsv)
   - **--titles_basics_path**: таблица с общими данными о картинах (titles.basics.tsv)
   - **--titles_principals_path**: таблица с данными о создателях картин (titles.principals.tsv)
   - **--titles_reviews_path**: таблица с данными об отзывах картин (titles.reviews.tsv)

Пример команды запуска:
```shell
./searchtitles --name="Safi Quadri" --names_basics_path=../data/name.basics.tsv --titles_akas_path=../data/title.akas.tsv --titles_basics_path=../data/title.basics.tsv --titles_principals_path=../data/title.principals.tsv --titles_reviews_path=../data/title.ratings.tsv
```
   

## Описание данных
![Диаграмма таблиц](images/tables.png?raw=true)

1. **name.basics.tsv** – информация о людях
   - nconst (string) - alphanumeric unique identifier of the name/person
   - primaryName (string)– name by which the person is most often credited
   - birthYear – in YYYY format
   - deathYear – in YYYY format if applicable, else '\N'
   - primaryProfession (array of strings)– the top-3 professions of the person
   - knownForTitles (array of tconsts) – titles the person is known for
2. **title.akas.tsv** – информация о названиях картин
   - _titleId_ (string) - a tconst, an alphanumeric unique identifier of the title
   - _ordering_ (integer) – a number to uniquely identify rows for a given titleId
   - _title_ (string) – the localized title
   - _region_ (string) - the region for this version of the title
   - _language_ (string) - the language of the title
   - _types_ (array) - Enumerated set of attributes for this alternative title. One or more of the following: "alternative", "dvd", "festival", "tv", "video", "working", "original", "imdbDisplay". New values may be added in the future without warning
   - _attributes_ (array) - Additional terms to describe this alternative title, not enumerated
   - _isOriginalTitle_ (boolean) – 0: not original title; 1: original title
3. **title.basics.tsv** – информация о картинах
   - _tconst_ (string) - alphanumeric unique identifier of the title
   - _titleType_ (string) – the type/format of the title (e.g. movie, short, tvseries, tvepisode, video, etc)
   - _primaryTitle_ (string) – the more popular title / the title used by the filmmakers on promotional materials at the point of release
   - _originalTitle_ (string) - original title, in the original language
   - _isAdult_ (boolean) - 0: non-adult title; 1: adult title
   - _startYear_ (YYYY) – represents the release year of a title. In the case of TV Series, it is the series start year
   - _endYear_ (YYYY) – TV Series end year. ‘\N’ for all other title types
   - _runtimeMinutes_ – primary runtime of the title, in minutes
   - _genres_ (string array) – includes up to three genres associated with the title
4. **title.crew.tsv** – режиссеры и директоры
   - tconst (string) - alphanumeric unique identifier of the title
   - directors (array of nconsts) - director(s) of the given title
   - writers (array of nconsts) – writer(s) of the given title
5. **title.episode.tsv** – информация об эпизодах сериала
   - tconst (string) - alphanumeric identifier of episode
   - parentTconst (string) - alphanumeric identifier of the parent TV Series
   - seasonNumber (integer) – season number the episode belongs to
   - episodeNumber (integer) – episode number of the tconst in the TV series
6. **title.principals.tsv** – информация о съемочной группе
   - tconst (string) - alphanumeric unique identifier of the title
   - ordering (integer) – a number to uniquely identify rows for a given titleId
   - nconst (string) - alphanumeric unique identifier of the name/person
   - category (string) - the category of job that person was in
   - job (string) - the specific job title if applicable, else '\N'
   - characters (string) - the name of the character played if applicable, else '\N'
7. **title.ratings.tsv** – информация об оценках картины
   - tconst (string) - alphanumeric unique identifier of the title
   - averageRating – weighted average of all the individual user ratings
   - numVotes - number of votes the title has received