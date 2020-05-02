/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/

modded class PluginBase
{
	[NonSerialized()]
	protected ref map<int, ref IRPCExecutable> rpcs;

	void PluginBase()
	{
		rpcs = new map<int, ref IRPCExecutable>;
		
		InitRPCs();
		GetDayZGame().Event_OnRPC.Insert( OnRPC );
	}

	void ~PluginBase()
	{
		delete rpcs;
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
		ref IRPCExecutable rpc = type.Spawn();

		if(rpc != null)
			rpcs.Insert(id, rpc);
	}

	/**
	 * Checks to see if RPC is stored inside of class and executes it.
	 *
	 * @param sender Player Identity of the player who sent it.
	 * @param rpc_type Integer type which the rpc is identitfied.
	 * @param ctx   Class which caches data which is stored before being sent over network.
	 * @since             0.1
	 */
	void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if(rpc_type > 97)
		{
			if(target == null)
			{
				autoptr IRPCExecutable rpc = rpcs.Get(rpc_type);
			
				if(rpc != null)
				{
					if(rpc.IsValid(sender))
						rpc.ExecuteRPC(sender, null, ctx, this);
				}
			}
		}
	}
}
