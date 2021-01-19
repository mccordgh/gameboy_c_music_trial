@REM mod2gbt [mod file name] [-c to create .c file] [memory bank number]
mod2gbt matts_demo.mod song -c 2

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o main.o main.c
@REM output.c is created by mod2gbt
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o output.o output.c
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o gbt_player.o gbt_player.s
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o gbt_player_bank1.o gbt_player_bank1.s

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wl-yt1 -Wl-yo4 -Wl-ya0 -o music.gb main.o output.o gbt_player.o gbt_player_bank1.o

del *.o *.lst
