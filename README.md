# Emulator accuracy check

This is a feature branch that implements emulator hardware checks to restrict access of certain emulators to your games.
A popular use case would be restricting it for MyBoy since its inaccurate core often causes crashes or unexpected bugs with your hacks.

This solution was created in a very stand-alone way so it is very easy to implement into projects based on
- pokefirered
- pokeemerald
- pokeemerald-expansion
<br/>

## What's included / How to use

If you are not able to automatically merge this branch (pokefirered/pokeemerald should work immediately) here are all new files:

- `src/emulator_check.c`
- `include/emulator_check.h`
- `include/config/emulator_check.h`
- `graphics/intro/emulator_check` containing several graphics files

To call the accuracy check simply add the following two lines to `AgbMain()` in `main.c` directly after `InitHeap()`

```
if (IsInaccurateEmulator())
    RunEmulatorCheckUI(CB2_InitCopyrightScreenAfterBootup);
```
<br/>

## How does it work?
The main function that handles the hardware check is `IsInaccurateEmulator()`. It will execute the defined check(s) from the config file and return TRUE/FALSE based on the result.
If it returns TRUE then a separate error screen UI is called instead of continuing with the regular game start.
The different checks are defined as bitmasks and can be combined if you would want that.

There are plenty customizations that can be done from the config file:

**ERROR_MUSIC** defines the music that's playing for the error screen.\
**SPRITE_MODE** defines the sprites shown on the error screen. Effectively showing either Pikachu (vanilla) or Egg (expansion).\
**ANIM_SPEED, FADING_STRIPES** define the behavior of the scrolling bg (top and bottom lines).\
**ALLOW_BOOT_CONTINUATION** enables a forced game load using **BOOT_CONTINUATION_KEY** if you want to give the player the option to still continue.\
**ACTIVE_EMU_CHECKS** defines the chosen hardware check(s).

The config file also contains explanations for all implemented hardware checks and their compatibility with different popular GBA emulators.

Finally, the **EMU_PASSES_** defines hold the information about which of the recommended emulators (mGBA, RetroArch, Lemuroid, Pizzaboy) are compatible whith which of the checks. So the "recommended emulators list" shown on the error screen only shows emulators that are compatible with the currently chosen hardware check(s).\
<br/>

## Credits

- code by [wiz1989](https://github.com/wiz1989)
- graphic assets by [mudskip](https://github.com/mudskipper13)
- sample UI template by [grunt-lucas](https://github.com/grunt-lucas/)
- the new GBA UI bible by [Archie](https://github.com/TeamAquasHideout)
- Android emulator tests done by Drazden
<br/>

## AI disclosure

Since this is both a very hot and controverse topic at the moment, I'd like to be transparent about my own modus operandi.

While I am writing almost all of my code myself and always review and govern every single line included in my changes, I still want to point out that I am currently using GitHub Copilot for some tasks.

Here is what I am using it for:
- Code reviews
- Debugging more complex scenarios
- auto completion (stuff like repeating lists, DebugPrints, etc.)
- creating py scripts for I/O procedures (like downloading/writing list data, I/O data with Excel, etc.)

In the context of this feature branch I also used it to crawl through https://problemkaputt.de/gbatek.htm and https://emulation.gametechwiki.com/index.php/GBA_Tests
and help me setting up the actual hardware checks.

