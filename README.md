# gist-downloader

**gist-downloader** is a command line tool which written in C++, using [cpr](https://github.com/whoshuu/cpr) and [json](https://github.com/nlohmann/json) libraries can download all the gists of a specified user to the running directory. Downloading gists has never been easier!

gist-downloader automates the download process of Gist codes as much as possible. It's just a tool for my needs at the moment. If you needed any additional functionality please [create an issue](https://github.com/maidis/gist-downloader/issues/new) or create a pull request.

Currently it's not possible to download updated version of an already downloaded gist. So if you think that there are updated gists, please delete everything and download again.

# Usage

```bash
gist-downloader <github-user>
```

Example:

```bash
gist-downloader
Downloads all gists of a given GitHub user
Example usage: gist-downloader beesandbombs
```

```bash
gist-downloader torvalds
User has no gist
```

```bash
gist-downloader anilozbek
There is no such user at GitHub
or something else went wrong.
```

```bash
gist-downloader maidis
7c4efdeb8b8ba2d6620eb7b47d10218b-hede.cpp saved ✔️
7c4efdeb8b8ba2d6620eb7b47d10218b-hede.hpp saved ✔️
a32ec223bb26982489f72393992fd2ec-twitter-bookmarklet.js saved ✔️
742f014c1a172c24152b-group-happy-kitty.xml saved ✔️
5427744-epub2.py saved ✔️
5427741-layout.html saved ✔️
2346946-actions.py saved ✔️
936636-hata.sh saved ✔️
936614-actions.py saved ✔️
859321-tarama-penceresi.cpp saved ✔️
858823-opengl.cpp saved ✔️
856664-sadece-zaman.cpp saved ✔️
847641-inttostring3.cpp saved ✔️
847596-inttostring2.cpp saved ✔️
847591-inttostring1.cpp saved ✔️
844782-fare-nerede.cpp saved ✔️
843777-daha-normal-pencere.cpp saved ✔️
840716-rastgele.cpp saved ✔️
840518-gistfile1.cpp saved ✔️
Happy Hacking 🐱💻
```
