#pragma once
#include "Block.h"
#include "../cWorld.h"
#include "../cLadder.h"

class cBlockLadderHandler : public cBlockHandler
{
public:
	cBlockLadderHandler(BLOCKTYPE a_BlockID)
		: cBlockHandler(a_BlockID)
	{

	}	

	virtual void PlaceBlock(cWorld *a_World, cPlayer *a_Player, char a_BlockMeta, int a_X, int a_Y, int a_Z, char a_Dir)
	{
		a_World->SetBlock(a_X, a_Y, a_Z, m_BlockID, cLadder::DirectionToMetaData(a_Dir));
		OnPlacedByPlayer(a_World, a_Player, a_X, a_Y, a_Z, a_Dir);
	}

	virtual bool CanBeAt(cWorld *a_World, int a_X, int a_Y, int a_Z)
	{
		char Dir = cLadder::MetaDataToDirection(a_World->GetBlockMeta( a_X, a_Y, a_Z));
		AddDirection( a_X, a_Y, a_Z, Dir, true );
		return a_World->GetBlock( a_X, a_Y, a_Z ) != E_BLOCK_AIR;
	}
	
};