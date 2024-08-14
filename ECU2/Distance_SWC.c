FUNC(void, ReadDistance_CODE) ReadDistance_5ms(VAR(void, AUTOMATIC) ) 
{
    /*
        Call RTE Port API to get raw distance data and modify it 
    */

    // CP_ID_0 : Checkpoint ID of the Alive Supervision CheckPoint corresponding to this SE
    // SE1_ID : Identifier of this Supervised Entity
	Rte_Call_WdgMCheckpointReached(SE1_ID, CP_ID_0); 
}