#pragma once
#include "Crafting.h"
#include <stdlib.h>

// Entity types
#define ENTITY_NULL 0
#define ENTITY_ITEM 1
#define ENTITY_FURNITURE 2
#define ENTITY_ZOMBIE 3
#define ENTITY_SLIME 4
#define ENTITY_AIRWIZARD 5
#define ENTITY_SPARK 6
#define ENTITY_TEXTPARTICLE 7
#define ENTITY_SMASHPARTICLE 8
#define ENTITY_PLAYER 9
#define ENTITY_PASSIVE 10
#define ENTITY_ARROW 11
#define ENTITY_SKELETON 12
#define ENTITY_KNIGHT 13
#define ENTITY_GLOWWORM 14

#define ENTITY_DRAGON 15
#define ENTITY_DRAGONPROJECTILE 16
#define ENTITY_MAGIC_PILLAR 17

#define ENTITY_NPC 18

typedef struct Entity Entity;

typedef struct _plrd PlayerData; //in order to not include Player.h and cause all sorts of problems

typedef struct {
	s8 ax;
	s8 ay;
	u8 dir;
	s8 health;
	s8 stamina;
	s8 staminaRecharge;
	s8 staminaRechargeDelay;
	s8 attackTimer;
	u8 spawnTrigger;
	bool isDead;
	bool hasWon;
	bool hasWonSaved;
	s8 endTimer;
	s16 walkDist;
	bool isCarrying;
	bool isSwimming;
	int swimTimer;
	int regenTimer;
	int strengthTimer;
	int swimBreathTimer;
	int speedTimer;
	int score;
	PlayerData *data;
} Player;


typedef struct {
	float xa;
	float ya;
	float za;
	float xx;
	float yy;
	float zz;
	s16 age;
	Item item;
} EntityItem;

typedef struct {
	s16 itemID;
	bool active;
	s8 r; // light radius for lantern.
	Inventory* inv; // Points to chest inventory.
} EntityFurniture;

typedef struct {
	u8 mtype;
	s8 xa;
	s8 ya;
	s16 health;
	s8 dir;
	s8 randWalkTime;
	s8 walkDist;
} PassiveMob;

typedef struct {
	s8 xa;
	s8 ya;
	s16 health;
	s8 dir;
	s8 lvl;
	s8 randWalkTime;
	s8 walkDist;
	s8 randAttackTime;
	u32 color;
} HostileMob;

typedef struct {
	s8 xa;
	s8 ya;
	s16 health;
	s8 lvl;
	s8 dir;
	s8 jumpTime;
	u32 color;
} Slime;

typedef struct {
	s8 xa;
	s8 ya;
	s16 health;
	s8 randWalkTime;
	s8 walkDist;
	s8 dir;
	int attackDelay;
	int attackTime;
	int attackType;
	s8 spriteAdjust;
} AirWizard;

typedef struct {
	Entity* parent;
	s16 age;
	float xa;
	float ya;
	float xx;
	float yy;
} Spark;

typedef struct {
	Entity* parent;
	s16 age;
	s16 itemID;
	s8 xa;
	s8 ya;
} Arrow;

typedef struct {
	s8 xa;
	s8 ya;
	s16 health;
	s8 randWalkTime;
	s8 walkDist;
	s8 dir;
	int attackDelay;
	int attackTime;
	int attackType;
	int animTimer;
} Dragon;

typedef struct {
	Entity* parent;
	u8 type;
	s16 age;
	float xa;
	float ya;
	float xx;
	float yy;
} DragonFire;

typedef struct {
	s8 xa;
	s8 ya;
	s8 randWalkTime;
	s8 waitTime;
} Glowworm;

typedef struct {
	u8 type;
} NPC;

typedef struct {
	float xa;
	float ya;
	float za;
	float xx;
	float yy;
	float zz;
	s16 age;
	char* text;
	int color;
} TextParticleEntity;

typedef struct {
	s16 age;
} SmashParticleEntity;

struct Entity {
	s16 x;
	s16 y;
	s8 xKnockback,yKnockback;
	u8 xr,yr;
	u8 type;
	u8 level;
	s8 hurtTime;
	s16 slotNum; // Read-only. Do not mess with this.
	bool canPass;
	bool canSwim;
	union {
		Player p;
		EntityItem entityItem;
		EntityFurniture entityFurniture;
		PassiveMob passive;
		HostileMob hostile;
		Slime slime;
		AirWizard wizard;
		Spark spark;
		Arrow arrow;
		Glowworm glowworm;
		Dragon dragon;
		DragonFire dragonFire;
		NPC npc;
		TextParticleEntity textParticle;
		SmashParticleEntity smashParticle;
	};
};

typedef struct {
	Entity entities[6][1000];
	s16 lastSlot[6];
	Inventory invs[300];
	s16 nextInv;
} EntityManager;

EntityManager eManager;
Entity nullEntity;


Entity newItemEntity(Item item, int x, int y, int level);
Entity newFurnitureEntity(int itemID, Inventory * invPtr, int x, int y, int level);
Entity newPassiveEntity(int type, int x, int y, int level);
Entity newZombieEntity(int lvl, int x, int y, int level);
Entity newSkeletonEntity(int lvl, int x, int y, int level);
Entity newKnightEntity(int lvl, int x, int y, int level);
Entity newSlimeEntity(int lvl, int x, int y, int level);
Entity newAirWizardEntity(int x, int y, int level);
Entity newSparkEntity(Entity* parent, float xa, float ya);
Entity newDragonEntity(int x, int y, int level);
Entity newDragonFireEntity(Entity* parent, u8 type, int x, int y, float xa, float ya);
Entity newMagicPillarEntity(int x, int y, int level);
Entity newTextParticleEntity(char * str, u32 color, int xa, int ya, int level);
Entity newSmashParticleEntity(int xa, int ya, int level);
Entity newArrowEntity(Entity* parent, int itemID, s8 xa, s8 ya, int level);
Entity newGlowwormEntity(int x, int y, int level);
Entity newNPCEntity(int type, int x, int y, int level);
void addEntityToList(Entity e, EntityManager* em);
void removeEntityFromList(Entity * e,int level,EntityManager* em);
