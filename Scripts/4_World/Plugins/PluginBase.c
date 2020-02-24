modded class PluginBase
{
	private ref map<int, ref RPCBase> rpcs;

	void PluginBase()
	{
		rpcs = new map<int, ref RPCBase>;
		rpcs.Insert(RPCTypeEnum.RPCServerTest, new TestServerRPC(RPCTypeEnum.RPCServerTest));
		
		InitRPCs();
	}

	void ~PluginBase()
	{
		delete rpcs;
	}

	void InitRPCs()
	{

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