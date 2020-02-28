modded class CarScript
{
	protected ref map<int, ref RPCBase> rpcs;

	void CarScript()
	{
		rpcs = new map<int, ref RPCBase>;

		InitRPCs();
	}

	/*
	*	An Function to initalize RPCs. To Be Overriden by user.
	*/
	void InitRPCs()
	{
	}

	/*
	*	Function to add RPCs to Hashmap
	*	@param type Typename of the RPC class
	*	@since 0.1
	*/

	void AddRPC(typename type, int id)
	{
		ref RPCBase rpc = type.Spawn();

		if(rpc != null)
		{
			rpc.SetRPCType(id);
			rpcs.Insert(id, rpc);
		}
	}

	/**
	 * Checks to see if RPC is stored inside of class and executes it.
	 *
	 * @param sender Player Identity of the player who sent it.
	 * @param rpc_type Integer type which the rpc is identitfied.
	 * @param ctx   Class which caches data which is stored before being sent over network.
	 * @since             0.1
	 */
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{	
		autoptr RPCBase rpc = rpcs.Get(rpc_type);

		if(rpc != null)
		{
			rpc.ExecuteRPC(sender, this, ctx);
			return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
}