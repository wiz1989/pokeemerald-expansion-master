# Start Menu Clock
This is a feature branch for [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion) that adds a clock that tracks the in-game time to the start menu, as seen below.

My implementation is a modified version of part of this [commit](https://github.com/BluRosie/em-remake/commit/4999f9ca4efe5b4b8fec8172cf2a7c364e0ad07e) from BluRosie that was shared a few years ago, that put playtime in the same location. Please credit them rather than me, they did all the difficult work.

![image](https://github.com/Pawkkie/pokeemerald-expansion/assets/61265402/42034ce7-713b-44f4-bb9e-99ff269fb4ba)

While the branch is intended to be used in cases where the in-game clock has been sped up and is no longer synced with the real time clock, it can certainly be used in both cases if you'd like to include a portable clock display.

I don't have a setting for it, but you can manually change the clock to a 24-hour mode if you prefer. Just change the conditional at the top of `ShowTimeWindow` in `start_menu.c`.

Lastly, if you do speed up the in-game clock, it's possible the start menu clock won't refresh as fast as you'd like it to. You can increase the refresh rate by adjusting the `if (!GetSafariZoneFlag() && !InBattlePyramid() && gSaveBlock2Ptr->playTimeSeconds == 0) ` condition in the `HandleStartMenuInput` function.

By default the clock refreshes every time playTimeSeconds hits 0. Feel free to change this as you see fit.
