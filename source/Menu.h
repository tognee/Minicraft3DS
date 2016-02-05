#pragma once

#include "MenuTutorial.h"
#include "texturepack.h"

void initMenus();

void renderMenu(int menu,int xscr,int yscr);
void tickMenu(int menu);

void menuRenderTilePit(int x,int y,int xt,int yt,u32 color);
