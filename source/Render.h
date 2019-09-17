#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Globals.h"
#include "MapGen.h"

sf2d_texture *playerLightBake;
sf2d_texture *lanternLightBake;
sf2d_texture *glowwormLightBake;
sf2d_texture *glowwormBigLightBake;
int offsetX, offsetY;
int playerScale;

void render(s32 xp, s32 yp, u32 xTile, u32 yTile, u8 bits);
void renderb(s32 xp, s32 yp, u32 xTile, u32 yTile, u8 bits, u32 color);
void renderr(s32 xp, s32 yp, u32 xTile, u32 yTile, u8 bits, float rotate);
void renderc(s32 xp, s32 yp, u32 xTile, u32 yTile, int sizeX, int sizeY, u8 bits);
void renderbc(s32 xp, s32 yp, u32 xTile, u32 yTile, int sizeX, int sizeY, u8 bits, u32 color);
void render16(s32 xp, s32 yp, u32 xTile, u32 yTile, u8 bits);
void render16c(s32 xp, s32 yp, u32 xTile, u32 yTile, u8 bits, float scaleX, float scaleY);
void render16b(s32 xp, s32 yp, u32 xTile, u32 yTile, u8 bits, u32 color);
void render16s(s32 xp, s32 yp, u32 tile, u8 bits, u32 color);
void render32(s32 xp, s32 yp, u32 xTile, u32 yTile, u8 bits);

void renderTitle(int x, int y);
void renderFrame(int x1, int y1, int x2, int y2, u32 bgColor);
void renderTile(int i, int d, u8 level, int x, int y);
void renderConnectedTile4(int x, int y, u32 xTile, u32 yTile);
void renderConnectedTile8(int x, int y, u32 xTile, u32 yTile);
void renderBackground(s8 level, int xScroll, int yScroll);
void renderWeather(u8 level, int xScroll, int yScroll);
void renderDayNight(PlayerData *pd);
void renderButtonIcon(u32 icon, int x, int y, float scale);

void bakeLights();
void freeLightBakes();
void renderLightsToStencil(PlayerData *pd, bool force, bool invert, bool rplayer);
void resetStencilStuff();
void bakeLight(sf2d_texture* texture, int x, int y, int r);
void renderLight(int x, int y, sf2d_texture* texture);

void renderGui(PlayerData *pd);
void renderZoomedMap(PlayerData *pd);
void renderPlayer(PlayerData *pd);

void drawText(char * msg, u32 x, u32 y);
void drawSizedText(char * msg, u32 x, u32 y, float size);
void drawTextColor(char * msg, u32 x, u32 y, u32 color);
void drawTextColorSpecial(char * msg, u32 x, u32 y, u32 color, u32 color2);
void drawSizedTextColor(char * msg, int x, int y, float size, u32 color);

void renderFurniture(int itemID, int x, int y);
void renderEntity(Entity* e, int x, int y);
void renderEntities(u8 level, int x, int y, EntityManager* em);

void renderRecipes(RecipeManager * r, int xo, int yo, int x1, int y1, int selected);
void renderItemList(Inventory * inv, int xo, int yo, int x1, int y1, int selected);
void renderArmorList(Inventory * inv, int xo, int yo, int x1, int y1, int selected);
void renderItemWithText(Item* item, int x, int y);
void renderItemStuffWithText(int itemID, int itemCL, bool onlyOne, int x, int y);
void renderItemWithTextCentered(Item* item, int width, int y);
void renderItemIcon(int itemID, int countLevel, int x, int y);
void renderItemIcon2(int itemID, int countLevel, int x, int y, int z);
