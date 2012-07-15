#pragma once
#include "../Defines.h"

class cWorld;
class cPlayer;



class cBlockHandler
{
public:
	cBlockHandler(BLOCKTYPE a_BlockID);
	//Called when the block gets ticked
	virtual void OnUpdate(cWorld *a_World, int a_X, int a_Y, int a_Z);
	virtual void OnPlacedByPlayer(cWorld *a_World, cPlayer * a_Player, int a_X, int a_Y, int a_Z, int a_Dir);
	virtual void OnDestroyedByPlayer(cWorld *a_World, cPlayer * a_Player, int a_X, int a_Y, int a_Z);
	virtual void OnPlaced(cWorld *a_World, int a_X, int a_Y, int a_Z, int a_Dir);
	virtual void OnDestroyed(cWorld *a_World, int a_X, int a_Y, int a_Z);
	virtual void OnNeighborChanged(cWorld *a_World, int a_X, int a_Y, int a_Z);
	static void NeighborChanged(cWorld *a_World, int a_X, int a_Y, int a_Z);
	virtual void OnClick(cWorld *a_World, cPlayer *a_Player, int a_X, int a_Y, int a_Z);
	virtual void PlaceBlock(cWorld *a_World, cPlayer *a_Player, char a_BlockMeta, int a_X, int a_Y, int a_Z, char a_Dir);

	virtual int GetTickRate();
	virtual char GetDropCount();
	virtual int GetDropID();
	virtual char GetDropMeta(char a_BlockMeta);
	virtual bool NeedsRandomTicks();
	//Item is -2 if it wasn�t a player
	virtual void DropBlock(cWorld *a_World, int a_X, int a_Y, int a_Z);
	virtual bool CanBeAt(cWorld *a_World, int a_X, int a_Y, int a_Z);
	//This gets called if the player tries to place a block ontop of this block (Only if he aims directly on this block)
	virtual bool AllowBlockOnTop();
	virtual bool IsUseable();
	virtual bool IsClickedThrough();
	virtual bool IgnoreBuildCollision();
	//Indicates this block can be placed on the side of other blocks. Default: true
	virtual bool CanBePlacedOnSide();
	//Does this block drops if it gets destroyed by an unsuitable situation? Default: true
	virtual bool DropOnUnsuitable();
	
	static cBlockHandler *GetBlockHandler(char a_BlockID);

	static void Deinit();
	
protected:
	char m_BlockID;
	static cBlockHandler *CreateBlockHandler(BLOCKTYPE a_BlockID);
	static cBlockHandler *m_BlockHandler[256];
	static bool m_HandlerInitialized;	//used to detect if the blockhandlers are initialized
};


inline cBlockHandler *BlockHandler(char a_BlockID) { return cBlockHandler::GetBlockHandler(a_BlockID); }