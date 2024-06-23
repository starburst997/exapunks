# EXA-Parser
Simple C++17 script to automatically create [this repo](https://github.com/starburst997/EXAPUNKS) by parsing the save files from the game [EXAPUNKS](https://store.steampowered.com/app/716490/EXAPUNKS/) by [Zachtronics](https://www.zachtronics.com/).

I really enjoyed it and wanted to showcase my solutions (and possibly revisit them later on) so I made this CLI tool as a before-going-to-bed project. I was inspired by other repos as well, like [this one](https://github.com/StinkingBanana/exapunks-solutions) or [that one](https://github.com/Seraphli/EXAPunks), but I felt like the presentation could be improved by [showing everything in a README](https://github.com/starburst997/EXAPUNKS/tree/main/solutions/23-xtreme-league-baseball-player-database), giving better insight and making things easier to follow. 

I loved comparing the different solutions people came up with after I finished the game and wanted to improve that experience.

## Features
- [README for each solution](https://github.com/starburst997/EXAPUNKS/tree/main/solutions/22-alliance-power-and-light-streetsmarts-gis-database)
  - Display GIF
  - Display level's instruction
  - All EXAs code inline
  - Display if EXA is local / global
  - Results (cycles / size / activity)
- Keep only the solutions with the less cycles
- Keep original save files
- Text files (`.exa`) for each EXAs 
- Separate folder for battles / levels
- Main README with lists (including scores)

## Usages

#### Fork

Fork this repo (or clone this repo and run the executable specifying a different output folder to start a fresh empty repo without the parser as well).

#### Prepare GIFs

Clear your desktop of any GIFs. Open the game and generate the GIFs for each solutions chronologically, they are saved on the desktop by default.

#### Temp folder (optional)

The default arguments read from an ignored `temp` folder at the root of this repo. For simplicity sake you can create that folder and include the required files in it.

- `/temp/`
  - `descriptions/`: copy text files from the game locale (ex: `en`) folder
  - `gifs/`: all your recorded GIFs, move from desktop
  - `saves/`: copy of all save files

#### Run

Compile the code (`EXA-Parser.cpp`) and run it! If you used the `temp` folder, there is nothing to do. Otherwise you need to specify each folder's location by arguments:

1. Directory for save files
2. Directory for GIFs
3. Directory to descriptions text
4. Output directory (by default, the repo itself (ex: `..`))
5. `data.txt` location

#### Tweak README and push!

`git add . && git commit . && git push` your repo! All of the files should've been generated automatically. Don't forget to tweak the root `README` file (only the text between `<!-- EXA_START -->` and `<!-- EXA_END -->` will get replaced).

## Locations

### Descriptions text

From game directory:
`EXAPUNKS\Content\Content\descriptions\en`

### Save files

Gamepass PC:
```
%LOCALAPPDATA%\Packages\58020AllianceMetaversalSt.EXAPUNKS_j78hpz8e66gfw\SystemAppData\xgs\0009000000DE7310_00000000000000000000000065287F60\all
```

Windows:
```
%USERPROFILE%\Documents\My Games\EXAPUNKS\<user-id>\
```

Mac:
```
$HOME/Library/Application Support/EXAPUNKS/<user-id>/
```

Linux:
```
~/.local/share/EXAPUNKS/<user-id>/
```

## [data.txt](data.txt)

This is a small file I made up while "reverse-engineering" the file format. Each line represent the `id`, `locale file` and `title` for each level. It is currently missing the "Bonus" levels.

## Workaround to use last opened solutions

The EXA_Parser goes through all solutions and uses the fastest one. If you like to use the last opened Solution you can go to the solution directory and run the following:
```
mkdir tmp
for i in *.solution; do grep LastSolutionOpen.*${i%.solution} save.dat || mv  -v ${i} tmp/; done
```
Thus the last opened solutions are the only ones around forcing EXA-Parser to use those.
Now create the repo with EXA-parser and finaly undo this workaround by:
```
mv tmp/* .
rm -r tmp
```
It's probably a good idea not to have the game open at the time.

## Issues
Generated GIFs name are *bad*, the first 4 levels are all named "EXAPUNKS - TRASH WORLD NEWS". So you need to generate the GIFs in chronological order and not have any duplicates.

Battles stats are not saved in the file format it seems. You need to update the README manually after being generated if you didn't score `100` for each of them.

## Contact
If you used this tool to create a repo please send it my way to `jd@boiv.in`! Or simply fork this repo and I'll get a notification.

*A hacker at heart, I'm always looking for **freelance** / **contract** work, feel free to get in touch!*

Enjoy!
