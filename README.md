# Strongholdunlock
![GitHub License](https://img.shields.io/github/license/DorianCoding/Strongholdunlock)
[![Github stars](https://img.shields.io/github/stars/DorianCoding/Strongholdunlock.svg)](https://github.com/DorianCoding/Strongholdunlock/stargazers)
<img alt="French flag" src="https://github.com/lipis/flag-icons/blob/main/flags/1x1/fr.svg" width="25">

**Stronghold Crusader games are the best medieval games that has ever existed so far. However they are aberrantly difficult. But, *there is always a solution*...**

----
Unlock all missions in Stronghold Crusader and/or Stronghold Crusader 2 (unlock software).
# Stronghold Crusader
## TODO
*The script should also work for non-Steam games.*
1. Disable Steam Cloud (get on Steam, click on the game, properties and disable Steam Cloud). Check that when launching the game, there is no message "Synchronization with Steam Cloud", else Steam will erase your local changes.
2. Look for this file `crusader.cfg`. It should be located in Documents/Stronghold crusader.
3. Clone this git or download the binary that corresponds to your OS (Windows/Linux). You can also recompile the source code `Stronghold.c`.
4. Put this executable in the same directory as the `crusader.cfg` file.
5. Open the cmd in this directory (right click/open in cmd) or type cmd in the search bar.
6. Type the name of the executable followed by the name of the file such as : `Stronghold_windows64.exe crusader.cfg`. *A copy of the previous file is automatically made so you don't have to worry about problems. However the program therefore needs permissions to write in this specific directory or will fail.*. The script should be very fast (less than 1s) and will respond to any termination signal.
7. Reopen the game and enjoy. All missions has been unlocked.
8. If you want to enable Steam Cloud again, delete your userdata located in Steam Programfiles (there is one folder per game, find the game by opening each cache and check the name of the game. When found, delete this folder and enable Steam Cloud on Steam and relaunch the game.

Feel free to ask for help!
## DIY (Do it yourself) - Linux recommended
As a information, here is what the software is doing:
On the file `crusader.cfg`, you have informations regarding your progress. As this file is a binary, you should translate it to hexadecimal.
`xxd crusader.cfg > crusader_hex.cfg`
Then open the file. The progression is written at byte 342 (for the 50 first mission) and at byte 422 (for the last 30 missions).
So to unlock all missions, you need to change those byte to the number of missions (50 gives `0x32` in hex and 30 gives `0x1e` in hex).
So just change those byte (two chars in hexadecimal) by those number and save the file. Of course, you need to revert the binary form using `xxd -r crusader_hex.cfg > crusader.cfg`.
This software is just performing thoses changes automatically, and is also saving the previous file.
## Information
This software just unlocks all missions. As missions are a single-mode campaign, it is your pleasure or not to do missions. This software does not bring any cheats during a party, whatever single or multiplayer.
Do not ***cheat to win***, because it is not a win, it is a **perfect fail**.
# Stronghold Crusader 2
## TODO
To unlock all missions in Stronghold Crusader 2 is way easier. On %userprofile%\Documents\Stronghold Crusader 2\Profiles, you have a file named : `campaign_manager_state.xml`.
It is a xml file, you can just edit it on any text editor and change all false values to true (search and replace). And all missions will be unlocked!
