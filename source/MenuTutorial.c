#include "MenuTutorial.h"

u8 pageNum = 0;
u8 maxPageNum = 7;

u32 biasedCirclePad(u32 in){
	if(in & KEY_CPAD_UP) return KEY_CPAD_UP;
	else if(in & KEY_CPAD_DOWN) return KEY_CPAD_DOWN;
	else if(in & KEY_CPAD_LEFT) return KEY_CPAD_LEFT;
	else if(in & KEY_CPAD_RIGHT) return KEY_CPAD_RIGHT;
	else return (in & -in);
}

u32 biasedMenuXY(u32 in){
	if(in & KEY_X) return KEY_X;
	else if(in & KEY_Y) return KEY_Y;
	else return (in & -in);
}

/** Oh my god, this was so damn tedious to make. */
void renderTutorialPage(bool topScreen){
	if(topScreen){
		drawTextColor("How to Play",(400-11*12)/2,12,0xFF00AFAF);
		switch(pageNum){
			case 0: // Moving the character
				drawTextColor("Movement",(400-8*12)/2,40,0xFF007FBF);
				drawText("Press   to move up",92,90);
				renderButtonIcon(biasedCirclePad(localInputs.k_up.input), 164, 88, 1);
				drawText("Press   to move down",80,120);
				renderButtonIcon(biasedCirclePad(localInputs.k_down.input), 152, 118, 1);
				drawText("Press   to move left",80,150);
				renderButtonIcon(biasedCirclePad(localInputs.k_left.input), 152, 148, 1);
				drawText("Press   to move right",74,180);
				renderButtonIcon(biasedCirclePad(localInputs.k_right.input), 146, 178, 1);
				break;
			case 1: // Attacking
				drawTextColor("Attacking",(400-9*12)/2,40,0xFF007FBF);
				drawText("Press   to Attack",98,80);
				renderButtonIcon(localInputs.k_attack.input & -localInputs.k_attack.input, 168, 78, 1);
				drawText("Attack with an item to use it",26,120);
				drawText("Use the axe to cut down trees",26,140);
				drawText("Use the sword to attack enemies",14,160);
				drawText("Use the shovel to dig ground",32,180);
				drawText("Use the pickaxe to mine rock/ore",8,200);
				break;
			case 2: // Inventory
				drawTextColor("Inventory",(400-9*12)/2,40,0xFF007FBF);
				drawText("Press   to open the menu",56,80);
				renderButtonIcon(biasedMenuXY(localInputs.k_menu.input), 126, 78, 1);
				drawText("Press   to scroll up",80,110);
				renderButtonIcon(biasedCirclePad(localInputs.k_up.input), 152, 108, 1);
				drawText("Press   to scroll down",68,140);
				renderButtonIcon(biasedCirclePad(localInputs.k_down.input), 140, 138, 1);
				drawText("Press   to select an item",50,170);
				renderButtonIcon(localInputs.k_accept.input & -localInputs.k_accept.input, 120, 168, 1);
				drawText("Press   to close the menu",50,200);
				renderButtonIcon(localInputs.k_decline.input & -localInputs.k_decline.input, 120, 198, 1);
				break;
			case 3: // Furniture
				drawTextColor("Furniture",(400-9*12)/2,40,0xFF007FBF);
				drawText("Use furniture for item crafting",(400-31*12)/2,74);
				drawText("Press   to open the menu",56,100);
				renderButtonIcon(biasedMenuXY(localInputs.k_menu.input), 126, 98, 1);
				drawText("while infront of the furniture",(400-30*12)/2,116);
				drawText("Use the lantern item to light",(400-29*12)/2,144);
				drawText("up underground areas",(400-20*12)/2,160);
				drawText("Use the power glove item to",(400-27*12)/2,184);
				drawText("pick up furniture",(400-17*12)/2,200);
				break;
			case 4: // Crafting
				drawTextColor("Crafting",(400-8*12)/2,40,0xFF007FBF);
				drawText("Create new items and tools",(400-26*12)/2,74);
				drawText("Go up to a furniture item and",(400-29*12)/2,104);
				drawText("Press   to open the menu",56,120);
				renderButtonIcon(biasedMenuXY(localInputs.k_menu.input), 126, 118, 1);
				drawText("Gather up the required materials",(400-32*12)/2,150);
				drawText("and then press   to craft it",(400-28*12)/2,166);
				renderButtonIcon(localInputs.k_accept.input & -localInputs.k_accept.input, 210, 164, 1);
				break;
			case 5: // Farming
				drawTextColor("Farming",(400-7*12)/2,40,0xFF007FBF);
				drawText("Grow wheat to make bread",(400-24*12)/2,74);
				drawText("Dig up grass to gather seeds",(400-28*12)/2,94);
				drawText("Use the hoe to till ground",(400-26*12)/2,114);
				drawText("Harvest wheat when it is yellow",(400-31*12)/2,134);
				drawText("Use the oven to bake bread",(400-26*12)/2,154);
				drawText("It takes 4 wheat to craft bread",(400-31*12)/2,174);
				break;
			case 6: // Mining
				drawTextColor("Mining",(400-6*12)/2,40,0xFF007FBF);
				drawText("Use a pickaxe tool for mining",(400-29*12)/2,74);
				drawText("Mine rocks for stone",(400-20*12)/2,94);
				drawText("Mine iron ore for iron",(400-22*12)/2,114);
				drawText("Mine gold ore for gold",(400-22*12)/2,134);
				drawText("Mine gem ore to get gems",(400-24*12)/2,154);
				drawText("It takes 4 ore and 1 coal to",(400-28*12)/2,190);
				drawText("make an ingot inside a furnace",(400-30*12)/2,210);
				break;
			case 7: // Potion Brewing
				drawTextColor("Brewing",(400-6*12)/2,40,0xFF007FBF);
				drawText("Create potions.",(400-13*12)/2,74);
				drawText("The potions give you abilities",(400-29*12)/2,94);
				drawText("Like speed and strength",(400-22*12)/2,114);
				drawText("They are hard to obtain",(400-22*12)/2,134);
				break;
		}
	} else {
		switch(pageNum){
			case 0: // Moving the character
				render16(30,56,16,112,0);//Player up
				renderButtonIcon(biasedCirclePad(localInputs.k_up.input), 30,40, 2);
				render16(60,56,0,112,0);//Player down
				renderButtonIcon(biasedCirclePad(localInputs.k_down.input), 60,40, 2);
				render16(90,56,48,112,1);//Player left
				renderButtonIcon(biasedCirclePad(localInputs.k_left.input), 90,40, 2);
				render16(120,56,48,112,0);//Player right
				renderButtonIcon(biasedCirclePad(localInputs.k_right.input), 120,40, 2);
				break;
			case 1: // Attacking
				render16(60,56,0,112,0);//Player-down
				renderButtonIcon(localInputs.k_attack.input & -localInputs.k_attack.input, 80, 56, 2);
				renderc(60,68,16,160,16,8,2);//Slash

				menuRenderTilePit(12,20,256,0);// grass pit
				render16(12+8,20+4,256,48,0);//Tree
				renderc(12+9,20+14,16,160,16,8,0);//Slash
				render(12+9+4,20+14,192,144,0);//Axe
				render16(12+9,20+18,16,112,0);//Player-up

				menuRenderTilePit(122,62,320,0);// sand pit
				render16(130,70,256,16,0);// hole
				render16(116,70,48,112,0);//Player-right
				renderb(136,76,16,152,0,sandColor);// Sand item
				renderc(128,70,40,160,8,16,0);//Slash
				render(130,74,0,144,0);//Shovel
				break;
			case 2: // Inventory
				renderFrame(4,4,17,11,0xFFFF1010);
				renderItemStuffWithText(ITEM_APPLE,5,false,80,78);
				renderItemStuffWithText(ITEM_SLIME,11,false,80,94);
				renderItemStuffWithText(TOOL_SWORD,4,true,80,110);
				renderItemStuffWithText(ITEM_IRONORE,3,false,80,126);
				renderItemStuffWithText(ITEM_IRONINGOT,11,false,80,142);
				sf2d_draw_rectangle(64, 110, 12, 12, 0xFF);
				drawText(">", 64, 110);
				renderButtonIcon(biasedCirclePad(localInputs.k_up.input), 44, 92, 1);
				renderButtonIcon(localInputs.k_accept.input & -localInputs.k_accept.input, 44, 108, 1);
				renderButtonIcon(biasedCirclePad(localInputs.k_down.input), 44, 125, 1);
				break;
			case 3: // Furniture
				sf2d_draw_rectangle(64, 48, 192, 32, grassColor);
				renderc(32,24,64,128,96,16,0);//Furniture entities

				renderFurniture(ITEM_WORKBENCH, 50,60);
				render16(50,46,0,112,0);//Player-down
				renderc(50,58,16,160,16,8,2);//Slash
				render(54,58,56,152,0);//Power glove

				render16(92,56,0,128,0);//Player(Carrying)
				render16(92,44,128,128,0);//Workbench
				break;
			case 4: // Crafting
				renderFrame(11,3,19,6,0xFFFF1010);
				renderFrame(11,7,19,12,0xFFFF1010);
				renderFrame(1,3,10,12,0xFFFF1010);
				renderItemStuffWithText(TOOL_AXE,0,true,28,64);
				renderItemIcon(TOOL_AXE, 0, 94, 32);
				drawText("0", 206, 66);
				renderItemIcon(ITEM_WOOD, 0, 94, 64);
				drawText("16/5", 206, 130);
				break;
			case 5: // Farming (Bottom screen)
				renderc(24,16,352,48,112,16,0); // Wheat Stages

				render16(20,40,352,48,0); // Farm Tile
				render16(36,40,448,48,0); // Wheat Tile
				render16(52,40,448,48,0); // Wheat Tile
				render16(20,54,16,112,0); // Player (Up)
				renderc(20,50,16,160,16,8,0); // Slash (Up)
				render(19,45,40,152,0); // Seeds
				render(26,39,48,152,0); // Wheat1
				render(29,44,48,152,0); // Wheat2

				renderc(72,40,352,48,32,16,0); // Farm Tile + Seeded Wheat Tile
				render16(72,54,16,112,0); // Player (Up)
				renderc(72,50,16,160,16,8,0); // Slash (Up)
				render(76,48,40,152,0); // Seeds

				sf2d_draw_rectangle(216, 80, 32, 32, dirtColor[1]); // Dirt color for grass
				render16(108, 40, 256, 0, 0); // Grass
				render16(124, 40,352,48,0); // Farm Tile
				render16(108,54,16,112,0); // Player (Up)
				renderc(108,50,16,160,16,8,0); // Slash (Up)
				render(112,48,72,144,0); // Gem Hoe

				sf2d_draw_rectangle(112, 156, 32, 32, dirtColor[1]); // Dirt color for grass
				render16(56, 78, 256, 0, 0); // Grass
				sf2d_draw_rectangle(80, 156, 32, 32, dirtColor[1]); // Dirt color
				render16(40, 78, 336, 80, 0); // Dirt Dots
				render(44, 82, 40,152,0); // Seeds

				render16(24,78,48,112,0); // Player (Right)
				renderc(36,78,40,160,8,16,0); // Slash (Right)
				render(38,82,32,144,0); // Gem Shovel

				render(82,78,48,152,0); // Wheat
				render(90,78,48,152,0); // Wheat
				render(82,86,48,152,0); // Wheat
				render(90,86,48,152,0); // Wheat
				drawText(">",203,164);
				render16(108,76,96,128,0); // Oven
				drawText(">",246,164);
				render(132,82,72,152,0); // Bread
				break;
			case 6: //Mining
				render16(23,32,464,48,0); // iron ore
				render16(23,52,480,48,0); // gold ore
				render16(23,72,496,48,0); // gem ore
				renderb(41,38,88,152,0,ironColor); // Iron ore item
				renderb(41,58,88,152,0,goldColor); // Gold ore item
				render(41,78,112,152,0); // Gem item
				drawText(">",104,74);
				drawText(">",104,114);
				drawText(">",104,154);
				render16(60,32,112,128,0); // Furnace
				render16(60,52,112,128,0); // Furnace
				render16(60,72,240,128,0); // Enchanter
				drawText(">",160,74);
				drawText(">",160,114);
				drawText(">",160,154);
				renderb(88,36,96,152,0,ironColor); // Iron ingot item
				renderb(88,56,96,152,0,goldColor); // Gold ingot item
				renderb(88,76,152,144,0,goldColor); // Gem Pickaxe
				drawText(">",200,74);
				drawText(">",200,114);
				render16(106,32,64,128,0); // Anvil
				render16(106,52,64,128,0); // Anvil
				drawText(">",244,74);
				drawText(">",244,114);
				render(130,36,136,144,0); // Iron Pickaxe
				render(130,56,144,144,0); // Gold Pickaxe
				break;
			case 7: // Brewing
				render16(65, 56, 240, 96, 0);
				break;
		}

		drawText(pageText,(320-(strlen(pageText))*12)/2,12);
		if(pageNum > 0){
			drawText("<",2,16);
			renderButtonIcon(localInputs.k_menuPrev.input & -localInputs.k_menuPrev.input, 8, 2, 2);
		}
		if(pageNum < maxPageNum){
			drawText(">",306,16);
			renderButtonIcon(localInputs.k_menuNext.input & -localInputs.k_menuNext.input, 136, 2, 2);
		}
		drawText("Press   to exit",(320-(15*12))/2,218);
		renderButtonIcon(localInputs.k_decline.input & -localInputs.k_decline.input, 140, 216, 1);
	}
}
