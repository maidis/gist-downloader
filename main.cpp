// The great GIFs of @beesandbombs made me do this
// https://twitter.com/beesandbombs
#include <iostream>
#include <fstream>
//#include <vector>

#include <cpr/cpr.h>
#include <json.hpp>

// story of this namespace: this is a hobby project of @nlohmann
// https://github.com/nlohmann/json/issues/9
using json = nlohmann::json;

int main(int argc, char *argv[])
{
    // thanks to short-circuit evaluation this works, but i'm going to
    // use a c++ command line option parser library for next projects
    if (argc != 2 or std::string(argv[1]) == "--help" or std::string(argv[1]) == "-h")
    {
        std::cout << "Downloads all gists of a given GitHub user\n"
                  << "Example usage: gist-downloader beesandbombs\n";
        return 0;
    }
    else
    {
        json j;
        int page = 1;
        bool firstRun = true;

        do
        {
            // https://developer.github.com/v3/gists/
            // https://developer.github.com/v3/#pagination
            std::string gistsAddress = std::string("https://api.github.com/users/") +
                                       argv[1] +
                                       "/gists?page=" +
                                       std::to_string(page) +
                                       "&per_page=100";

            // https://whoshuu.github.io/cpr/
            auto r = cpr::Get(cpr::Url{gistsAddress},
                              cpr::Header{{"Content-Type", "application/json"}},
                              cpr::Header{{"User-Agent", "maidis"}});

            // https://nlohmann.github.io/json/
            j = json::parse(r.text);

            //std::vector<std::string> gists = {" "};
            //std::vector<std::string> gistsRawAddress = {" "};

            // ex: torvalds
            if(firstRun and j.empty())
            {
                std::cout << "User has no gist\n";
                return 0;
            }

            auto checkErrors = j.find("message");

            //std::cout << *checkErrors << '\n';

            // ex: --hel
            if(firstRun and checkErrors != j.end())
            {
                std::cout << "There is no such user at GitHub\n"
                          << "or something else went wrong.\n";
                return 0;
            }

            firstRun = false;

            for (auto& element : j)
            {
                //gists.push_back(element["files"].get<std::string>());
                json hede = element["files"];

                for (auto& element2 : hede)
                {
                    auto raw_url = element2.find("raw_url");
                    //std::cout << *raw_url << '\n';

                    std::string gistAddress= *raw_url;

                    auto r2 = cpr::Get(cpr::Url{gistAddress},
                                       cpr::Header{{"Content-Type", "application/json"}},
                                       cpr::Header{{"User-Agent", "maidis"}});

                    auto filename = element2.find("filename");
                    //std::cout << *filename << '\n';
                    std::string filename2 = *filename;

                    auto id = element.find("id");
                    //std::cout << *id << '\n';
                    std::string id2 = *id;

                    std::string theName = id2 + "-" + filename2;

                    std::ofstream gistFile;
                    gistFile.open(theName);
                    gistFile << r2.text;
                    gistFile.close();

                    std::cout << theName << " saved ✔️\n";
                }
            }
            ++page;
        }while(!j.empty());
    }
    std::cout << "Happy Hacking 🐱‍💻\n";
    return 0;
}
