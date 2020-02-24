modded class PluginBase
{
	protected ref map<int, ref RPCBase> rpcs;

	void PluginBase()
	{
		rpcs = new map<int, ref RPCBase>;
		
		InitRPCs();
	}

	void ~PluginBase()
	{
		delete rpcs;
	}

	void InitRPCs()
	{
	}

	void AddRPC(typename type, int id)
	{
		ref RPCBase rpc = type.Spawn();

		if(rpc != null)
		{
			rpc.SetRPCType(id);
			rpcs.Insert(id, rpc);
		}
	}

	void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		autoptr RPCBase rpc = rpcs.Get(rpc_type);

		if(rpc != null)
		{	
			rpc.ExecuteRPC(sender, null, ctx);
			return;
		}
	}
}