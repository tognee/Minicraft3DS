#include "Entity.h"

#include "Synchronizer.h"

Entity newItemEntity(Item item, int x, int y, int level){
	Entity e;
	e.type = ENTITY_ITEM;
	e.level = level;
	e.entityItem.age = 0;
	e.entityItem.item = item;
	e.x = x;
	e.y = y;
	e.xr = 3;
	e.yr = 3;
	e.canPass = false;

	e.entityItem.xx = x;
	e.entityItem.yy = y;
	e.entityItem.zz = 2;
	e.entityItem.xa = gaussrand(false) * 0.1;
	e.entityItem.ya = gaussrand(false) * 0.1;
	e.entityItem.za = ((float)rand() / RAND_MAX) * 0.45 + 1;

	return e;
}

void assignInventory(Entity* e){
	if(eManager.nextInv > 300) return;
	e->entityFurniture.inv = &eManager.invs[eManager.nextInv];
	eManager.nextInv++;
}

Entity newFurnitureEntity(int itemID,Inventory * invPtr, int x, int y, int level){
	Entity e;
	e.type = ENTITY_FURNITURE;
	e.level = level;
	e.x = x;
	e.y = y;
	e.xr = 3;
	e.yr = 3;
	e.entityFurniture.itemID = itemID;
	e.canPass = false;
	if(itemID == ITEM_LANTERN) e.entityFurniture.r = 8;
	else if(itemID == ITEM_CHEST){
		if(invPtr == NULL)assignInventory(&e);
		else e.entityFurniture.inv = invPtr;
	}
	return e;
}

Entity newPassiveEntity(int type, int x, int y, int level){
	Entity e;
	e.type = ENTITY_PASSIVE;
	e.level = level;
	e.x = x;
	e.y = y;
	e.hurtTime = 0;
	e.xKnockback = 0;
	e.yKnockback = 0;
	e.passive.mtype = type;
	e.passive.health = 20;
	e.passive.dir = 0;
	e.passive.xa = 0;
	e.passive.ya = 0;
	e.xr = 4;
	e.yr = 3;
	e.canPass = false;
	return e;
}

Entity newZombieEntity(int lvl, int x, int y, int level){
	Entity e;
	e.type = ENTITY_ZOMBIE;
	e.level = level;
	e.x = x;
	e.y = y;
	e.hurtTime = 0;
	e.xKnockback = 0;
	e.yKnockback = 0;
	e.hostile.lvl = lvl;
	e.hostile.xa = 0;
	e.hostile.ya = 0;
	e.hostile.health = lvl * lvl * 10;
	e.hostile.dir = 0;
	e.xr = 4;
	e.yr = 3;
	e.canPass = false;
	switch(lvl){
		case 2: e.hostile.color = 0xFF8282CC; break;
		case 3: e.hostile.color = 0xFFEFEFEF; break;
		case 4: e.hostile.color = 0xFFAA6262; break;
		default: e.hostile.color = 0xFF95DB95; break;
	}
	return e;
}

Entity newSkeletonEntity(int lvl, int x, int y, int level){
	Entity e;
	e.type = ENTITY_SKELETON;
	e.level = level;
	e.x = x;
	e.y = y;
	e.hurtTime = 0;
	e.xKnockback = 0;
	e.yKnockback = 0;
	e.hostile.lvl = lvl;
	e.hostile.xa = 0;
	e.hostile.ya = 0;
	e.hostile.health = lvl * lvl * 10;
	e.hostile.dir = 0;
	e.hostile.randAttackTime = 0;
	e.xr = 4;
	e.yr = 3;
	e.canPass = false;
	switch(lvl){
		case 2: e.hostile.color = 0xFFC4C4C4; break;
		case 3: e.hostile.color = 0xFFA0A0A0; break;
		case 4: e.hostile.color = 0xFF7A7A7A; break;
		default: e.hostile.color = 0xFFFFFFFF; break;
	}
	return e;
}

Entity newKnightEntity(int lvl, int x, int y, int level){
	Entity e;
	e.type = ENTITY_KNIGHT;
	e.level = level;
	e.x = x;
	e.y = y;
	e.hurtTime = 0;
	e.xKnockback = 0;
	e.yKnockback = 0;
	e.hostile.lvl = lvl;
	e.hostile.xa = 0;
	e.hostile.ya = 0;
	e.hostile.health = lvl * lvl * 20;
	e.hostile.dir = 0;
	e.xr = 4;
	e.yr = 3;
	e.canPass = false;
	switch(lvl){
		case 2: e.hostile.color = 0xFF0000C6; break;
		case 3: e.hostile.color = 0xFF00A3C6; break;
		case 4: e.hostile.color = 0xFF707070; break;
		default: e.hostile.color = 0xFFFFFFFF; break;
	}
	return e;
}

Entity newSlimeEntity(int lvl, int x, int y, int level){
	Entity e;
	e.type = ENTITY_SLIME;
	e.level = level;
	e.x = x;
	e.y = y;
	e.hurtTime = 0;
	e.xKnockback = 0;
	e.yKnockback = 0;
	e.slime.lvl = lvl;
	e.slime.xa = 0;
	e.slime.ya = 0;
	e.slime.dir = 0;
	e.slime.health = lvl * lvl * 5;
	e.xr = 4;
	e.yr = 3;
	e.canPass = false;
	switch(lvl){
		case 2: e.slime.color = 0xFF8282CC; break;
		case 3: e.slime.color = 0xFFEFEFEF; break;
		case 4: e.slime.color = 0xFFAA6262; break;
		default: e.slime.color = 0xFF95DB95; break;
	}
	return e;
}

Entity newAirWizardEntity(int x, int y, int level){
	Entity e;
	e.type = ENTITY_AIRWIZARD;
	e.level = level;
	e.x = x;
	e.y = y;
	e.hurtTime = 0;
	e.xKnockback = 0;
	e.yKnockback = 0;
	e.wizard.dir = 0;
	e.wizard.health = 2000;
	e.wizard.attackDelay = 0;
	e.wizard.attackTime = 0;
	e.wizard.attackType = 0;
	e.wizard.xa = 0;
	e.wizard.ya = 0;
	e.xr = 4;
	e.yr = 3;
	e.canPass = true;
	return e;
}

Entity newSparkEntity(Entity* parent, float xa, float ya){
	Entity e;
	e.type = ENTITY_SPARK;
	e.level = parent->level;
	e.spark.age = 0;
	e.spark.parent = parent;
	e.spark.xa = xa;
	e.spark.ya = ya;
	e.spark.xx = parent->x;
	e.spark.yy = parent->y;
	e.xr = 3;
	e.yr = 3;
	e.canPass = true;
	return e;
}

Entity newDragonEntity(int x, int y, int level) {
	Entity e;
	e.type = ENTITY_DRAGON;
	e.level = level;
	e.x = x;
	e.y = y;
	e.hurtTime = 0;
	e.xKnockback = 0;
	e.yKnockback = 0;
	e.dragon.dir = 0;
	e.dragon.health = 2000;
	e.dragon.attackDelay = 0;
	e.dragon.attackTime = 0;
	e.dragon.attackType = 0;
	e.dragon.animTimer = 0;
	e.dragon.xa = 0;
	e.dragon.ya = 0;
	e.xr = 8;
	e.yr = 8;
	e.canPass = false;
	return e;
}

Entity newDragonFireEntity(Entity* parent, u8 type, int x, int y, float xa, float ya) {
	Entity e;
	e.type = ENTITY_DRAGONPROJECTILE;
	e.level = parent->level;
	e.dragonFire.age = 0;
	e.dragonFire.type = type;
	e.dragonFire.parent = parent;
	e.dragonFire.xa = xa;
	e.dragonFire.ya = ya;
	e.dragonFire.xx = x;
	e.dragonFire.yy = y;
	e.x = (int) x;
	e.y = (int) y;
	e.xr = 3;
	e.yr = 3;
	e.canPass = true;
	return e;
}

Entity newMagicPillarEntity(int x, int y, int level){
	Entity e;
	e.type = ENTITY_MAGIC_PILLAR;
	e.level = level;
	e.x = x;
	e.y = y;
	e.xr = 3;
	e.yr = 3;
	e.canPass = false;
	return e;
}

Entity newTextParticleEntity(char * str, u32 color, int x, int y, int level){
	Entity e;
	e.type = ENTITY_TEXTPARTICLE;
	e.level = level;
	e.textParticle.color = color;
	e.textParticle.age = 0;
	e.textParticle.text = (char*)calloc(strlen(str),sizeof(char));
	strncpy(e.textParticle.text,str,strlen(str));
	e.x = x;
	e.y = y;
	e.canPass = true;
	e.textParticle.xx = x;
	e.textParticle.yy = y;
	e.textParticle.zz = 2;
	e.textParticle.xa = gaussrand(false) * 0.3;
	e.textParticle.ya = gaussrand(false) * 0.2;
	e.textParticle.za = ((float)rand() / RAND_MAX) * 0.7 + 2;

	return e;
}
Entity newSmashParticleEntity(int x, int y, int level){
	Entity e;
	e.type = ENTITY_SMASHPARTICLE;
	e.level = level;
	e.smashParticle.age = 0;
	e.x = x;
	e.y = y;
	e.canPass = true;
	playSoundPositioned(snd_monsterHurt, e.level, e.x, e.y); //TODO: This is a wierd location for the effect
	return e;
}

Entity newArrowEntity(Entity* parent, int itemID, s8 xa, s8 ya, int level){
	Entity e;
	e.type = ENTITY_ARROW;
	e.level = level;
	e.arrow.age = 0;
	e.arrow.parent = parent;
	e.arrow.itemID = itemID;
	e.arrow.xa = xa;
	e.arrow.ya = ya;
	e.x = parent->x;
	e.y = parent->y;
	e.xr = 2;
	e.yr = 2;
	e.canPass = false;
	e.canSwim = true;
	return e;
}

Entity newGlowwormEntity(int x, int y, int level){
	Entity e;
	e.type = ENTITY_GLOWWORM;
	e.level = level;
	e.glowworm.xa = 0;
	e.glowworm.ya = 0;
	e.glowworm.randWalkTime = 0;
	e.glowworm.waitTime = 0;
	e.x = x;
	e.y = y;
	e.canPass = true;
	return e;
}

Entity newNPCEntity(int type, int x, int y, int level){
	Entity e;
	e.type = ENTITY_NPC;
	e.level = level;
	e.x = x;
	e.y = y;
	e.hurtTime = 0;
	e.xKnockback = 0;
	e.yKnockback = 0;
	e.npc.type = type;
	e.xr = 4;
	e.yr = 3;
	e.canPass = false;
	return e;
}

void addEntityToList(Entity e, EntityManager* em){
	e.slotNum = em->lastSlot[e.level];
	em->entities[e.level][em->lastSlot[e.level]] = e;
	++em->lastSlot[e.level];
}

void removeEntityFromList(Entity * e,int level,EntityManager* em){
	int i;
	if(em->entities[level][e->slotNum].type == ENTITY_TEXTPARTICLE) free(em->entities[level][e->slotNum].textParticle.text);
	for(i = e->slotNum; i < em->lastSlot[level];++i){
		em->entities[level][i] = em->entities[level][i + 1]; // Move the items down.
		em->entities[level][i].slotNum = i;
	}
	em->lastSlot[level]--;
	em->entities[level][em->lastSlot[level]] = nullEntity; // Make the last slot null.
}
