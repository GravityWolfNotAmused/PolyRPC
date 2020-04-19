/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/
modded class DayZGame
{
	/*
	* Hashmap of RPCs
	*/
	private ref map<int, ref IRPCExecutable> rpcs;

	void DayZGame()
	{
		rpcs = new map<int, ref IRPCExecutable>;

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
		ref IRPCExecutable rpc = type.Spawn();

		if(rpc != null)
		{
			rpcs.Insert(id, rpc);
		}
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if(target == null)
		{
			autoptr IRPCExecutable rpc = rpcs.Get(rpc_type);

			if(rpc != null)
			{
				rpc.ExecuteRPC(sender, null, ctx, this);
				return;
			}
		}

		super.OnRPC(sender, target, rpc_type, ctx);
	}
}
